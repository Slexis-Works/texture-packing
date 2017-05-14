#include "texture-packing.hpp"

int main (int argc, char *argv[]) {

	// Paramètres et valeurs par défaut
	coord minSize(16);
	coord maxSize(256);
	size_t nbRects(1000);
	coord texWidth(2048);
	coord texHeight(2048);
	std::string outputFolder;
	std::string outputRect;
	size_t nbTests(1);
	std::vector<std::string> algosChoisis;
	std::map<std::string, funcAlgo> algosDispos;
	algosDispos["FF"] = algoFF;
	algosDispos["FFDH"] = algoFFDH;
	algosDispos["NFDH"] = algoNFDH;
	algosDispos["BFDH"] = algoBFDH;
	//algosDispos.push_back("AD");
	//algosDispos.push_back("Harmonic");
	//algosDispos.push("");

	// http://www.cplusplus.com/reference/random/
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();


	// Traitement des arguments

	for (int an=1 ; an<argc ; ++an) {
		std::string arg(argv[an]);

		if (arg == "--help") {
			if (an == 1 && argc == 2) {
				showHelp(argv[0]);
				return 0;
			} else {
				std::cerr << "Erreur : --help doit apparaître seul." << std::endl;
				showUsage(argv[0]);
				return 1;
			}
		} else if (arg == "--seed") {
			++an;
			if (an == argc || (isBadInt(argv[an]) && argv[an][0] != '-')) {
				std::cerr << "Erreur : --seed doit être suivi de la graine voulue" << std::endl;
				showUsage(argv[0]);
				return 3;
			}
			seed = std::stol(argv[an]);
		} else if (arg == "--tmin") {
			++an;
			if (an == argc || isBadInt(argv[an])) {
				std::cerr << "Erreur : --tmin doit être suivi de la taille minimale voulue en pixels" << std::endl;
				showUsage(argv[0]);
				return 4;
			}
			minSize = std::stoi(argv[an]);
		} else if (arg == "--tmax") {
			++an;
			if (an == argc || isBadInt(argv[an])) {
				std::cerr << "Erreur : --tmax doit être suivi de la taille maximale voulue en pixels" << std::endl;
				showUsage(argv[0]);
				return 5;
			}
			maxSize = std::stoi(argv[an]);
		} else if (arg == "--nbrect") {
			++an;
			if (an == argc || isBadInt(argv[an])) {
				std::cerr << "Erreur : --nbrect doit être suivi du nombre de rectangles à générer" << std::endl;
				showUsage(argv[0]);
				return 6;
			}
			nbRects = std::stoi(argv[an]);
		} else if (arg == "--lt") {
			++an;
			if (an == argc || isBadInt(argv[an])) {
				std::cerr << "Erreur : --lt doit être suivi de la largeur de la texture voulue en pixels" << std::endl;
				showUsage(argv[0]);
				return 7;
			}
			texWidth = std::stoi(argv[an]);
		} else if (arg == "--ht") {
			++an;
			if (an == argc || isBadInt(argv[an])) {
				std::cerr << "Erreur : --ht doit être suivi de la hauteur de la texture voulue en pixels" << std::endl;
				showUsage(argv[0]);
				return 8;
			}
			texHeight = std::stoi(argv[an]);
		} else if (arg == "--sortie") {
			++an;
			if (an == argc || !*(argv[an])) {
				std::cerr << "Erreur : le nom du dossier des résultats ne peut être vide" << std::endl;
				showUsage(argv[0]);
				return 9;
			}
			outputFolder = argv[an];
		} else if (arg == "--tests") {
			++an;
			if (an == argc || isBadInt(argv[an])) {
				std::cerr << "Erreur : --tests doit être suivi du nombre de tests à effectuer" << std::endl;
				showUsage(argv[0]);
				return 10;
			}
			nbTests = std::stoi(argv[an]);
		} else if (arg == "--rectangles") {
			++an;
			if (an == argc || !*(argv[an])) {
				std::cerr << "Erreur : le nom du dossier des rectangles ne peut être vide" << std::endl;
				showUsage(argv[0]);
				return 11;
			}
			outputRect = argv[an];
		} else if (algosDispos.count(arg) == 1) {
			if (std::find(algosChoisis.begin(), algosChoisis.end(), arg) != algosChoisis.end()) {
				std::cerr << "Attention : algorithme " << arg << " déjà spécifié" << std::endl;
			} else {
				algosChoisis.push_back(arg);
			}
		} else {
			std::cerr << "Erreur : paramètre ou algorithme inconnu : " << arg << std::endl;
			showUsage(argv[0]);
			return 12;
		}

	}

	// Vérification des paramètres
	if (minSize == 0 || maxSize == 0 || texWidth == 0 || texHeight == 0) {
		std::cerr << "Erreur : aucune taille ne peut être égale à 0" << std::endl;
		return 20;
	}

	if (maxSize > texWidth || maxSize > texHeight) {
		std::cerr << "Erreur : la taille maximale des rectangles ne peut dépasser la taille de la texture" << std::endl;
		return 21;
	}

	if (minSize > maxSize) {
		coord tmp = minSize;
		minSize = maxSize;
		maxSize = tmp;
		std::cerr << "Attention : les tailles minimale et maximale des rectangles ont été interverties pour être cohérentes" << std::endl;
	}

	if (nbTests == 0) {
		std::cerr << "Erreur : il faut au moins un test pour ce programme" << std::endl;
		return 22;
	}

	if (nbRects == 0) {
		std::cerr << "Erreur : il faut générer au moins un rectangle" << std::endl;
		return 23;
	}

	if (algosChoisis.empty()) {
		for (std::map<std::string, funcAlgo>::iterator it=algosDispos.begin(), end=algosDispos.end() ; it != end ; ++it) {
			algosChoisis.push_back(it->first);
		}
	}

	// Démarrage du programme

	std::cout << "Configuration OK" << std::endl;
	std::cout << "Graine utilisée : " << seed << std::endl;
	//std::cout << nbTests << " tests par algorithme" << std::endl;
	if (outputFolder.empty()) {
		std::stringstream seedConv;
		seedConv << seed << "_";
		if (algosChoisis.size() == 1)
			seedConv << algosChoisis[0];
		seedConv >> outputFolder;
	}

	std::default_random_engine randGen(seed);
	std::uniform_int_distribution<coord> distriSize(minSize, maxSize);
	std::uniform_int_distribution<coord> distriColor(0, 0xFFFFFF);

	if (nbTests == 1) {
		if (algosChoisis.size() > 1) {
			std::cout << "Les algorithmes ne seront traités qu'une fois avec les mêmes données" << std::endl;
		} else {
			std::cout << "L'algorithme ne sera traité qu'une seule fois" << std::endl;
		}
		std::vector<Rectangle> rects;
		for (size_t i=0 ; i<nbRects ; ++i) {
			rects.push_back(Rectangle(
				distriSize(randGen),
				distriSize(randGen),
				distriColor(randGen)
			));
		}
		if (!outputRect.empty()) {
			std::cout << "Les rectangles générés n'ont pas été mis dans " << outputRect << std::endl;
		}
		if (algosChoisis.size() > 1) {
			std::cout << "Les résultats seront dans " << outputFolder << "*nom algo*" << std::endl;
		} else {
			std::cout << "Les résultats seront dans " << outputFolder << std::endl;
		}
		for (std::string alg : algosChoisis) {
			std::cout << "Traitement de l'algorithme " << alg << std::endl;
			std::vector<Bin> res;
			algosDispos[alg](rects, res, texWidth, texHeight);

			std::cout << "Terminé. " << res.size() << " boîtes utilisées" << std::endl;
			std::string currentOutputF = outputFolder;
			if (algosChoisis.size() > 1) {
				currentOutputF += alg;
			}
			if (mkdir(currentOutputF.c_str(), 0777)) {
				perror("mkdir");
			}

			for (size_t i = 0 ; i < res.size() ; ++i) {
				std::stringstream binPath;
				binPath << currentOutputF << "/" << (i+1) << ".ppm";
				PPMImage curBinImg(texWidth, texHeight);
				res[i].drawOn(curBinImg);
				curBinImg.saveImage(binPath.str());
			}
		}
	} else {
		if (!outputRect.empty()) {
			std::cerr << "Attention : les rectangles ne peuvent être enregistrés s'il y a plusieurs tests" << std::endl;
		}

		std::cout << "Démarrage de " << nbTests << " tests par classe et par nombre de blocs pour " << algosChoisis.size() << " algorithme(s)" << std::endl;
		size_t nbBlocsParTest[] = {20, 40, 60, 80, 100};

		std::uniform_int_distribution<unsigned char> probaType(0, 9);
		std::uniform_int_distribution<coord> typesDistriL[] = {
			std::uniform_int_distribution<coord>(100*2/3, 100),
			std::uniform_int_distribution<coord>(1, 100/2),
			std::uniform_int_distribution<coord>(100/2, 100),
			std::uniform_int_distribution<coord>(1, 100/2)
		};
		std::uniform_int_distribution<coord> typesDistriH[] = {
			std::uniform_int_distribution<coord>(1, 100/2),
			std::uniform_int_distribution<coord>(100*2/3, 100),
			std::uniform_int_distribution<coord>(100/2, 100),
			std::uniform_int_distribution<coord>(1, 100/2)
		};

		std::map<std::string, long> scoresAlgos;
		for (std::string alg : algosChoisis) {
			scoresAlgos[alg] = 0;
		}
		for (size_t nbBI = 0 ; nbBI < 5 ; ++nbBI) {
			for (size_t classe = 0 ; classe < 4 ; ++classe) {
				for (size_t t = 0 ; t < nbTests ; ++t) {
					std::vector<Rectangle> rects;
					long lowerBound = 0;
					for (size_t r = 0 ; r < nbBlocsParTest[nbBI] ; ++r) {
						unsigned char resProba, type;
						resProba = probaType(randGen);
						if (resProba < 7) {
							type = classe;
						} else {
							type = (classe + resProba - 6)%4;
						}
						int rL = typesDistriL[type](randGen);
						int rH = typesDistriH[type](randGen);
						rects.push_back(Rectangle(rL, rH, distriColor(randGen)));
						lowerBound += rL * rH;
					}
					lowerBound = ceil(((float)lowerBound)/10000.0);
					//std::cout << "LowerBound pour ces rectangles : " << lowerBound << std::endl;
					for (std::string alg : algosChoisis) {
						std::vector<Bin> res;
						algosDispos[alg](rects, res, 100, 100);
						scoresAlgos[alg] += res.size() - lowerBound;
						//std::cout << "Résultat " << t << " pour algo " << alg << " avec " << rects.size() << " blocs pour la classe " << classe << " : " << res.size() << " boîtes (" << (res.size() - lowerBound) << ")" << std::endl;
					}
				}
			}
		}
		for (std::string alg : algosChoisis) {
			std::cout << alg << " : " << scoresAlgos[alg] << " blocs de différence pour une moyenne de " << ((double)scoresAlgos[alg])/(double)(nbTests*20) << std::endl;
		}
	}

	return 0;
}

void showUsage(const std::string name) {
	std::cerr << "Utilisation : " << std::endl
			<< name << " --help" << std::endl
			<< "Affiche plus de détails" << std::endl
			<< name << " [--seed nombre] [--tmin tailleMin] [--tmax tailleMax] [--lt largeurTexture] [--ht hauteurTexture] [--sortie nomDossier] [--tests nombre] [algorithme(s)]" << std::endl;
}

void showHelp(const std::string name) {
	std::cerr << "Utilisation : " << std::endl
			<< name << " --help" << std::endl
			<< "Affiche cette aide" << std::endl
			<< name << " [--seed nombre] [--tmin tailleMin] [--tmax tailleMax] [--lt largeurTextre] [--ht hauteurTexture] [--sortie nomDossier] [--tests nombre] [--rectangles nomDossier] algorithme(s)" << std::endl
			<< "Options :" << std::endl
			<< "\t--seed : graine pour la génération aléatoire. Défaut : tirée de l'horloge interne" << std::endl
			<< "\t--tmin : dimensions minimales incluses en pixels des rectangles générés. Défaut : 16" << std::endl
			<< "\t--tmax : dimensions maximales incluses en pixels des rectangles générés. Défaut : 256" << std::endl
			<< "\t--nbrect : nombre de rectangles à générer à chaque test. Défaut : 1000" << std::endl
			<< "\t--lt : largeur en pixels de la texture sur laquelle on doit placer les rectangles. Défaut : 2048" << std::endl
			<< "\t--ht : hauteur en pixels de la texture sur laquelle on doit placer les rectangles. Défaut : 2048" << std::endl
			<< "\t--sortie : nom du dossier où envoyer les résultats. Si plusieurs algorithmes sont spécifiés, leurs noms y seront rajoutés. Défaut : seed_NomAlgo" << std::endl
			<< "\t--tests : nombre de tests à effectuer. Si 1, le résultat de l'algorithme sera mis dans le dossier. Sinon, ce sera le nombre de tests par classe et nombre de blocs dans la variante de la méthode proposée par Martello et Vigo dans 'Exact solution of the two-dimensional 8nite bin packing problem'" << std::endl
			<< "\t--rectangles : nom du dossier où mettre les rectangles initiaux. Ignoré si le nombre de tests n'est pas 1. Défaut : les rectangles ne sont pas produits" << std::endl
			<< "\tAucun, un ou plusieurs algorithmes peuvent être spécifiés. Ils travailleront avec les mêmes données à chaque test. Si aucun n'est précisé, tous ceux disponibles seront traités" << std::endl
			<< "Algorithmes disponibles :" << std::endl
			<< "\tFF : First Fit" << std::endl
			<< "\tFFDH : First Fit Decreasing Height (tri par hauteur)" << std::endl
			<< "\tNFDH : Next Fit Decreasing Height" << std::endl
			<< "\tBFDH : Best Fit Decreasing Height" << std::endl;
}

bool isBadInt(const std::string s){
  return s.find_first_not_of( "0123456789" ) != std::string::npos;
}

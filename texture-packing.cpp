#include "texture-packing.hpp"

int main (int argc, char *argv[]) {

	// Paramètres et valeurs par défaut

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
		} else {
			std::cerr << "Erreur : paramètre ou algorithme inconnu : " << arg << std::endl;
			showUsage(argv[0]);
			return 2;
		}

	}

	// Démarrage du programme

	std::default_random_engine randGen(seed);
	std::uniform_int_distribution<coord> distriSize(16, 256);

	for (int i=0 ; i < 5 ; ++i) {
		std::cout << distriSize(randGen) << std::endl;
	}

	return 0;
}

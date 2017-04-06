#include <iostream>
#include <string>
#include <random>
#include <chrono>

#include "PPMImage.hpp"
#include "Rectangle.hpp"
#include "Shelf.hpp"

int main (int argc, char *argv[]);
void showUsage(std::string name) {
	std::cerr << "Utilisation : " << std::endl
			<< name << " --help" << std::endl
			<< "Affiche plus de détails" << std::endl
			<< name << " [--seed nombre] [--tmin tailleMin] [--tmax tailleMax] [--sortie nomDossier] [--tests nombre] algorithme(s)" << std::endl;
}

void showHelp(std::string name) {
	std::cerr << "Utilisation : " << std::endl
			<< name << " --help" << std::endl
			<< "Affiche cette aide" << std::endl
			<< name << " [--seed nombre] [--tmin tailleMin] [--tmax tailleMax] [--sortie nomDossier] [--tests nombre] [--rectangles nomDossier] algorithme(s)" << std::endl
			<< "Options :" << std::endl
			<< "\t--seed : graine pour la génération aléatoire. Défaut : tirée de l'horloge interne" << std::endl
			<< "\t--tmin : dimensions minimales en pixels des rectangles générés. Défaut : 16" << std::endl
			<< "\t--tmax : dimensions maximales en pixels des rectangles générés. Défaut : 256" << std::endl
			<< "\t--sortie : nom du dossier où envoyer les résultats. Si plusieurs algorithmes sont spécifiés, leurs noms y seront rajoutés. Défaut : seed_NomAlgo" << std::endl
			<< "\t--tests : nombre de tests à effectuer. Si 1, le résultat de l'algorithme sera mis dans le dossier. Sinon, ce sera le meilleur et le pire cas" << std::endl
			<< "\t--rectangles : nom du dossier où mettre les rectangles initiaux. Ignoré si le nombre de tests n'est pas 1. Défaut : les rectangles ne sont pas produits" << std::endl
			<< "\tUn ou plusieurs algorithmes peuvent être spécifiés. Ils travailleront avec les mêmes données à chaque évaluation" << std::endl
			<< "Algorithmes disponibles :" << std::endl
			<< "\tAucun lel" << std::endl;
}

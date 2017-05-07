#include "algoBFDH.hpp"

void algoBFDH(const std::vector<Rectangle> &rects, std::vector<Bin> &bins, coord bw, coord by) {
	// Tri des données
	std::vector<Rectangle> sortedRects;
	for (const Rectangle &rect : rects) {
		sortedRects.push_back(rect);
	}
	std::sort(sortedRects.begin(), sortedRects.end(), goesBeforeByHeight);

	// Création de tous les étages
	std::vector<Shelf> shelves;

	// Insertion du premier rectangle afin d'initialiser un premier étage
	shelves.push_back(Shelf(bw, 0, sortedRects[0]));

	int i = 0;
	int currSize = 0;
	int minShelf = 0;
	int minShelfSize = std::numeric_limits<int>::max();

	// On cherche, pour chaque élément, l'étage qui laissera le moins d'espace horizontal lorsqu'on l'ajoutera
	for (const Rectangle &rect : sortedRects) {
		for (auto & shelf : shelves) {
			// On calcul l'espace horizontal restant de l'étage courant après insertion de l'élément
			currSize = shelf.getEmptySpace() - rect.getW();

			// Si l'espace horizontal est insuffisant, on avance dans le for
			if (currSize < 0) {
				i++;
				continue;
			}

			// Sinon, on regarde si l'espace de l'étage courant et inférieur à l'espace trouvé plus tôt dans la boucle
			if (minShelfSize > currSize) {
				minShelf = i;
				minShelfSize = currSize;
			}

			i++;
		}

		// Si pas de place, on insère un nouvel étage
		if (shelves.at(minShelf).getEmptySpace() < rect.getW()) {
			shelves.push_back(Shelf(bw, 0, rect));
		}
		// Sinon insertion de l'élément
		else {
			shelves.at(minShelf).putRect(rect);
		}

		// Réinitialisation de variable
		i = 0;
		minShelf = 0;
		minShelfSize = std::numeric_limits<int>::max();
	}

	// Insertion de tous les étages de manière naïve
	coord curY = by;
	for (auto & shelf : shelves) {
		if (curY + shelf.getHeight() > by) {
			bins.push_back(Bin(bw, by));
			curY = 0;
		}
		shelf.setY(curY);
		curY += shelf.getHeight();
		bins.back().importShelf(shelf);
	}
}

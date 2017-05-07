#include "algoNFDH.hpp"

void algoNFDH(const std::vector<Rectangle> &rects, std::vector<Bin> &bins, coord bw, coord by) {
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

	unsigned int i = 0; // Compteur des étages
	unsigned int j = 0; // Compteur des rectangles

	for (const Rectangle &rect : sortedRects) {
		bool inserted = true;
		if (j != 0) {
			inserted = shelves.at(i).putRect(rect);
		}
		if (!inserted) {
			shelves.push_back(Shelf(bw, 0, rect));
			i++;
		}
		j++;
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

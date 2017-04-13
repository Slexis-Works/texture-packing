#include "algoFFDH.hpp"

void algoFFDH(const std::vector<Rectangle> &rects, std::vector<Bin> &bins, coord bw, coord by) {
	// Tri des données
	std::vector<Rectangle> sortedRects;
	for (const Rectangle &rect : rects) {
		sortedRects.push_back(rect);
	}
	std::sort(sortedRects.begin(), sortedRects.end(), goesBeforeByHeight);

	// Création de tous les étages
	std::vector<Shelf> shelves;
	for (const Rectangle &rect : sortedRects) {
		bool inserted = false;
		for (auto & shelf : shelves) {
			if (shelf.putRect(rect)) {
				inserted = true;
				break;
			}
		}
		if (inserted) {
			continue;
		}
		shelves.push_back(Shelf(bw, 0, rect));
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

bool goesBeforeByHeight(const Rectangle rect1, const Rectangle rect2) {
	return rect1.getH() > rect2.getH();
}

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
	shelves.push_back(Shelf(bw, 0, sortedRects[0]));
	unsigned int i = 0;
	unsigned int curr = i;
	for (const Rectangle &rect : sortedRects) {
		for (auto & shelf : shelves) {
			if (shelf.getEmptySpace() <= shelves.at(curr).getEmptySpace()
					&& shelf.getEmptySpace() >= rect.getW()) {
				curr = i;
			}
			else if (i == shelves.size()-1){
				curr = i;
			}
			else {
				i++;
			}
		}

		if (shelves.at(curr).getEmptySpace() < rect.getW()) {
			shelves.push_back(Shelf(bw, 0, rect));
		}
		else {
			shelves.at(curr).putRect(rect);
		}

		i=0;
		curr=i;
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

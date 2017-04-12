#include "Bin.hpp"

Bin::Bin(coord width, coord height)
: width(width)
, height(height)
{

}

void Bin::addRect(const Rectangle &rect, coord x, coord y) {
	rects.push_back(Rectangle(rect, x, y));
}

void Bin::importShelf(const Shelf &shelf) {
	std::vector<Rectangle>::const_iterator it = shelf.getRects().begin(), end = shelf.getRects().end();
	while (it != end) {
		addRect(*it, it->getX(), it->getY());
		++it;
	}
}

void Bin::drawOn(PPMImage &img) const {
	std::vector<Rectangle*>::iterator it, end;
	for (std::vector<Rectangle>::const_iterator it=rects.begin(), end=rects.end() ; it != end ; ++it) {
		(*it).drawOn(img);
	}
}


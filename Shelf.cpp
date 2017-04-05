#include "Shelf.hpp"


Shelf::Shelf(coord width, coord y, Rectangle* first)
: height(first->getH())
, y(y)
, curWidth(first->getW())
, maxWidth(width)
{
	first->setCoords(0, y);
	rects.push_back(first);
}

bool Shelf::putRect(Rectangle *rect) {
	coord rw = rect->getW();
	if (rect->getH() > rects.back()->getH()
		|| rw > maxWidth - curWidth) {
		return false;
	}

	// Ajout effectif
	rect->setCoords(curWidth, y);
	curWidth += rw;
	rects.push_back(rect);
	return true;
}

int Shelf::putRotatableRect(Rectangle *rect) {
	if (putRect(rect)) {
		return 1;
	}
	rect->flip();
	if (putRect(rect)) {
		return 2;
	}
	rect->flip();
	return 0;
}

void Shelf::setY(coord ny) {
	y = ny;
	std::vector<Rectangle*>::iterator it, end;
	it = rects.begin();
	end = rects.end();
	while (it != end) {
		(*it)->setY(ny);
		++it;
	}
}

void Shelf::drawOn(PPMImage &img) {
	std::vector<Rectangle*>::iterator it, end;
	it = rects.begin();
	end = rects.end();
	while (it != end) {
		std::cout << *it << " : " << (*it)->getX() << " ; " << (*it)->getY() << " of size " << (*it)->getW() << " ; " << (*it)->getH() << std::endl;
		(*it)->drawOn(img);
		++it;
	}
}

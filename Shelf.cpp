#include "Shelf.hpp"

Shelf::Shelf(coord width, coord y, const Rectangle& first)
: height(first.getH())
, y(y)
, curWidth(first.getW())
, maxWidth(width)
{
	rects.push_back(Rectangle(first, 0, y));
}

bool Shelf::putRect(const Rectangle &rect) {
	coord rw = rect.getW();
	//if (rect.getH() > rects.back().getH()
	if (rect.getH() > height
		|| rw > maxWidth - curWidth) {
		return false;
	}

	// Ajout effectif
	rects.push_back(Rectangle(rect, curWidth, y));
	curWidth += rw;
	return true;
}

int Shelf::putRotatableRect(const Rectangle &rect) {
	Rectangle recTest(rect, 0, 0);
	if (putRect(recTest)) {
		return 1;
	}
	recTest.flip();
	if (putRect(recTest)) {
		return 2;
	}
	return 0;
}

void Shelf::setY(coord ny) {
	y = ny;
	std::vector<Rectangle>::iterator it, end;
	it = rects.begin();
	end = rects.end();
	while (it != end) {
		(*it).setY(ny);
		++it;
	}
}

void Shelf::drawOn(PPMImage &img) const {
	std::vector<Rectangle>::const_iterator it, end;
	it = rects.begin();
	end = rects.end();
	while (it != end) {
		(*it).drawOn(img);
		++it;
	}
}

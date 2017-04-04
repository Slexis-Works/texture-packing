#include "Rectangle.hpp"

Rectangle::Rectangle(coord x, coord y, coord w, coord h, RGBColor col)
: x(x)
, y(y)
, w(w)
, h(h)
, col(col)
{

}

Rectangle::Rectangle(coord w, coord h, RGBColor col) {
	Rectangle(0, 0, w, h, col);
}

void Rectangle::flip() {
	coord tmp = w;
	w = h;
	h = tmp;
}

void Rectangle::setSize(coord nw, coord nh) {
	w = nw ? nw : w;
	y = nh ? nh : y;
}

void Rectangle::drawOn(PPMImage &img) {
	img.fillRect(x, y, w, h, col);
}

bool Rectangle::collides(const Rectangle o) {
	return x + w >= o.x
		&& x < o.x + o.w
		&& y + h >= o.y
		&& y < o.y + o.h;
}

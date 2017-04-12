#ifndef ALGOSFFDH_HPP
#define ALGOSFFDH_HPP

#include <vector>
#include <algorithm>

#include "Rectangle.hpp"
#include "Shelf.hpp"
#include "Bin.hpp"

void algoSFFDH(const std::vector<Rectangle> rects, std::vector<Bin> &bins, coord bw, coord by);
bool goesBeforeByHeight(const Rectangle rect1, const Rectangle rect2) {
	return rect1.getH() > rect2.getH();
}

#endif // ALGOSFFDH_HPP

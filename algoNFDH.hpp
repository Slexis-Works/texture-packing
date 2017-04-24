#ifndef ALGONFDH_HPP
#define ALGONFDH_HPP

#include <vector>
#include <algorithm>

#include "Rectangle.hpp"
#include "Shelf.hpp"
#include "Bin.hpp"

void algoNFDH(const std::vector<Rectangle> &rects, std::vector<Bin> &bins, coord bw, coord by);
bool goesBeforeByHeight(const Rectangle rect1, const Rectangle rect2);

#endif // ALGONFDH_HPP

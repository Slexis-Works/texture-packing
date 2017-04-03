#include "PPMImage.hpp"

PPMImage::PPMImage(coord width, coord height, RGBColor bgc)
: width(width)
, height(height)
, length(width*height)
, map(NULL)
{
	map = new RGBColor[length];
	assert(map);
	for (size_t i=0 ; i<length ; ++i)
		map[i] = bgc;
}

PPMImage::~PPMImage() {
	delete map;
}

void PPMImage::drawPix(coord x, coord y, RGBColor col) {
	std::cerr << "Printing a pixel at " << x << " ; " << y << std::endl;
	if (x < 0 || x >= width
		|| y < 0 || y >= height)
		return;
	map[y*width + x] = col;
}

void PPMImage::fillRect(coord xs, coord ys, coord w, coord h, RGBColor col) {
	for (coord y=ys, ye=ys+h ; y<ye ; ++y) {
		for (coord x=xs, xe=xs+w ; x<xe ; ++x) {
			drawPix(x, y, col);
		}
	}

}

void PPMImage::saveImage(std::string path) {
	std::ofstream file(path);

	file << "P3" << std::endl
		<< width << ' ' << height << std::endl
		<< "255" << std::endl;
	
	for (coord y=0 ; y<height ; ++y) {
		for (coord x=0 ; x<width ; ++x) {
			RGBColor curp = map[y*width + x];
			file << (int)curp.r << ' ' << (int)curp.g << ' ' << (int)curp.b << ' ';
		}
		file << std::endl;
	}
}

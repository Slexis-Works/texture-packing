#include "testPPM.hpp"

int main(int argc, char *argv[]) {
	PPMImage img(30, 20);

	img.drawPix(1, 1, Yellow);
	img.drawPix(0, 0, Blue);
	img.drawPix(2, 0, Red);

	img.fillRect(20, 10, 9, 9, Green);

	img.saveImage("test.ppm");

	return 0;
}

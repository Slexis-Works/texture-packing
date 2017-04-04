#include "testPPM.hpp"

int main(int argc, char *argv[]) {
	PPMImage img(30, 20);

	img.drawPix(1, 1, Yellow);
	img.drawPix(0, 0, Blue);
	img.drawPix(2, 0, Red);

	img.fillRect(20, 10, 9, 9, Green);

	img.saveImage("test.ppm");

	PPMImage::saveRectangle(30, 40, Green, "testSaveRectangle.ppm");

	PPMImage rectanglesBefore(200, 150), rectanglesAfter(200, 150);
	Rectangle rectR(10, 10, 40, 10, Red),
			rectG(15, 30, 20, 20, Green),
			rectB(1, 140, 198, 9, Blue);
	rectR.drawOn(rectanglesBefore);
	rectG.drawOn(rectanglesBefore);
	rectB.drawOn(rectanglesBefore);

	std::cout << "rectR and rectG " << (rectR.collides(rectG)?"overlap":"are separated") << std::endl;

	std::cout << "Flipping rectR..." << std::endl;
	rectR.flip();
	std::cout << "rectR and rectG " << (rectR.collides(rectG)?"overlap":"are separated") << std::endl;

	rectR.drawOn(rectanglesAfter);
	rectG.drawOn(rectanglesAfter);
	rectB.drawOn(rectanglesAfter);

	rectanglesBefore.saveImage("rectanglesBefore.ppm");
	rectanglesAfter.saveImage("rectanglesAfter.ppm");

	return 0;
}

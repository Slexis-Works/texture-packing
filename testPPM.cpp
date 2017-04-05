#include "testPPM.hpp"

int main() {
	/*PPMImage img(30, 20);

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
	rectanglesAfter.saveImage("rectanglesAfter.ppm");*/

	PPMImage shelvesImg(256, 256);

	Rectangle
		r11(50,100,Green),
		r12(90,80,Red),
		r13(200,10,Black), // Sera pas ajouté, trop large
		r14(10,85,Black), // Non plus, trop haut
		r15(100,30,Blue),
		r21(15,64,Red),
		r22(80,35,Green),
		r23(20,35,Blue),
		r24(40,36,Black); // Trop haut


	Shelf s1(256, 0, &r11);
	s1.putRect(&r12);
	s1.putRect(&r13);
	s1.putRect(&r14);
	s1.putRect(&r15);
	Shelf s2(256, 100, &r21);
	s2.putRect(&r22);
	s2.putRect(&r23);
	s2.putRect(&r24);

	std::cout << "Drawing first shelf" << std::endl;
	s1.drawOn(shelvesImg);
	std::cout << "Drawing second shelf" << std::endl;
	s2.drawOn(shelvesImg);
	std::cout << "Saving image" << std::endl;

	shelvesImg.saveImage("shelves.ppm");

	return 0;
}

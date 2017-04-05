#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "PPMImage.hpp"

class Rectangle {
public:
	Rectangle(coord x, coord y, coord w, coord h, RGBColor col = Black);
	Rectangle(coord w, coord h, RGBColor col = Black);

	// Fonctions utiles
	/**
	 * Tourne le rectangle de 90°
	 *
	 * La simili-rotation s'effectue en intervertissant
	 * hauteur et largeur.
	 */
	void flip();

	/**
	 * Redimensionne l'image
	 *
	 * @param	coord	nw	Nouvelle largeur, ignoré si 0
	 * @param	coord	nh	Nouvelle hauteur, ignoré si 0
	 */
	 void setSize(coord nw, coord nh);

	/**
	 * Dessine le rectangle sur une PPMImage
	 *
	 * @param	PPMImage	img	Image sur laquelle dessiner
	 */
	void drawOn(PPMImage &img);

	// Fonctions de test

	/**
	 * Indique si le rectangle empiète sur l'autre
	 *
	 * @param	const Rectangle	o	Autre rectangle
	 *
	 * @param	bool	true si les deux rectangles sont en collision
	 */
	bool collides(const Rectangle o);

	// GETters

	coord getX() { return x;}
	coord getY() { return y;}
	coord getW() { return w;}
	coord getH() { return h;}

	// SETters

	void setCoords(coord nx, coord ny) { x = nx; y = ny;}
	void setX(coord nx) { x = nx;}
	void setY(coord ny) { y = ny;}

private:
	coord x;
	coord y;
	coord w;
	coord h;

	RGBColor col;
};

#endif // RECTANGLE_HPP

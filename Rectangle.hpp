#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "PPMImage.hpp"

class Rectangle {
public:
	Rectangle(coord x, coord y, coord w, coord h, const RGBColor col = Black);
	Rectangle(coord w, coord h, const RGBColor col = Black);
	Rectangle(coord w, coord h, int col = 0);
	Rectangle(const Rectangle &r, coord x, coord y);

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
	void drawOn(PPMImage &img) const;

	// Fonctions de test

	/**
	 * Indique si le rectangle empiète sur l'autre
	 *
	 * @param	const Rectangle	o	Autre rectangle
	 *
	 * @param	bool	true si les deux rectangles sont en collision
	 */
	bool collides(const Rectangle o) const;

	// GETters

	coord getX() const { return x;}
	coord getY() const { return y;}
	coord getW() const { return w;}
	coord getH() const { return h;}

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

#ifndef RECTANGLE_H
#define RECTANGLE_H

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

private:
	coord x;
	coord y;
	coord w;
	coord h;

	RGBColor col;
};

#endif // RECTANGLE_H

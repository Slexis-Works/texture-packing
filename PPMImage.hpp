#ifndef PPMIMAGE_HPP
#define PPMIMAGE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <cassert>

typedef unsigned char color;
typedef unsigned int coord;

struct RGBColor {
	color r;
	color g;
	color b;
};

#define White	{255,255,255}
#define Black	{0,0,0}

#define Red	{255,0,0}
#define Green	{0,255,0}
#define Blue	{0,0,255}

#define Yellow	{255,255,0}
#define Cyan	{0,255,255}
#define Magenta	{255,0,255}


/**
 * Image PPM 24 bits à triplets RGB
 */
class PPMImage {
public:
	// Constructeur et destructeur
	/**
	 * Construit une image PPM aux tailles prédéfinies
	 *
	 * @param	coord	width	Largeur de l'image, en pixels
	 * @param	coord	height	Hauteur de l'image, en pixels
	 * @param	RGBColor	bgc	Couleur de fond, blanche par défaut
	 */
	PPMImage(coord width, coord height, RGBColor bgc = White);
	/**
	 * Destructeur de la classe, désalloue map
	 */
	~PPMImage();

	// Fonctions de dessin
	/**
	 * Colore un pixel de l'image
	 *
	 * @param	coord	x	Abscisse du pixel à teinter
	 * @param	coord	y	Ordonnée du pixel à teinter
	 * @param	RGBColor	col	Couleur à donner au pixel
	 */
	void drawPix(coord x, coord y, RGBColor col);

	/**
	 * Colore un rectangle de l'image
	 *
	 * @param	coord	xs	Abscisse du bord gauche du rectangle
	 * @param	coord	ys	Ordonnée du bord haut du rectangle
	 * @param	coord	w	Largeur du rectangle, en pixels
	 * @param	coord	h	Hauteur du rectangle, en pixels
	 * @param	RGBColor	col	Couleur à donner au pixel
	 */
	void fillRect(coord xs, coord ys, coord w, coord h, RGBColor col);

	/**
	 * Génére et enregistre le fichier image
	 *
	 * @param	std::string	path	Chemin du fichier
	 */
	void  saveImage(std::string path);

	/**
	 * Crée et enregistre une image unicolore
	 *
	 * @param	coord	width	Largeur de l'image, en pixels
	 * @param	coord	height	Hauteur de l'image, en pixels
	 * @param	RGBColor	col	Couleur de l'image
	 * @param	std::string	path	Chemin de l'image
	 */
	static void saveRectangle(coord w, coord h, RGBColor col, std::string path);

private:
	coord width;
	coord height;
	size_t length;
	struct RGBColor *map;

};

#endif // PPMIMAGE_HPP

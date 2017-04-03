#include <iostream>
#include <string>
#include <fstream>

typedef unsigned char color;
typedef unsigned int coord;

struct RGBColor {
	color r;
	color g;
	color b;
};



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
	 */
	PPMImage(coord width, coord height);
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
	void fill(coord xs, coord ys, coord w, coord h, RGBColor col);

	/** Génére et enregistre le fichier image
	 *
	 * @param	std::string	path	Chemin du fichier
	 */
	void  saveImage(std::string path);

private:
	coord width;
	coord height;
	struct RGBColor *map;

};


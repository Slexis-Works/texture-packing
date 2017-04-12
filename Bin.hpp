#ifndef BIN_HPP
#define BIN_HPP

#include <vector>

#include "Rectangle.hpp"
#include "Shelf.hpp"
#include "PPMImage.hpp"

/**
 * Classe représentant une boîte contenant des rectangles
 *
 * Les rectangles passés en paramètres sont copiés
 */
class Bin {
public:
	/**
	 * Constructeur de la classe
	 *
	 * @param	coord	width	Largeur de la boîte
	 * @param	coord	height	Hauteur de la boîte
	 */
	Bin(coord width, coord height);

	/**
	 * Ajoute le rectangle dans la boîte sans vérifier
	 *
	 * @param	Rectangle*	rect	Rectangle à insérer, possédant une couleur et une taille
	 * @param	coord	x	Abcisse dans la boîte du rectangle
	 * @param	coord	y	Ordonnée dans la boîte du rectangle
	 */
	void addRect(const Rectangle &rect, coord x, coord y);

	/**
	 * Importe un étage pré-construit
	 *
	 * @param	Shelf*	shelf	Étage dont on veut importer les rectangles
	 */
	void importShelf(const Shelf &shelf);

	/**
	 * Dessine toute la boîte sur l'image
	 *
	 * @param	PPMImage&	img	Image sur laquelle dessiner. Devrait avoir les mêmes dimensions que la boîte
	 */
	void drawOn(PPMImage &img) const;

private:
	coord width;
	coord height;
	std::vector<Rectangle> rects;
};

#endif // SHELF_HPP

#ifndef SHELF_HPP
#define SHELF_HPP

#include <vector>

#include "Rectangle.hpp"
#include "PPMImage.hpp"

class Shelf {
public:
	/**
	 * Crée l'étage avec un premier élément
	 *
	 * @param	coord	width	Largeur maximale de l'étagère, en pixels
	 * @param	coord	y	Ordonnée du bord inférieur de l'étagère
	 * @param	Rectangle&	first	Rectangle calé à gauche
	 */
	Shelf(coord width, coord y, const Rectangle &first);

	/**
	 * Essaie d'insérer le rectangle donné et modifie ses coordonnées
	 *
	 * @param	Rectangle&	rect	Rectangle à insérer, calé en bas et à droite du bloc le plus à droite
	 *
	 * @return	bool	Indique si l'insertion a pu être acceptée
	 */
	bool putRect(const Rectangle &rect);

	/**
	 * Essaie d'insérer le rectangle donné en autorisant les rotations
	 *
	 * @param	Rectangle&	rect	Rectangle à insérer, pouvant être tourné
	 *
	 * @return	int	0 en cas d'impossibilité, 1 si l'insertion a pu se faire directement, 2 s'il y a eu besoin d'une rotation
	 */
	int putRotatableRect(const Rectangle &rect);

	/**
	 * Modifie l'ordonnée de l'étage et des rectangles présents
	 *
	 * @param	coord	ny	Nouvelle ordonnée
	 */
	void setY(coord ny);

	/**
	 * Dessine toute l'étagère sur l'image
	 *
	 * @param	PPMImage&	img	Image sur laquelle dessiner
	 */
	void drawOn(PPMImage &img) const;

	/**
	 * Permet l'accès en lecture à tous les rectangles contenus
	 */
	const std::vector<Rectangle>& getRects() const { return rects;}

	/**
	 * Renvoie la hauteur de l'étage
	 */
	coord getHeight() const { return height;}

	/**
	 * Renvoie l'espace restant de l'étage
	 */
	 coord getEmptySpace() { return maxWidth-curWidth;}
private:
	coord height;
	coord y;
	coord curWidth;
	coord maxWidth;
	std::vector<Rectangle> rects;
};

#endif // SHELF_HPP

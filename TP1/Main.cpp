/**************************************************
 * Titre: Travail pratique #1 - Main.cpp
 * Date: Septembre 2017
 * Auteurs: Charles Marois et François-Xavier Legault
 *
 *
 *Questions:
 * 1. Quel est le lien (agrégation ou composition) entre la classe GroupImage 
 * et la classe Image?
 *
 *		La classe Image a un lien de composition avec la classe GroupImage, car
 *		GroupImage utilise l'objet Image comme un de ses attributs. De plus, si
 *		L'objet GroupImage est détruit, son attribut Image disparait aussi.
 *
 *
 * 2. Quel effet aura une méthode si elle aura la mention const?
 *
 *		Si une méthode a la mention const, elle n'aura pas le droit 
 *		de modifier la valeur d'un attribut de l'objet et d'utiliser
 *		une méthode qui n'a pas été déclarée constante.
**************************************************/

#include "Pixel.h"
#include "Image.h"
#include "GroupImage.h"


#include <string>
#include <iostream>

using namespace std;

int main()
{
	//1- Creez 9 pixels rouge  (255,0,0)	
	Pixel pixelsRouges[9];
	for (unsigned int i = 0; i < 9; i++) {
		pixelsRouges[i] = Pixel(255, 0, 0);
	}
	//2-Creez 9 pixels verts (0,255,0)
	Pixel pixelsVerts[9];
	for (unsigned int i = 0; i < 9; i++) {
		pixelsVerts[i] = Pixel(0, 255, 0);
	}
	//3- Creez une image de taille 3*3 
	Image image0 = Image("image0", 3, 3);

	//4- Ajouter à l'image créée à l'étape 3 les pixels rouges
	for (unsigned int i = 0; i < 3; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			image0.ajouterPixel(pixelsRouges[i + 3 * j], i, j);
		}
	}

	//5- Creez une deuxième image de taille 3*3 
	Image image1 = Image("image1", 3, 3);

	//6- Ajouter à l'image créées à l'étape 3 les pixels verts
	for (unsigned int i = 0; i < 3; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			image1.ajouterPixel(pixelsVerts[i + 3 * j], i, j);
		}
	}

	//7- Creez un groupe d'image avec une capacite de 3
	GroupImage groupeImage = GroupImage("", 3);

	//8- Ajoutez les deux images crées precédament au groupe
	groupeImage.ajouterImage(image0);
	groupeImage.ajouterImage(image1);
	
	//9- Augmentez la teinte bleu du Pixel (1,1) de l'image 0 de 50 unités
	groupeImage.obtenirImage(0).augmenterTeintePixel(1, 1, 50, 'B');
	 
	//10- Diminuer la teinte rouge du Pixel (1, 1) de l'image 0 de 255 unités
	image0.augmenterTeintePixel(1, 1, -255, 'R');
	
	//11- Augmentez la teinte bleu du Pixel (2, 1) de l'image 1 de 100 unités  
	image1.augmenterTeintePixel(2, 1, 100, 'B');
	
	//12- Affichez les images de ce groupe
	groupeImage.afficherImages();

	//13- Doublez la taille de la premiere image du groupe en largeur	
	groupeImage.doublerTailleImageEnLargeur(0);

	//14- Doublez la taille de la deuxieme image du groupe en hauteur
	groupeImage.doublerTailleImageEnHauteur(1);

	//15- Afficher cette image 
	groupeImage.obtenirImage(1).afficherImage();

	return 0;
}
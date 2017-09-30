/**************************************************
 * Titre: Travail pratique #1 - Main.cpp
 * Date: Septembre 2017
 * Auteur: 
**************************************************/

#include "Pixel.h"
#include "Image.h"
#include "GroupImage.h"


#include <string>
#include <iostream>

using namespace std;

/*
TODO : Veuillez répondre aux question ici
1)
2)
3)
*/

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
	
	//4- Ajouter à l'image créées à l'étape 3 les pixels rouges
	for (unsigned int i = 0; i < image0.obtenirNombrePixelLargeur(); i++) {
		for (unsigned int j = 0; j < image0.obtenirNombrePixelHauteur(); j++) {
			image0.ajouterPixel(pixelsRouges[i + 3 * j], i, j);
		}
	}

	//5- Creez une deuxième image de taille 3*3 
	Image image1 = Image("image1", 3, 3);
	
	//6- Ajouter à l'image créées à l'étape 3 les pixels verts
	for (unsigned int i = 0; i < image1.obtenirNombrePixelLargeur(); i++) {
		for (unsigned int j = 0; j < image1.obtenirNombrePixelHauteur(); j++) {
			image1.ajouterPixel(pixelsVerts[i + 3 * j], i, j);
		}
	}

	//7- Creez un groupe d'image avec une capacite de 3
	GroupImage groupeImage = GroupImage(3);
	
	//8- Ajoutez les deux images crées precédament au groupe
	//const Image* ptrImage0 = &image0;
	//groupeImage.ajouterImage(ptrImage0);
	groupeImage += image0;
	groupeImage += image1;

	cout << groupeImage;
	
	//9- Augmentez la teinte bleu du Pixel (1,1) de l'image 0 de 50 unités
	//groupeImage.obtenirImage(0)->augmenterTeintePixel(1, 1, 50, 'B');
	 
	//10- Diminuer la teinte rouge du Pixel (1, 1) de l'image 0 de 255 unités
	//groupeImage.obtenirImage(0)->augmenterTeintePixel(1, 1, 255, 'R');
	
	//11- Augmentez la teinte bleu du Pixel (2, 1) de l'image 1 de 100 unités  
	//groupeImage.obtenirImage(1)->augmenterTeintePixel(2, 1, 100, 'B');
	
	//12- Afficher le groupe d'image
	//cout << groupeImage;
	
	//13- Supprimer la premiere image du groupe d'image
	
	//14- Afficher le groupe d'image
	
	
	return 0;
}
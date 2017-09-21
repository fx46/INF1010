#include "Image.h"
#include "Pixel.h"
#include "Const.h"
#include <string>
#include <iostream>
	
using namespace std;
	
Image::Image(){
	nomImage_ = "";
	nombrePixelEnHauteur_ = 0;
	nombrePixelEnLargeur_ = 0;
	pixels_ = nullptr;
}

Image::Image(const string& nomImage,unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur){
	nomImage_ = nomImage;
	nombrePixelEnHauteur_ = nombrePixelHauteur;
	nombrePixelEnLargeur_ = nombrePixelLargeur;
	pixels_ = new Pixel*[nombrePixelLargeur];
	for (unsigned int i = 0; i < nombrePixelLargeur; i++) {
		pixels_[i] = new Pixel[nombrePixelHauteur];
	}
}

Image::~Image()
{
}

string Image::obtenirNomImage() const{
	return nomImage_;
}

unsigned int Image::obtenirNombrePixelHauteur() const{
	return nombrePixelEnHauteur_;
}

unsigned int Image::obtenirNombrePixelLargeur() const{
	return nombrePixelEnLargeur_;
}

void Image::modifierNomImage(const string & nomImage){
	nomImage_ = nomImage;
}

void Image::doublerTailleEnLargeur(){
	Image nouvelleImage = Image("temp", obtenirNombrePixelHauteur(), 2 * obtenirNombrePixelLargeur());
	nouvelleImage.pixels_ = pixels_;
	pixels_ = nouvelleImage.pixels_;
	nombrePixelEnLargeur_ *= 2;
}

void Image::doublerTailleEnHauteur(){
	Image nouvelleImage = Image("temps", 2 * obtenirNombrePixelHauteur(), obtenirNombrePixelLargeur());
	nouvelleImage.pixels_ = pixels_;
	pixels_ = nouvelleImage.pixels_;
	nombrePixelEnHauteur_ *= 2;
}

bool Image::ajouterPixel(Pixel & pixel,unsigned int positionLargeur, unsigned int positionHauteur){
	if (positionLargeur >= 0 && 
		positionHauteur >= 0 && 
		positionLargeur < obtenirNombrePixelLargeur() &&
		positionHauteur < obtenirNombrePixelHauteur()) {
			pixels_[positionLargeur][positionHauteur] = pixel;
			return true;
	}
	return false;
}

Pixel Image::obtenirPixel(unsigned int positionHauteur, unsigned int positionLargeur) const{
	return pixels_[positionLargeur][positionHauteur];
}

void Image::augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur){
	if (couleur == 'R') {
		pixels_[positionLargeur][positionHauteur].modifierTeinteRouge(increment);
	}
	else if (couleur == 'B') {
		pixels_[positionLargeur][positionHauteur].modifierTeinteBleu(increment);
	}
	else {
		pixels_[positionLargeur][positionHauteur].modifierTeinteVert(increment);
	}
}

void Image::afficherImage() const {
	cout << "Affichage de l'image : " << nomImage_ << endl;
	for (unsigned int i = 0; i < obtenirNombrePixelHauteur(); i++) {
		cout << "\t";
		for (unsigned int j = 0; j < obtenirNombrePixelLargeur(); j++) {
			pixels_[j][i].afficherPixel();
		}
		cout << endl;
	}
	cout << endl;
}

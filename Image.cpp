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
	pixels_ = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		pixels_[i] = new Pixel[nombrePixelEnLargeur_];
	}
}

Image::~Image()
{
	/*
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		delete pixels_[i];
	}
	delete[] pixels_;
	pixels_ = nullptr;
	*/
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
	Pixel** pixelsTemp = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		pixelsTemp[i] = new Pixel[2 * nombrePixelEnLargeur_];
	}
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		for (unsigned int j = 0; j < nombrePixelEnLargeur_; j++) {
			pixelsTemp[i][j] = pixels_[i][j];
		}
	}
	//delete pixels_;
	nombrePixelEnLargeur_ *= 2;
	pixels_ = pixelsTemp;
}

void Image::doublerTailleEnHauteur(){
	Pixel** pixelsTemp = new Pixel*[2 * nombrePixelEnHauteur_];
	for (unsigned int i = 0; i < 2 * nombrePixelEnHauteur_; i++) {
		pixelsTemp[i] = new Pixel[nombrePixelEnLargeur_];
	}
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		for (unsigned int j = 0; j < nombrePixelEnLargeur_; j++) {
			pixelsTemp[i][j] = pixels_[i][j];
		}
	}
	//delete pixels_;
	nombrePixelEnHauteur_ *= 2;
	pixels_ = pixelsTemp;
}

bool Image::ajouterPixel(Pixel & pixel,unsigned int positionLargeur, unsigned int positionHauteur){
	if (positionLargeur >= 0 && 
		positionHauteur >= 0 && 
		positionLargeur < obtenirNombrePixelLargeur() &&
		positionHauteur < obtenirNombrePixelHauteur()) {
			pixels_[positionHauteur][positionLargeur] = pixel;
			return true;
	}
	return false;
}

Pixel Image::obtenirPixel(unsigned int positionHauteur, unsigned int positionLargeur) const{
	return pixels_[positionHauteur][positionLargeur];
}

void Image::augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur){
	if (couleur == 'R') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteRouge(increment);
	}
	else if (couleur == 'B') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteBleu(increment);
	}
	else {
		pixels_[positionHauteur][positionLargeur].modifierTeinteVert(increment);
	}
}

void Image::afficherImage() const {
	cout << "Affichage de l'image : " << nomImage_ << endl;
	for (unsigned int i = 0; i < obtenirNombrePixelHauteur(); i++) {
		cout << "\t";
		for (unsigned int j = 0; j < obtenirNombrePixelLargeur(); j++) {
			pixels_[i][j].afficherPixel();
		}
		cout << endl;
	}
	cout << endl;
}

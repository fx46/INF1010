#include "Image.h"
#include "Pixel.h"
#include "Const.h"
	
using namespace std;
	
Image::Image(){
	nomImage_ = "";
	nombrePixelEnHauteur_ = 0;
	nombrePixelEnLargeur_ = 0;
	pixels_ = 0;
}

Image::Image(const string& nomImage,unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur){
	nomImage_ = nomImage;
	nombrePixelEnHauteur_ = nombrePixelHauteur;
	nombrePixelEnLargeur_ = nombrePixelLargeur;
	pixels_ = 0;
}

Image::~Image()
{
}

string Image::obtenirNomImage() const{
	return this->nomImage_;
}

unsigned int Image::obtenirNombrePixelHauteur() const{
	return this->nombrePixelEnHauteur_;
}

unsigned int Image::obtenirNombrePixelLargeur() const{
	return this->nombrePixelEnLargeur_;
}

void Image::modifierNomImage(const string & nomImage){
	nomImage_ = nomImage;
}

void Image::doublerTailleEnLargeur(){
	nombrePixelEnLargeur_ = 2 * nombrePixelEnLargeur_;
}
void Image::doublerTailleEnHauteur(){
	nombrePixelEnHauteur_ = 2 * nombrePixelEnHauteur_;
}

bool Image::ajouterPixel(Pixel & pixel,unsigned int positionLargeur, unsigned int positionHauteur){
	if (positionLargeur <= nombrePixelEnLargeur_ && positionHauteur <= nombrePixelEnHauteur_) {
		pixels_[positionHauteur][positionHauteur] = pixel;
		return true;
	}
	return false;
}

Pixel Image::obtenirPixel(unsigned int positionHauteur, unsigned int positionLargeur) const{
	return pixels_[positionLargeur][positionHauteur];
}

void Image::augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur){
	Pixel pixel = obtenirPixel(positionLargeur, positionHauteur);
	if (couleur = 'R') {
		pixel.modifierTeinteRouge(increment);
	}
	else if (couleur = 'B') {
		pixel.modifierTeinteBleu(increment);
	}
	else {
		pixel.modifierTeinteVert(increment);
	}
}

void Image::afficherImage() const {
	for (unsigned int i = obtenirNombrePixelHauteur(); i > 0; i--) {
		for (unsigned int j = obtenirNombrePixelLargeur(); j > 0; j--) {
			pixels_[i][j].afficherPixel();
		}
	}
}

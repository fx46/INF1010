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
	this->nomImage_ = nomImage;
}

void doublerTailleEnLargeur(){
	nombrePixelEnLargeur_ = 2 * nombrePixelEnLargeur_;
}
void doublerTailleEnHauteur(){
	nombrePixelEnHauteur_ = 2 * nombrePixelEnHauteur_;
}

bool ajouterPixel(Pixel & pixel,unsigned int positionLargeur, unsigned int positionHauteur){
	pixels_[positionLargeur][positionHauteur] = pixel;
}

Pixel obtenirPixel(unsigned int positionHauteur, unsigned int positionLargeur) const{
	return pixels_[positionLargeur][positionHauteur];
}

void augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur){
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

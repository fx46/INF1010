#include "Image.h"
#include "Pixel.h"
#include "Const.h"
	
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
	nombrePixelEnLargeur_ = 2 * nombrePixelEnLargeur_;
}
void Image::doublerTailleEnHauteur(){
	nombrePixelEnHauteur_ = 2 * nombrePixelEnHauteur_;
}

bool Image::ajouterPixel(Pixel & pixel,unsigned int positionLargeur, unsigned int positionHauteur){
	if (positionLargeur <= nombrePixelEnLargeur_ && positionHauteur <= nombrePixelEnHauteur_) {
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
	for (unsigned int i = 0; i < obtenirNombrePixelLargeur(); i++) {
		cout << "\t";
		for (unsigned int j = 0; j < obtenirNombrePixelHauteur(); j++) {
			obtenirPixel(i, j).afficherPixel();
		}
		cout << endl;
	}
}

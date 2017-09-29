
#include "Image.h"
#include <iostream>
#include "Const.h"
#include <string>

using namespace std;

Image::Image():nomImage_("Image Vide"),nombrePixelEnHauteur_(1),nombrePixelEnLargeur_(1)
{
	pixels_ = new Pixel*[1];
	pixels_[0] = new Pixel[1];
}


Image::~Image()
{
	/*
	for(unsigned int i = 0; i < nombrePixelEnHauteur_; i++){
		delete[] pixels_[i];
	}
	delete[] pixels_;
	nombrePixelEnHauteur_ = 0;
	nombrePixelEnLargeur_ = 0;
	pixels_ = nullptr;
	*/
}

Image::Image(const string& nomImage,unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur) :nomImage_(nomImage),
	nombrePixelEnHauteur_(nombrePixelHauteur), nombrePixelEnLargeur_(nombrePixelLargeur)
{
	pixels_ = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_;i++) {
		pixels_[i] = new Pixel[nombrePixelEnLargeur_];
	}
}


void Image::modifierNomImage(const string & nomImage) {
	nomImage_ = nomImage;
}


unsigned int Image::obtenirNombrePixelHauteur() const {
	return nombrePixelEnHauteur_;
}


unsigned int Image::obtenirNombrePixelLargeur() const {
	return nombrePixelEnLargeur_;
}

string Image::obtenirNomImage() const{
	return nomImage_;
}

bool Image::ajouterPixel(Pixel & pixel, unsigned int positionLargeur, unsigned int positionHauteur) {
	if (positionLargeur >= nombrePixelEnLargeur_ || positionHauteur >= nombrePixelEnHauteur_) {
		return false;
	}
	else {
		pixels_[positionHauteur][positionLargeur] = pixel;
		return true;
	}
}

void Image::doublerTailleEnHauteur(){
	nombrePixelEnHauteur_ *= 2;

	Pixel** imageTemp = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0;i < nombrePixelEnHauteur_ / 2;i++) {
		imageTemp[i] = pixels_[i];
	}

	for (unsigned int i = nombrePixelEnHauteur_ / 2;i < nombrePixelEnHauteur_;i++) {
		imageTemp[i] = new Pixel[nombrePixelEnLargeur_];
	}	

	delete[] pixels_;
	pixels_ = imageTemp;
	imageTemp = nullptr;

}

void Image::doublerTailleEnLargeur() {
	nombrePixelEnLargeur_ *= 2;

	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		Pixel* colonneImage = new Pixel[nombrePixelEnLargeur_];
		for (unsigned int j = 0;j < nombrePixelEnLargeur_ / 2; j++) {
			colonneImage[j] = pixels_[i][j];
		}
		delete[] pixels_[i];
		pixels_[i] = colonneImage;

	}

	
}
/*
void Image::afficherImage() const {

	cout << "Affichage de l'image :  " << obtenirNomImage().c_str()<< endl;
	
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		cout << "    ";
			for (unsigned int j = 0; j < nombrePixelEnLargeur_;j++) {
					pixels_[i][j].afficherPixel();
		    }
		cout << endl;
	}
}
*/

Pixel Image::obtenirPixel(unsigned int positionLargeur,unsigned int positionHauteur) const {
 
	return pixels_[positionHauteur][positionLargeur];

}

void Image::augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur) {

	if (couleur == 'R') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteRouge(increment);
	}
	if (couleur == 'G') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteVert(increment);
	}
	if (couleur == 'B') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteBleu(increment);
	}

}
//constructeur par copie nécessaire?
Image::Image(const Image &I) {
	nomImage_ = I.nomImage_;
	nombrePixelEnHauteur_ = I.nombrePixelEnHauteur_;
	nombrePixelEnLargeur_ = I.nombrePixelEnLargeur_;
}

Image & Image::operator = (const Image & P) {
	if (this != &I)
	{
		~Image();  //décommenter la fonction ~ pour voir si cela fonctionne
		this->nomImage_ = I.nomImage_;
		this->nombrePixelEnHauteur_ = I.nombrePixelEnHauteur_;
		this->nombrePixelEnLargeur_ = I.nombrePixelEnLargeur_;

		pixels_ = new Pixel*[nombrePixelEnHauteur_];
		for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
			this->pixels_[i] = new Pixel[nombrePixelEnLargeur_];
			for (unsigned int j = 0; j < nombrePixelEnLargeur_; j++) {
				this->pixels_[i][j] = I.pixels_[i][j];
			}
		}
	}
	return *this;
}

friend ostream & operator << (ostream & sortie, const Image & I) {
	sortie << "Affichage de l'image :  " << I.obtenirNomImage().c_str() << endl;

	for (unsigned int i = 0; i < I.nombrePixelEnHauteur_; i++) {
		sortie << "    ";
		for (unsigned int j = 0; j < I.nombrePixelEnLargeur_; j++) {
			if(I.pixels_[i][j] != nullptr)
				I.pixels_[i][j].retournerCouleur();  //ou utiliser l'opérateur << de Pixel??
		}
		sortie << endl;
	}

	return sortie;
}

bool Image::operator == (const Image & I){
	bool trigger = true;
	if (this->nomImage_ == I.nomImage_) {
		for (unsigned int i = 0; i < this->nombrePixelEnHauteur_; i++) {
			for (unsigned int j = 0; j < this->nombrePixelEnLargeur_; j++) {
				if (this->pixels_[i][j] != I.pixels_[i][j])
					trigger = false;
			}
		}
		return trigger;
	}
	else
		trigger = false;
		return trigger
}

bool Image::operator == (const string & name) {
	return this->nomImage_ == name;
}

bool operator == (const string & name, const Image & I) {
	return name == I.nomImage_;
}
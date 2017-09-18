#include "GroupImage.h"
#include "Image.h"
#include <string>

using namespace std;

GroupImage::GroupImage() {
	type_ = "";
	nombreImages_ = 0;
	capaciteImages_ = 0;
	images_ = nullptr;
}

GroupImage::~GroupImage() {
}

GroupImage::GroupImage(const string &type, unsigned int capaciteImages) {
	type_ = type;
	capaciteImages_ = capaciteImages;
	nombreImages_ = 0;
	images_ = new Image[capaciteImages];
}

void GroupImage::modifierType(const string &type) {
	type_ = type;
}

string GroupImage::obtenirType() const {
	return type_;
}

Image GroupImage::obtenirImage(unsigned int indiceImage) const {
	return images_[indiceImage];
}

unsigned int GroupImage::obtenirNombreImages() const {
	return nombreImages_;
}

void GroupImage::ajouterImage(const Image &image) {
	if (nombreImages_ < capaciteImages_) {
		images_[nombreImages_] = image;
		nombreImages_++;
	}
}

void GroupImage::afficherImages() const {
	for (unsigned int i = 0; i < obtenirNombreImages(); i++) {
		obtenirImage(i).afficherImage();
	}
}

void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage) {
	Image nouvelleImage = obtenirImage(indiceImage);
	nouvelleImage.doublerTailleEnLargeur();
	images_[indiceImage] = nouvelleImage;
}

void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage) {
	Image nouvelleImage = obtenirImage(indiceImage);
	nouvelleImage.doublerTailleEnHauteur();
	images_[indiceImage] = nouvelleImage;
}
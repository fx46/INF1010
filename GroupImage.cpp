#include "GroupImage.h"
#include "Image.h"
#include <string>

using namespace std;

GroupImage::GroupImage() {
	type_ = "";
	nombreImages_ = 0;
	capaciteImages_ = 0;
}

GroupImage::~GroupImage() {
}

GroupImage::GroupImage(const string &type, unsigned int capaciteImages) {
	type_ = type;
	capaciteImages_ = capaciteImages;
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
	images_[capaciteImages_++] = image;
}

void GroupImage::afficherImages() const {
	for (unsigned int i = obtenirNombreImages(); i > 0; i--) {
		obtenirImage(i).afficherImage();
	}
}

void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage) {
	obtenirImage(indiceImage).doublerTailleEnLargeur();
}

void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage) {
	obtenirImage(indiceImage).doublerTailleEnHauteur();
}

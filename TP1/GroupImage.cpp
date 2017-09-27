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
	for (int i = 0; i < nombreImages_; i++) {
		images_[i].~Image();
	}
	delete[] images_;
	images_ = nullptr;
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
	images_[indiceImage].doublerTailleEnLargeur();
}

void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage) {
	images_[indiceImage].doublerTailleEnHauteur();
}


#include "GroupImage.h"
#include <iostream>
#include <string>

using namespace std;

GroupImage::GroupImage() {
}

GroupImage::~GroupImage() {
	for (unsigned int i = 0; i < images_.size() - 1; i++) {
		delete images_[i];
	}
}

void GroupImage::modifierType(const string & type) {
	type_ = type;
}

string GroupImage::obtenirType() const{
	return type_;
}

void GroupImage::ajouterImage(Image& image) {
	bool nomDejaPris = false;
	for (unsigned int i = 0; i < images_.size(); i++) {
		if (image.obtenirNomImage() == *images_[i]) {
			nomDejaPris = true;
		}
	}
	if (!nomDejaPris) {
		images_.push_back(&image);
	}
}

void GroupImage::retirerImage(const string & name) {
	for (unsigned int i = 0; i < images_.size(); i++) {
		if (*images_[i] == name) {
			for (unsigned int j = i; j < images_.size() - 1; j++) {
				images_[j] = images_[j + 1];
			}
			images_.pop_back();
		}
	}
}
void GroupImage::afficherImages(ostream& os) const {

	os << "*********************************************" << endl;
	os << "Affichage des images du groupe :  ";
	os << obtenirType().c_str() << endl;
	os << "*********************************************"<< endl;
	
	for (unsigned int i = 0; i < images_.size(); i++) {

		os << *images_[i];
		os << "---------------------------------------------" << endl;

	}
	cout << endl;
}

Image* GroupImage::obtenirImage(unsigned int indiceImage) const {
	return images_[indiceImage];
}

void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage) {
	images_[indiceImage]->doublerTailleEnLargeur();
}

void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage) {
	images_[indiceImage]->doublerTailleEnHauteur();
}
 
GroupImage & GroupImage::operator += (Image &I) {
	ajouterImage(I);
	return *this;
}

GroupImage & GroupImage::operator -= (Image &I) {
	retirerImage(I.obtenirNomImage());
	return *this;
}

ostream& operator<<(ostream& sortie, const GroupImage& G) {
	G.afficherImages(sortie);
	return sortie;
}
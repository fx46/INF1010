
#include "GroupImage.h"
#include <iostream>

using namespace std;

GroupImage::GroupImage():nombreImages_(1),capaciteImages_(1) {
	images_.push_back(new Image[1]);
}

GroupImage::~GroupImage() {
	for (unsigned int i = 0; i < images_.size(); i++) {
		delete images_[i];
	}
	capaciteImages_ = 0;
	nombreImages_ = 0;
}

/*GroupImage::GroupImage(const string & type,unsigned int capaciteImages): type_(type), capaciteImages_(capaciteImages) {

	images_ = new Image[capaciteImages_];
	nombreImages_ = 0;
}
*/

void GroupImage::modifierType(const string & type) {
	type_ = type;
}

string GroupImage::obtenirType() const{
	return type_;
}

/*unsigned int GroupImage::obtenirNombreImages() const {
	return nombreImages_;
}*/

void GroupImage::ajouterImage(const Image*& image) {
	images_.push_back(new Image(*image));
	nombreImages_++;
}

void GroupImage::retirerImage(const string & name) {
	for (unsigned int i = 0; i < images_.size() - 1; i++) {
		if (images_[i]->obtenirNomImage() == name) {
			for (unsigned int j = i; j < images_.size() - 1; j++) {
				images_[j] = images_[j + 1];
			}
			images_.pop_back();
			break;
		}
	}
}
void GroupImage::afficherImages(ostream& os) const {

	cout << "*********************************************" << endl;
	cout << "Affichage des images du groupe :  ";
	cout << obtenirType().c_str() << endl;
	cout << "*********************************************"<< endl;
	
	for (unsigned int i = 0; i < nombreImages_; i++) {

		cout << images_[i];
		cout << "---------------------------------------------" << endl;

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
 
GroupImage & GroupImage::operator += (const Image & I) {
	const Image* ptrI = &I;
	this->ajouterImage(ptrI);
	return *this;
}

GroupImage & GroupImage::operator -= (const Image & I) {
	this->retirerImage(I.obtenirNomImage());
	return *this;
}
#include "Pixel.h"
#include "Const.h"


Pixel::Pixel()
{
	tauxRouge_ = 0;
	tauxVert_ = 0;
	tauxBleu_ = 0;
}

Pixel::~Pixel()
{
}

Pixel::Pixel(unsigned int tauxRouge, unsigned int tauxVert, unsigned int tauxBleu) {
	tauxRouge_ = tauxRouge;
	tauxVert_ = tauxVert;
	tauxBleu_ = tauxBleu;
}

unsigned int Pixel::getR() {
	return tauxRouge_;
}

unsigned int Pixel::getV() {
	return tauxVert_;
}

unsigned int Pixel::getB() { 
	return tauxBleu_;
}

void Pixel::modifierTeinteRouge(int incrementRouge) {
	if (tauxRouge_ += incrementRouge < MIN_CONCENTRATION_COULEUR) {
		tauxRouge_ = MIN_CONCENTRATION_COULEUR;
	}
	else if (tauxRouge_ += incrementRouge > MAX_CONCENTRATION_COULEUR) {
		tauxRouge_ = MAX_CONCENTRATION_COULEUR;
	}
	else { tauxRouge_ += incrementRouge; }
}
	

void Pixel::modifierTeinteVert(int incrementVert) {
	if (tauxVert_ += incrementVert < MIN_CONCENTRATION_COULEUR) {
		tauxVert_ = MIN_CONCENTRATION_COULEUR;
	}
	else if (tauxVert_ += incrementVert > MAX_CONCENTRATION_COULEUR) {
		tauxVert_ = MAX_CONCENTRATION_COULEUR;
	}
	else { tauxVert_ += incrementVert; }
}

void Pixel::modifierTeinteBleu(int incrementBleu) {
	if (tauxBleu_ += incrementBleu < MIN_CONCENTRATION_COULEUR) {
		tauxBleu_ = MIN_CONCENTRATION_COULEUR;
	}
	else if (tauxBleu_ += incrementBleu > MAX_CONCENTRATION_COULEUR) {
		tauxRouge_ = MAX_CONCENTRATION_COULEUR;
	}
	else { tauxBleu_ += incrementBleu; }
}

void Pixel::afficherPixel() const {
	;
}


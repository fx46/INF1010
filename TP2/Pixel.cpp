
#include "Pixel.h"
#include <iostream>
#include "Const.h"

using namespace std;

Pixel::Pixel() : tauxRouge_(0),tauxVert_(0),tauxBleu_(0)
{
}


Pixel::~Pixel()
{
}

Pixel::Pixel(unsigned int tauxRouge, unsigned int tauxVert, unsigned int tauxBleu) :
	tauxRouge_(tauxRouge), tauxVert_(tauxVert), tauxBleu_(tauxBleu)
{
}


unsigned int Pixel::obtenirTauxRouge() const {
	return tauxRouge_;
}
unsigned int Pixel::obtenirTauxVert() const {
	return tauxVert_;
}
unsigned int Pixel::obtenirTauxBleu() const {
	return tauxBleu_;
}

void Pixel::modifierTeinteRouge(int incrementRouge) {
	if (incrementRouge < 0) {
		if (abs(incrementRouge) >= tauxRouge_) {
		    tauxRouge_ = MIN_CONCENTRATION_COULEUR;
		}
		else {
		    tauxRouge_ -= incrementRouge;
		}
	}
	else {
		unsigned int temp = tauxRouge_ + incrementRouge;
		if (temp >= MAX_CONCENTRATION_COULEUR) {
		    tauxRouge_ = MAX_CONCENTRATION_COULEUR;
		}
		else {
		    tauxRouge_ = temp;
		}
	}
}

void Pixel::modifierTeinteVert( int incrementVert) {
	if (incrementVert < 0) {
		if (abs(incrementVert) >= tauxVert_) {
		    tauxVert_ = MIN_CONCENTRATION_COULEUR;
		}
		else {
		    tauxVert_ -= incrementVert;
		}
	}
	else {
		unsigned int temp = tauxVert_ + incrementVert;
		if (temp >= MAX_CONCENTRATION_COULEUR) {
		    tauxVert_ = MAX_CONCENTRATION_COULEUR;
		}
		else {
		    tauxVert_ = temp;
		}
	}
}

void Pixel::modifierTeinteBleu( int incrementBleu) {
	if (incrementBleu < 0) {
		if (abs(incrementBleu) >= tauxBleu_) {
		    tauxBleu_ = MIN_CONCENTRATION_COULEUR;
		}
		else {
		    tauxBleu_ -= incrementBleu;
		}
	}
	else {
		unsigned int temp = tauxBleu_ + incrementBleu;
		if (temp >= MAX_CONCENTRATION_COULEUR) {
		    tauxBleu_ = MAX_CONCENTRATION_COULEUR;
		}
		else {
		    tauxBleu_ = temp;
		}
	}
}

char Pixel::retournerCouleur() const{
	if (tauxVert_ == 0 && tauxBleu_ == 0 && tauxRouge_ != 0) {
		return 'R';

	}
	else if (tauxRouge_ == 0 && tauxBleu_ == 0 && tauxVert_ != 0) {
		return 'G';

	}
	else if (tauxRouge_ == 0 && tauxVert_ == 0 && tauxBleu_ != 0) {
		return 'B';

	}
	// Optionnel, si on veut distinguer colore et completement noir
	/*
	else if (tauxRouge_ == 0 && tauxVert_ == 0 && tauxBleu_ == 0){
	cout <<'O';
	}
	*/
	else {
		return << 'Q';
	}

// affiche la couleur du pixel
// en appelant << pour un objet de classe Pixel
ostream & Pixel::operator << (ostream & sortie, const Pixel & P){
	if (P.tauxVert_ == 0 && P.tauxBleu_ == 0 && P.tauxRouge_ != 0) {
		cout << 'R';

	}
	else if (P.tauxRouge_ == 0 && P.tauxBleu_ == 0 && P.tauxVert_ != 0) {
		cout << 'G';

	}
	else if (P.tauxRouge_ == 0 && P.tauxVert_ == 0 && P.tauxBleu_ != 0) {
		cout << 'B';

	}
	/*
	// Optionnel, si on veut distinguer colore et completement noir

	else if (P.tauxRouge_ == 0 && P.tauxVert_ == 0 && P.tauxBleu_ == 0){
	cout <<'O';
	}
	*/
	else {
		cout << 'Q';
	}

//compare deux Pixels
bool Pixel::operator == (const Pixel & P){
	if (tauxRouge_ == P.tauxRouge_ && tauxVert_ == P.tauxVert && tauxBleu_ == P.tauxBleu)
		return true;
	else
		return false;
}

//compare Pixel à une couleur passée en paramètre char
bool Pixel::operator == (const char & C) {
	if (C == 'R') {
		if ((tauxVert_ == 0 && tauxBleu_ == 0 && tauxRouge_ != 0)
			return true;
		else
			return false;
	}
	
	else if (C == 'G') {
		if ((tauxRouge_ == 0 && tauxBleu_ == 0 && tauxVert_ != 0)
			return true;
		else
			return false;
	}

	else if (C == 'B') {
		if ((tauxVert_ == 0 && tauxRouge_ == 0 && tauxBleu_ != 0)
			return true;
		else
			return false;
	}
}

//inverse operateur précédent; compare couleur char à un Pixel passé en paramètre
bool Pixel::operator == (const Pixel & P) {

}

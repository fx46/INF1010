#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>

class Pixel
{
public:
	Pixel();
	~Pixel();

	Pixel(unsigned int tauxRouge,unsigned int tauxVert, unsigned int tauxBleu);

	void modifierTeinteRouge( int incrementRouge);
	void modifierTeinteVert( int incrementVert);
	void modifierTeinteBleu(int incrementBleu);

	unsigned int obtenirTauxRouge() const;
	unsigned int obtenirTauxVert() const;
	unsigned int obtenirTauxBleu() const;
		
	//  Remplacer cette méthode par char retournerCouleur() const;
	char retournerCouleur() const;

	// Ajouter les opérateurs
	friend std::ostream& operator<<(std::ostream& sortie, const Pixel& P);
	bool operator == (const Pixel & P);
	bool operator == (const char C);
	friend bool operator == (const char C, const Pixel & P);

private:
	unsigned int tauxRouge_ ;
	unsigned int tauxVert_;
	unsigned int tauxBleu_;
};

#endif
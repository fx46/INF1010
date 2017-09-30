#ifndef GROUPIMAGE_H
#define GROUPIMAGE_H
#include "Image.h"
#include <vector>

using namespace std;


class GroupImage
{
public:
	GroupImage(); // A modifier l'implementation
	~GroupImage(); // A modifier l'implementation

	void modifierType(const string &type);
	string obtenirType() const;

	// Modifier cette méthode par Image* obtenirImage(unsigned int indiceImage) const;
	Image* obtenirImage(unsigned int indiceImage) const;

	// Méthode à modifier avec void ajouterImage(Image* &image);
	void ajouterImage(Image &image);

	//  ajouter la methode pour retirer une image en donnant
	//son nom en paramètre
	void retirerImage(const string & name);
	// Méthode à modifier avec void afficherImages(ostream& os)
	void afficherImages(ostream& sortie) const;  
	

	void doublerTailleImageEnLargeur(unsigned int indiceImage);

	void doublerTailleImageEnHauteur(unsigned int indiceImage);
	
     
    // Ajouter les opérateurs 
	GroupImage & operator += (Image &I);
	GroupImage & operator -= (Image &I);
	friend ostream& operator<<(ostream& sortie, const GroupImage& G);

private:

	string type_;

	// Attributs à modifier 
	vector <Image*> images_;

};

#endif
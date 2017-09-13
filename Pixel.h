#ifndef PIXEL_H
#define PIXEL_H




class Pixel
{
public:
	Pixel();
	~Pixel();

	Pixel(unsigned int tauxRouge,unsigned int tauxVert, unsigned int tauxBleu);

	unsigned int getR();
	unsigned int getV();
	unsigned int getB();

	void modifierTeinteRouge( int incrementRouge);
	void modifierTeinteVert( int incrementVert);
	void modifierTeinteBleu(int incrementBleu);
		
	void afficherPixel() const;

private:
	unsigned int tauxRouge_ ;
	unsigned int tauxVert_;
	unsigned int tauxBleu_;
};

#endif
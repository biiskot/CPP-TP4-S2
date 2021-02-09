#pragma once
#include <iostream>
#include <vector>

class Ville {
public:
	double Distance2Villes(Ville v1, Ville v2);
	void setPos(int x, int y);
	int getPosX(int x);
	int getPosY(int y);
private:
	Ville(){}
	std::string nom;
	int posX = 0;
	int posY = 0;
};


void Ville::setPos(int x, int y) {
	this->posX = x;
	this->posY = y;
}

int Ville::getPosY(int y) {
	y = this->posY;
	return y;
}

int Ville::getPosX(int x) {
	x = this->posX;
	return x;
}

double Ville::Distance2Villes(Ville v1, Ville v2) {
	double distance = 0;
	distance = sqrt((v1.posX - v2.posX) ^ 2 + (v1.posY - v2.posY) ^ 2);
	return distance;
}

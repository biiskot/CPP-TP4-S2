#include <iostream>
#include <vector>
#include "classeVille.h"
#include <ctime>

constexpr int codeASCIIde_a = 97;
constexpr int codeASCIIde_A = 65;
constexpr int nombreDeLettres = 26;
constexpr int tailleMinNomVille = 4;
constexpr int tailleMaxNomVille = 12;
constexpr int grainePourLeRand = 1;
constexpr int nombreDeVilles = 4;
constexpr int nombreCombinaisons = 24;
constexpr int tailleCoteCarte = 100;

std::vector <std::string> Listvilles;


void remplirVec(Ville& ville, std::vector <Ville>& tab) {
	tab.push_back(ville);
}

void afficheVec(std::vector<std::string> v, int len) {
	for (int i = 0; i < len; i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

void Permutations(std::vector<std::string> &villes, int debut, int fin) {
	if (debut == fin) {
		afficheVec(villes,villes.size());
	}
	else {
		for (int i = 0; i <= fin; i++) {
			std::swap(villes[debut], villes[i]);
			Permutations(villes, debut + 1, fin);
			std::swap(villes[debut], villes[i]);
			
		}
	}

}

void genNomsVilles(std::vector<std::string> v) {
	int nbLettresNomVille = 0;
	std::string nomTmp;
	int N_to_C=0;
	std::string c;
	char num_char;
	for (int i = 0; i < nombreDeVilles; i++) {
		nbLettresNomVille = tailleMinNomVille + rand()​ % ​(tailleMaxNomVille​ - ​tailleMinNomVille​ + ​1​);
		for (int j = 0; j < nbLettresNomVille; j++) {
			N_to_C = rand();
			c = std::to_string(N_to_C);
			num_char = c.c_str(N_to_C);
			nomTmp[j] = num_char;
		}
		v.push_back(nomTmp);
	}
}

int main() {
	std::srand(grainePourLeRands);
	Permutations(Listvilles, 0, Listvilles.size() - 1);
}

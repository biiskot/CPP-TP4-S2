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

void afficheVec(std::vector<std::string> v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

//marche que pour 2 villes
void Permutations(std::vector<std::string> &villes, int debut, int fin) {
	if (debut == fin) {
		afficheVec(villes);
	}
	else {
		for (int i = 0; i <= fin; i++) {
			std::swap(villes[debut], villes[i]);
			Permutations(villes, debut + 1, fin);
			std::swap(villes[debut], villes[i]);
		}
	}

}

// A : 65
// a : 97

// int to ascii char
char convert(int nombre)
{
	return nombre + 'a' - 1;
}

char convertmaj(int nombre)
{
	return nombre + 'A' - 1;
}

void genNomsVilles(std::vector<std::string> &v) {
	int nbLettresNomVille = 0;
	int N_to_C=0;
	char C;
	std::string nom;
	for (int i = 0; i < nombreDeVilles; i++) {

		nbLettresNomVille = tailleMinNomVille + rand() % (tailleMaxNomVille - tailleMinNomVille + 1);

		for (int j = 0; j < nbLettresNomVille; j++) {
			if (j == 0) {
				N_to_C = rand() % 25 + 1;
				nom.push_back(convertmaj(N_to_C));
			}
			else {
				N_to_C = rand() % 25 + 1;
				nom.push_back(convert(N_to_C));
			}
		}
		std::cout << nom << std::endl;
		std::cout<<std::endl;
		v.push_back(nom);
		nom.resize(0);
	}
	std::cout << "vecteur des villes generees :" << std::endl;
	afficheVec(v);
}

int main() {
	std::srand(time(nullptr));
	Permutations(Listvilles, 0, Listvilles.size() - 1);
	genNomsVilles(Listvilles);
}

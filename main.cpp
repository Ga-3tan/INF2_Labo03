#include <iostream>
#include <vector>
#include "ParametresJeu.h"
#include "Carte.h"
#include "Joueur.h"

using namespace std;

void test(vector<Carte> b);

int main() {
    vector<Carte> cartesEnJeu;

    // Creer le jeu de cartes
    for (unsigned short i = 1; i <= NOMBRE_FAMILLES; ++i) {
        for (char c = 'A'; c < 'A' + CARTES_PAR_FAMILLE; ++c) {
            cartesEnJeu.emplace_back(i, c);
        }
    }

    for(const Carte& c : cartesEnJeu){
        cout << c << " ";
    }

    test(cartesEnJeu);

    return 0;
}

void test(vector<Carte> b) {
    Joueur a = Joueur("a");
    a.ajouterCarte(b.at(13));
    a.ajouterCarte(b.at(6));
    a.ajouterCarte(b.at(8));
    a.ajouterCarte(b.at(10));
    a.ajouterCarte(b.at(5));
    a.ajouterCarte(b.at(2));
    a.ajouterCarte(b.at(9));
    a.ajouterCarte(b.at(4));
    a.ajouterCarte(b.at(7));
    cout << a.detecterFamille() << endl;

    for(const Carte& c : a.getCartesEnMain()){
        cout << c << " ";
    }
    cout << endl;
}

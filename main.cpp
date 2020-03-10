#include <iostream>
#include <vector>
#include "ParametresJeu.h"
#include "Carte.h"

using namespace std;

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

    return 0;
}

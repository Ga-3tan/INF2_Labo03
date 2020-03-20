/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : main.cpp
 Auteur(s)   : Do Vale Lopes Miguel, Tevaearai Rébecca, Zwick Gaétan
 Date        : 06.03.2020

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : g++ 7.4.0
 -----------------------------------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "ParametresJeu.h"
#include "Partie.h"
#include "Joueur.h"
#include "MeilleurJoueur.h"
#include "Carte.h"

using namespace std;

// TODO toute la fct main()
int main() {


    const unsigned NB_PARTIES = 100;

    // Seed pour le random
    srand(time(NULL));

    // Test N parties
    for (size_t i = 0; i < NB_PARTIES; ++i) {
        // Liste des joueurs
        MeilleurJoueur j1("Alice");
        Joueur j2("Bobby");
        Joueur j3("Carol");
        Joueur j4("Danny");

        vector<Joueur*> listeJoueur = {&j1, &j2, &j3, &j4};

        //Cree la partie
        Partie partie(listeJoueur);

        //Lance la partie
        partie.startGame();
    }

    return 0;
}

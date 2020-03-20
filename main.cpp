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
#include <iomanip>
#include "ParametresJeu.h"
#include "Partie.h"
#include "Joueur.h"
#include "MeilleurJoueur.h"

using namespace std;

int main() {
    const unsigned NB_PARTIES = 1000;
    const int PRECISION_POURCENT = 2;

    // Seed pour le random
    srand(time(NULL));

    // Liste des joueurs
    MeilleurJoueur j1("Alice");
    Joueur j2("Bobby");
    Joueur j3("Carol");
    Joueur j4("Danny");
    vector<Joueur *> listeJoueurs = {&j1, &j2, &j3, &j4};

    // Test N parties
    for (size_t i = 0; i < NB_PARTIES; ++i) {

        //Cree la partie
        Partie partie(listeJoueurs);

        //Lance la partie
        partie.start();
    }

    // Affiche les scores après N parties
    Joueur *gagnant = listeJoueurs.front();
    cout << endl << "Scores apres " << NB_PARTIES << " parties : " << endl;
    for (const auto joueur : listeJoueurs) {
        cout << "-" << joueur->getNom() << " : " << joueur->getNbrDeFamilles() << " familles ("
             << fixed << setprecision(PRECISION_POURCENT)
             << (double) joueur->getNbrDeFamilles() / NOMBRE_FAMILLES / NB_PARTIES * 100
             << " % des familles)" << endl;
        if (joueur->getNbrDeFamilles() > gagnant->getNbrDeFamilles()) {
            gagnant = joueur;
        }
    }

    // Affiche le gagnant
    cout << "Le gagnant est : " << gagnant->getNom() << endl;

    return 0;
}

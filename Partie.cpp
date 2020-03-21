/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Partie.cpp
 Auteur(s)   : Do Vale Lopes Miguel, Tevaearai Rébecca, Zwick Gaétan
 Date        : 06.03.2020

 But         : Construire un système pouvant jouer au jeu des 7 familles

 Remarque(s) : - Fichier .cpp de la class Partie

 Compilateur : g++ 7.4.0
 -----------------------------------------------------------------------------------
*/
#include "Partie.h"
#include "ParametresJeu.h"
#include <random>
#include <algorithm>

using namespace std;

Partie::Partie(const vector<Joueur*>& listeJoueurs) : listeJoueurs(listeJoueurs) {}

void Partie::start() {
    // Reinitialise le nombre de tour
    nbTour = 0;

    // Cree le jeu de cartes
    vector<Carte> jeuCarte;
    for (unsigned short i = 1; i <= NOMBRE_FAMILLES; ++i) {
        for (char c = 'A'; c < 'A' + CARTES_PAR_FAMILLE; ++c) {
            jeuCarte.emplace_back(i, c);
        }
    }

    // Melange les cartes
    pioche = jeuCarte;
    random_shuffle(pioche.begin(), pioche.end());

    // Distribution des cartes
    for (Joueur *joueur : listeJoueurs) {
        for (unsigned i = 0; i < CARTES_PAR_JOUEUR; i++) {
            joueur->ajouterCarte(pioche.at(i));
        }
        pioche.erase(pioche.begin(), pioche.begin() + CARTES_PAR_JOUEUR);
    }

    // Boucle de jeu
    gameLoop();

    // Fin de partie
    end();
}


Joueur* Partie::choisirJoueur(const Joueur& demandeur) {
    // Liste des joueurs possibles
    vector<Joueur*> joueursPossible;
    for (const auto joueur : listeJoueurs) {
        if (!(*joueur == demandeur || joueur->mainVide())) {
            joueursPossible.push_back(joueur);
        }
    }
    // Retourne un joueur aleatoire
    Joueur* joueurChoisi = joueursPossible.at(rand() % joueursPossible.size());
    return *find(listeJoueurs.begin(), listeJoueurs.end(), joueurChoisi);
}

Carte Partie::piocherCarte() {
    Carte carte = pioche.back();
    pioche.pop_back();
    return carte;
}

void Partie::gameLoop() {
    while (!partieFinie()) {
        // Affiche le tour
//        afficherTour();

        // Chaque joueur tour a tour
        for (Joueur* joueurCourant : listeJoueurs) {
            if (!partieFinie()) {
                bool possedeCarte;
                do {
                    // Pose les familles si possible
                    joueurCourant->detecterFamille();

                    // Demande une carte s'il peut
                    possedeCarte = false;
                    if (!joueurCourant->mainVide()) {
                        // Choisi joueur et carte
                        Carte carteChoisi = joueurCourant->demanderCarte();
                        Joueur* joueurChoisi = choisirJoueur(*joueurCourant);
//                        cout << joueurCourant->getNom() << " demande a " << joueurChoisi->getNom()
//                             << " la carte " << carteChoisi << endl;

                        // Verifie et donne la carte si oui
                        possedeCarte = joueurChoisi->donnerCarte(*joueurCourant, carteChoisi);
//                        if (possedeCarte) {
//                            cout << "  et " << joueurChoisi->getNom() << " donne la carte a "
//                                 << joueurCourant->getNom() << endl;
//                        } else {
//                            cout << "  mais " << joueurChoisi->getNom() << " ne l'a pas" << endl;
//                        }
                    }

                } while (possedeCarte); // Rejoue si il a recu une carte

                // Pioche une carte
                if (!pioche.empty()) {
                    Carte cartePioche = piocherCarte();
//                    cout << joueurCourant->getNom() << " prend une carte dans la pioche (" << cartePioche << ")" << endl;
                    joueurCourant->ajouterCarte(cartePioche);
                    joueurCourant->detecterFamille();
                }
            } else {
                break;
            }
        }
    }
}

bool Partie::partieFinie() const {
    for (const auto joueur : listeJoueurs) {
        if (!joueur->mainVide()) {
            return false;
        }
    }
    return pioche.empty();
}

void Partie::end() {
//    for (const auto joueur : listeJoueurs) {
//        cout << joueur->getNom() << " : ";
//        for (Carte carte : joueur->getCartesEnMain()) {
//            cout << carte << "  ";
//        }
//        cout << "[";
//        for (Carte carte : joueur->getFamillesSurTable()) {
//            cout << carte << ".";
//        }
//        cout << "]" << endl;
//    }
//    cout << "Pioche : ";
//    for (Carte carte : pioche) {
//        cout << carte << " ";
//    }
//    cout << endl;
//
//    cout << "La partie est finie !" << endl;
//    cout << "Nombre de tours : " << nbTour << endl;

    // Vide la main et les familles posées des joueurs.
    for (Joueur* joueur : listeJoueurs) {
        joueur->viderCartes();
    }
}

void Partie::afficherTour() {
    cout << "*** Tour " << ++nbTour << " ***" << endl;
    for (const auto joueur : listeJoueurs) {
        cout << joueur->getNom() << " : ";
        for (Carte carte : joueur->getCartesEnMain()) {
            cout << carte << "  ";
        }
        cout << "[";
        for (Carte carte : joueur->getFamillesSurTable()) {
            cout << carte << ".";
        }
        cout << "]" << endl;
    }
    cout << "Pioche : ";
    for (const Carte &carte : pioche) {
        cout << carte << " ";
    }
    cout << endl;
}
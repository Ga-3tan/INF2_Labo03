/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Partie.cpp
 Auteur(s)   : Do Vale Lopes Miguel, Tevaearai Rébecca, Zwick Gaétan
 Date        : 06.03.2020

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : g++ 7.4.0
 -----------------------------------------------------------------------------------
*/
#include "Partie.h"
#include "ParametresJeu.h"
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

Partie::Partie(const vector<Joueur> &listeJoueurs) : listeJoueurs(listeJoueurs) {}

Carte Partie::piocherCarte() {
    Carte carte = *(pioche.end() - 1);
    pioche.pop_back();
    return carte;
}

// TODO peut être ameliorer...
Joueur &Partie::choisirJoueur(const Joueur &demandeur) {
    // Liste des joueurs possibles
    vector<Joueur> joueursPossible;
    for (const Joueur &joueur : listeJoueurs) {
        if (!(joueur == demandeur || joueur.mainVide())) {
            joueursPossible.push_back(joueur);
        }
    }
    // Retourne un joueur aleatoire
    Joueur &joueurChoisi = joueursPossible.at(rand() % joueursPossible.size());
    return *find(listeJoueurs.begin(), listeJoueurs.end(), joueurChoisi);
}

bool Partie::gameFinished() const {
    for (const Joueur &joueur : listeJoueurs) {
        if (!joueur.mainVide()) {
            return false;
        }
    }
    return pioche.empty();
}

//TODO Mettre au propre/ameliorer
bool Partie::gameLoop() {
    while (!gameFinished()) {
        // Affiche le tour
        afficherTour();

        // Chaque joueur tour a tour
        for (Joueur &joueurCourant : listeJoueurs) {
            if (!gameFinished()) {
                bool possedeCarte;
                do {
                    // Pose les familles si possible
                    joueurCourant.detecterFamille();

                    // Demande une carte s'il peut
                    possedeCarte = false;
                    if (!(joueurCourant.mainVide() && pioche.empty())) {

                        // Choisi joueur et carte
                        Carte carteChoisi = joueurCourant.demanderCarte();
                        Joueur& joueurChoisi = choisirJoueur(joueurCourant);
                        cout << joueurCourant.getNom() << " demande a " << joueurChoisi.getNom()
                             << " la carte " << carteChoisi << endl;

                        // Verifie et donne la carte si oui
                        possedeCarte = joueurChoisi.donnerCarte(joueurCourant, carteChoisi);
                        if(possedeCarte){
                            cout << "  et " << joueurChoisi.getNom() << " donne la carte a "
                                 << joueurCourant.getNom() << endl;
                        }else{
                            cout << "  mais " << joueurChoisi.getNom() << " ne l'a pas" << endl;
                        }
                    }
                } while (possedeCarte); // Rejoue si il a recu une carte

                // Pioche une carte
                if (!pioche.empty()) {
                    joueurCourant.ajouterCarte(piocherCarte());
                    joueurCourant.detecterFamille();
                }
            } else {

                //TODO Pas forcement utile, mais correspond à l'output du pdf
                for (const Joueur &joueur : listeJoueurs) {
                    cout << joueur.getNom() << " : ";
                    for (Carte carte : joueur.getCartesEnMain()) {
                        cout << carte << "  ";
                    }
                    cout << "[";
                    for (Carte carte : joueur.getFamillesSurTable()) {
                        cout << carte << ".";
                    }
                    cout << "]" << endl;
                }
                cout << "Pioche : ";
                for (Carte carte : pioche) {
                    cout << carte << " ";
                }
                cout << endl;
                break;
            }
        }
    }
    return false;
}

void Partie::startGame() {
    // Reinitialise le nombre de tour
    nbTour = 0;

    // Cree le jeu de cartes
    for (unsigned short i = 1; i <= NOMBRE_FAMILLES; ++i) {
        for (char c = 'A'; c < 'A' + CARTES_PAR_FAMILLE; ++c) {
            cartesEnJeu.emplace_back(i, c);
        }
    }

    // Melange les cartes
    pioche = cartesEnJeu;
    random_shuffle(pioche.begin(), pioche.end());

    // Distribution des cartes
    for (Joueur &joueur : listeJoueurs) {
        for (unsigned i = 0; i < CARTES_PAR_JOUEUR; i++) {
            joueur.ajouterCarte(pioche.at(i));
        }
        pioche.erase(pioche.begin(), pioche.begin() + CARTES_PAR_JOUEUR);
    }

    // Boucle de jeu
    gameLoop();

    // Fin de partie
    endGame();
}

// TODO A quoi sert le % ?
void Partie::endGame() {
    Joueur &gagnant = listeJoueurs.at(0); //TODO pensez a trier listeJoueur pour savoir le gagnant (pas tjr .at(0))
    gagnant.setNbrDePartiesGagnees(gagnant.getNbrDePartiesGagnees() + 1); //TODO on pt etre se debarasser des set..
    cout << "La partie est finie !" << endl;
    cout << "Nombre de tours : " << nbTour << endl;

    cout << "le gagnant est : " << gagnant.getNom() << endl;
    cout << "Scores : " << endl;
    for (const Joueur &joueur : listeJoueurs) {
        cout << "-" << joueur.getNom() << " : " << joueur.getNbrDeFamilles() << " familles ("
             << int((double) joueur.getNbrDeFamilles() / NOMBRE_FAMILLES * 100) << " % des familles)" << endl;
        if (joueur.getNbrDeFamilles() > gagnant.getNbrDeFamilles()) {
            gagnant = joueur;
        }
    }
}

void Partie::afficherTour() {
    cout << "*** Tour " << ++nbTour << " ***" << endl;
    for (const Joueur &joueur : listeJoueurs) {
        cout << joueur.getNom() << " : ";
        for (Carte carte : joueur.getCartesEnMain()) {
            cout << carte << "  ";
        }
        cout << "[";
        for (Carte carte : joueur.getFamillesSurTable()) {
            cout << carte << ".";
        }
        cout << "]" << endl;
    }
    cout << "Pioche : ";
    for (Carte carte : pioche) {
        cout << carte << " ";
    }
    cout << endl;
}

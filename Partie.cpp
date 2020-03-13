//
// Created by gaeta on 06.03.2020.
//

#include "Partie.h"
#include "ParametresJeu.h"
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

Joueur& Partie::getRandomPlayer() { return joueurs.at(rand() % joueurs.size()); }

bool Partie::gameFinished() const {
    for (const Joueur& joueur : joueurs) {
        if (!joueur.mainVide()) {
            return false;
        }
    }
    return pile.empty();
}

Carte Partie::piocherCarte() { return *pile.end(); }

bool Partie::gameLoop() {
    for (Joueur& joueur : joueurs) {
        if (!gameFinished()) {
            do {
                joueur.detecterFamille();
            } while (joueur.demanderCarte(getRandomPlayer()));
            if (!pile.empty()) {
                joueur.ajouterCarte(piocherCarte());
            }
            joueur.detecterFamille();
        } else {
            break;
        }
    }
    return gameFinished(); // return false si le jeu n'est pas fini
}

void Partie::startGame(vector<Joueur>& JoueurList) {
    // ajouter les joueurs
    joueurs = JoueurList;
    // Cree le jeu de cartes
    for (unsigned short i = 1; i <= NOMBRE_FAMILLES; ++i) {
        for (char c = 'A'; c < 'A' + CARTES_PAR_FAMILLE; ++c) {
            cartesEnJeu.emplace_back(i, c);
        }
    }

    // Melange les cartes
    vector<Carte> cartesDistrib = cartesEnJeu;
    shuffle( cartesDistrib.begin(), cartesDistrib.end(), mt19937(random_device()()));

    // Distribution des cartes
    for (Joueur &joueur : joueurs) {
        for (unsigned i = 0; i < CARTES_PAR_JOUEUR; i++) {
            joueur.ajouterCarte(cartesDistrib.at(i));
            cartesDistrib.erase(cartesDistrib.begin() + i);
        }
    }
    pile = cartesDistrib;

    // Boucle de jeu
    while (!gameLoop());
    endGame();
}

void Partie::endGame() {
    Joueur& gagnant = joueurs.at(0);
    cout << "Scores : " << endl;
    for (Joueur joueur : joueurs) {
        cout << "-" << joueur.getNom() << " : " << joueur.getNbrDeFamilles() << "familles ("
             << int(joueur.getNbrDeFamilles()/NOMBRE_FAMILLES*100) << " % des familles)" << endl;
        if ( joueur.getNbrDeFamilles() > gagnant.getNbrDeFamilles()) {
            gagnant = joueur;
        }
    }
    gagnant.setNbrDePartiesGagnees(gagnant.getNbrDePartiesGagnees()+1);
    cout << "le gagnant est : " << gagnant.getNom() << endl;
    cout << "Partie finie";
}

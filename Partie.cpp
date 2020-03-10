//
// Created by gaeta on 06.03.2020.
//

#include <cstdlib>
#include "Partie.h"
#include "ParametresJeu.h"

Joueur& Partie::getRandomPlayer() {
    return joueurs.at(rand() % joueurs.size());
}

bool Partie::gameFinished() {
    for (Joueur joueur : joueurs) {
        if (!joueur.mainVide()) {
            return false;
        }
    }
    return pile.empty();
}

Carte Partie::pickCardFromPile() {
    return *pile.end();
}

bool Partie::gameLoop() {
    for (Joueur& joueur : joueurs) {
        if (!gameFinished()) {
            do {
                joueur.detecterFamille();
            } while (joueur.demanderCarte(getRandomPlayer()));
            if (!pile.empty()) {
                joueur.ajouterCarte(pickCardFromPile());
            }
            joueur.detecterFamille();
        } else {
            break;
        }
    }
    return !gameFinished();
}

void Partie::startGame() {
    // Creer le jeu de cartes
    for (unsigned short i = 1; i <= NOMBRE_FAMILLES; ++i) {
        for (char c = 'A'; c < 'A' + CARTES_PAR_FAMILLE; ++c) {
            cartesEnJeu.emplace_back(i, c);
        }
    }

    bool game;
    do {
        game = gameLoop();
    } while (game);
}

void Partie::endGame() {

}

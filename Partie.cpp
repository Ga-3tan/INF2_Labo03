//
// Created by gaeta on 06.03.2020.
//

#include <cstdlib>
#include "Partie.h"

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

Carte Partie::pickCardFromPile(std::vector<Carte> pileDeCarte) {
    return *pileDeCarte.end();
}

bool Partie::gameLoop() {
    for (Joueur &joueur : joueurs) {
        if (!gameFinished()) {
            do {
                joueur.detecterFamille();
            } while (joueur.demanderCarte(getRandomPlayer())); // demanderCarte retourne false si le joueur pioche dans la pile
            joueur.detecterFamille();
        }
    }

    return !gameFinished();
}

void Partie::startGame() {
    bool game;
    do {
        game = gameLoop();
    } while (game);
}

void Partie::endGame() {

}

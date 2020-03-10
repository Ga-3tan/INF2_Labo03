//
// Created by gaeta on 06.03.2020.
//

#include <c++/4.8.3/cstdlib>
#include "Partie.h"

Joueur Partie::getRandomPlayer() {
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
    for (Joueur joueur : joueurs) {
        if (!gameFinished()) {
            //        do {} while (joueur.detecterFamille()); // en fin de tour le joueur vérifie s'il a des famille a poser
            joueur.demanderCarte();
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

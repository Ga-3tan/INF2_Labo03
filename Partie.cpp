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
        if (!gameFinished()) { // TODO peut-être à retirer
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
    bool game;
    // Creer le jeu de cartes
    for (unsigned short i = 1; i <= NOMBRE_FAMILLES; ++i) {
        for (char c = 'A'; c < 'A' + CARTES_PAR_FAMILLE; ++c) {
            cartesEnJeu.emplace_back(i, c);
        }
    }
    // Distribution des cartes
    for (Joueur joueur : joueurs) {
        for (unsigned i = 0; i < CARTES_PAR_JOUEUR; i++) {
            auto tmp = rand() % cartesEnJeu.size(); // TODO à enlever si on mélange le tas avant
            joueur.ajouterCarte(cartesEnJeu.at(tmp));
            cartesEnJeu.erase(cartesEnJeu.begin()+tmp);
        }
    }
    pile = cartesEnJeu; // TODO à mélanger si on mélange ne mélange pas avant
    do {
        game = gameLoop();
    } while (game);
}

// TODO TO FINISH
void Partie::endGame() {
    Joueur& gagnant = joueurs.at(0);
    for (Joueur joueur : joueurs) {
        // TODO COMPTER LES NOMBRES DE FAMILLES AVEC LA VARIABLE FAMILLE_POSEE ET LES RAJOUTER AU SCORE
        if ( NOMBRE_DE_FAMILLE_DU_JOUEUR > gagnant.NOMBRE_DE_FAMILLE) {
            gagnant = joueur;
        }
    }
    std::cout << "le gagnant est : " << gagnant.getNom() << endl;
}

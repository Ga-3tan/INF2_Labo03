//
// Created by gaeta on 06.03.2020.
//

#ifndef INF2_LABO03_PARTIE_H
#define INF2_LABO03_PARTIE_H

#include <vector>
#include "Joueur.h"
#include "Carte.h"


class Partie {
private:
    std::vector<Joueur> joueurs;
    std::vector<Carte> cartesEnJeu; //sera mis a jour en debut de partie et à chaque famille compléter
    std::vector<Carte> pile;
    bool gameIsFinished;

public:
    bool gameFinished();
    Carte pickCardFromPile(std::vector<Carte> pileDeCarte);
    Joueur getRandomPlayer();
    void startGame();
    bool gameLoop();
    void endGame();

};


#endif //INF2_LABO03_PARTIE_H

//
// Created by gaeta on 06.03.2020.
//

#ifndef INF2_LABO03_PARTIE_H
#define INF2_LABO03_PARTIE_H

#include <vector>
#include "Joueur.h"
#include "Carte.h"


class Partie {
    friend std::vector<Carte> getJeuCartes();

public:
    bool gameFinished() const;
    Carte piocherCarte();
    Joueur& getRandomPlayer();
    void startGame();
    bool gameLoop();
    void endGame();


private:
    std::vector<Joueur> joueurs;
    std::vector<Carte> pile;
    std::vector<Carte> cartesEnJeu;
    bool gameIsFinished;
};


#endif //INF2_LABO03_PARTIE_H

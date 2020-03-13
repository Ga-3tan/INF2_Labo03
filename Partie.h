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
    void startGame(std::vector<Joueur>& JoueurList);
    bool gameLoop();
    void endGame();
    void afficherTour();


private:
    std::vector<Joueur> joueurs;
    std::vector<Carte> pile;
    std::vector<Carte> cartesEnJeu;
    bool gameIsFinished;
    unsigned nbTour = 0;
};


#endif //INF2_LABO03_PARTIE_H

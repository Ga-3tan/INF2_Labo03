/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Partie.h
 Auteur(s)   : Do Vale Lopes Miguel, Tevaearai Rébecca, Zwick Gaétan
 Date        : 06.03.2020

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : g++ 7.4.0
 -----------------------------------------------------------------------------------
*/
#ifndef PARTIE_H
#define PARTIE_H

#include <vector>
#include "Joueur.h"
#include "Carte.h"

class Partie {

public:
    /**
     * @brief Constructeur à 1 argument
     * @param listeJoueurs la liste de Joueur de la partie
     */
    Partie(const std::vector<Joueur*>& listeJoueurs);

    /**
     * @brief Pioche une carte de la pile
     * @return une carte de type Carte
     * @warning Verifiez que la pile ne soit pas vide avant de piocher !
     */
    Carte piocherCarte();

    /**
     * @brief Choisi un joueur aléatoirement
     * @param demandeur le joueur qui demande une carte
     * @return un autre joueur qui n'a pas de main vide
     */
    Joueur* choisirJoueur(const Joueur& demandeur);

    //TODO Franciser les nom (si necessaire) + doxygen
    bool gameFinished() const;
    void startGame();
    bool gameLoop();
    void endGame();

    //TODO la partie affichage + doxygen
    void afficherTour();


private:
    std::vector<Joueur*> listeJoueurs;
    std::vector<Carte> pioche;
    std::vector<Carte> cartesEnJeu; //TODO Pour le moment, on laisse mais peut être enlever plus tard
    unsigned nbTour; // mis à 0 dans le start game (eviter les init ici)
};


#endif //PARTIE_H
/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Partie.h
 Auteur(s)   : Do Vale Lopes Miguel, Tevaearai Rébecca, Zwick Gaétan
 Date        : 06.03.2020

 But         : Construire un système pouvant jouer au jeu des 7 familles

 Remarque(s) : - Fichier header de la class Partie qui gère l'organisation du jeu

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
     * @brief Lance le jeu
     */
    void start();

private:
    std::vector<Joueur*> listeJoueurs;
    std::vector<Carte> pioche;
    unsigned nbTour;

    /**
     * @brief Choisi un joueur aléatoirement
     * @param demandeur le joueur qui demande une carte
     * @return un pointeur sur un autre joueur qui n'a pas de main vide
     */
    Joueur* choisirJoueur(const Joueur& demandeur);

    /**
     * @brief Pioche une carte de la pile
     * @return une carte de type Carte
     * @warning Verifiez que la pile ne soit pas vide avant de piocher !
     */
    Carte piocherCarte();

    /**
     * @brief Boucle du jeu, gere la pioche et organise le jeu
     * @details Donne le tour à chaque joueur et tire au
                hasard le joueur à qui on demande des cartes
     */
    void gameLoop();

    /**
     * @brief Detecte la fin de partie
     * @return un booléen, true si la partie est finie
     */
    bool partieFinie() const;

    /**
     * @brief Affichage de fin de partie et reinitialisation des mains
     */
    void end();

    /**
     * @brief Affichage du tour
     */
    void afficherTour();
};


#endif //PARTIE_H
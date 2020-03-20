/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : MeilleurJoueur.h
 Auteur(s)   : Do Vale Lopes Miguel, Tevaearai Rébecca, Zwick Gaétan
 Date        : 06.03.2020

 But         : Construire un système pouvant jouer au jeu des 7 familles

 Remarque(s) : - Fichier header de la class MeilleurJoueur, cette classe est une
                 "fille" de la class "mère" Joueur. (class dérivée)

 Compilateur : g++ 7.4.0
 -----------------------------------------------------------------------------------
*/
#ifndef MEILLEURJOUEUR_H
#define MEILLEURJOUEUR_H

#include "Joueur.h"

class MeilleurJoueur : public Joueur{

public:
    /**
     * @brief Constructeur à 1 argument
     * @param nom le nom du joueur
     */
    MeilleurJoueur(const std::string& nom);

    /**
     * @brief Choisi une carte à demander
     * @return la carte choisie
     * @warning Verifiez que la main du joueur ne soit pas vide avant de demander !
     *          Les cartes en mains doivent être triées !
     * @details Stratégie : choix de la famille la plus nombreuse
     */
    Carte demanderCarte() const;
};


#endif //MEILLEURJOUEUR_H
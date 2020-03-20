/*
 -----------------------------------------------------------------------------------
 Laboratoire : 00
 Fichier     : MeilleurJoueur.h
 Auteur(s)   : Miguel Do Vale Lopes
 Date        : 20.03.2020

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : g++ 7.4.0
 -----------------------------------------------------------------------------------
*/

#ifndef INF2_LABO03_MEILLEURJOUEUR_H
#define INF2_LABO03_MEILLEURJOUEUR_H

#include "Joueur.h"

class MeilleurJoueur : public Joueur{

public:
    MeilleurJoueur(const std::string& nom);
    Carte demanderCarte() const;

protected:
    //Aucune idée pour le moment
};


#endif //INF2_LABO03_MEILLEURJOUEUR_H

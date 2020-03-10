/* ---------------------------
Laboratoire : 03
Fichier :
Auteur(s) : Rébecca Tevaearai, Gaeta, Miguela
Date : 06.03.2020

But :

Remarque(s) :

Compilateur : gcc

--------------------------- */

#include "Joueur.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Joueur::demanderCarte(Joueur& joueur) {





   //cherche la famille la plus remplie possédée
   //demande la carte choisie au pelo d'en face
   //si il l'a, prend la carte et la met dans sa main
   //sinon, schade
   //verifie si il a une famille pleine

}
bool Joueur::detecterFamille() {

    //verfifier vide
}
Joueur::Joueur(string nom) : nom(nom) {}

bool Joueur::mainVide() {
    if(cartesEnMain.empty())
        return true;
}

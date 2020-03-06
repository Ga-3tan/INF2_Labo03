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

void Joueur::demanderCarte() {

   //cherche la famille la plus remplie possédée
   //donner un numero de carte non-possédée

}
void Joueur::detecterFamille() {

    //verfifier vide
}
Joueur::Joueur(string nom) : nom(nom) {}

bool Joueur::mainVide() {
    if(cartesEnMain.empty())
        return true;
}

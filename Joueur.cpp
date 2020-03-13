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
#include <algorithm>

using namespace std;

void Joueur::ajouterCarte(Carte carte) {
    cartesEnMain.push_back(carte);
}

Carte Joueur::prendreCarte(Carte carte) {
//    if(find(cartesEnMain.begin(), cartesEnMain.end(), carte)){
//
//        return carte;
//    }
}

bool Joueur::demanderCarte(Joueur& joueurAdverse) {
    //vecteur static
    //choisis random carte c

//    ajouterCarte(joueurAdverse.prendreCarte(c));


   //cherche la famille la plus remplie possédée
   //demande la carte choisie au pelo d'en face
   //si il l'a, prend la carte et la met dans sa main
   //sinon, schade
   //verifie si il a une famille pleine

}
bool Joueur::detecterFamille() {
    //carte en main triée
    sort(cartesEnMain.begin(), cartesEnMain.end());
    unsigned short current = cartesEnMain.begin()->getFamille();
    unsigned cnt = 0;
    unsigned first = 0;
    for (unsigned i = 0; i < cartesEnMain.size(); i++) {
        if (current == cartesEnMain.at(i).getFamille()) {
            cnt++;
        } else {
            cnt = 1;
            current = cartesEnMain.at(i).getFamille();
            first = i;
        }
        if (cnt == 4) {
            //mettre la famille sur la table et les supprimer de la main
            famillesSurTable.insert(famillesSurTable.end(), cartesEnMain.begin() + first, cartesEnMain.begin() + first + 4);
            cartesEnMain.erase(cartesEnMain.begin() + first, cartesEnMain.begin() + first + 4);

            //TODO INCREMENTER LE NOMBRE DE FAMILLES POSÉE
            return true;
        }
    }
}
Joueur::Joueur(string nom) : nom(nom) {}

bool Joueur::mainVide() {
    if(cartesEnMain.empty())
        return true;
}

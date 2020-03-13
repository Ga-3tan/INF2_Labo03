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
#include "ParametresJeu.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Joueur::ajouterCarte(const Carte& carte) {
    cartesEnMain.push_back(carte);
}

Carte Joueur::prendreCarte(Carte carte) {
//    if(find(cartesEnMain.begin(), cartesEnMain.end(), carte)){
//
//        return carte;
//    }
}

bool Joueur::demanderCarte(Joueur &joueurAdverse) {
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
    // Trie les cartes en mains
    sort(cartesEnMain.begin(), cartesEnMain.end());

    // Verifie la main
    unsigned compteur = 0;
    unsigned debut = 0;
    unsigned short familleCourante = cartesEnMain.front().getFamille();
    for (size_t i = 0; i < cartesEnMain.size(); i++) {
        if (cartesEnMain.at(i).getFamille() == familleCourante) {
            compteur++;
        } else {
            compteur = 1;
            familleCourante = cartesEnMain.at(i).getFamille();
            debut = i;
        }

        if (compteur == CARTES_PAR_FAMILLE) {
            // Pose la famille
            famillesSurTable.insert(famillesSurTable.end(), cartesEnMain.begin() + debut,
                                    cartesEnMain.begin() + debut + CARTES_PAR_FAMILLE);
            // Supprime la famille de la main
            cartesEnMain.erase(cartesEnMain.begin() + debut,cartesEnMain.begin() + debut + CARTES_PAR_FAMILLE);
            //incrémente la donnée membre nbrDeFamille
            ++nbrDeFamille;
            return true;
        }
    }
    return false;
}

unsigned Joueur::getNbrDeFamille() {
    return this->nbrDeFamille;
}

Joueur::Joueur(string nom) : nom(nom), nbrDeFamille(0) {}

bool Joueur::mainVide() { return cartesEnMain.empty(); }

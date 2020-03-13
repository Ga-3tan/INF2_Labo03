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
#include "Partie.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


Joueur::Joueur(string nom) : nom(nom) {}

unsigned Joueur::getNbrDeFamilles() {
    return nbrDeFamilles;
}

unsigned Joueur::getNbrDePartiesGagnees() {
    return nbrDePartiesGagnees;
}

void Joueur::setNbrDeFamilles(unsigned i) {
    nbrDeFamilles = i;
}

void Joueur::setNbrDePartiesGagnees(unsigned i) {
    nbrDePartiesGagnees = i;
}

void Joueur::ajouterCarte(const Carte &carte) {
    cartesEnMain.push_back(carte);
}

Carte Joueur::prendreCarte(const Carte &carte) {
//    if(find(cartesEnMain.begin(), cartesEnMain.end(), carte)){
//
//        return carte;
//    }
}

Carte Joueur::demanderCarte(Joueur &joueurAdverse, vector<Carte> cartesDispo) {
    for (const Carte& c : cartesEnMain) {
        cartesDispo.erase(remove_if(cartesDispo.begin(), cartesDispo.end(), c), cartesDispo.end());
    }

    // Demande une carte aleatoirement
    return cartesDispo.at(rand() % cartesDispo.size());
}


bool Joueur::detecterFamille(vector<Carte> &cartesEnJeu) {
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
            // Supprime la famille de la main et du jeu en cours
            cartesEnMain.erase(cartesEnMain.begin() + debut, cartesEnMain.begin() + debut + CARTES_PAR_FAMILLE);
            cartesEnJeu.erase(cartesEnJeu.begin() + debut, cartesEnJeu.begin() + debut + CARTES_PAR_FAMILLE);

            // +1 famille au joueur
            ++nbrDeFamilles;
            return true;
        }
    }
    return false;
}

bool Joueur::mainVide() const { return cartesEnMain.empty(); }
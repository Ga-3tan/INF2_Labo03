/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Joueur.cpp
 Auteur(s)   : Do Vale Lopes Miguel, Tevaearai Rébecca, Zwick Gaétan
 Date        : 06.03.2020

 But         : Construire un système pouvant jouer au jeu des 7 familles

 Remarque(s) : - Fichier .cpp de la class Joueur

 Compilateur : g++ 7.4.0
 -----------------------------------------------------------------------------------
*/
#include "Joueur.h"
#include "ParametresJeu.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

Joueur::Joueur(const string& nom) : nom(nom), nbFamilles(0) {}

bool Joueur::operator==(const Joueur& joueur2) const {
    return this->nom == joueur2.nom;
}

std::string Joueur::getNom() const { return nom; }

std::vector<Carte> Joueur::getCartesEnMain() const { return cartesEnMain; }

std::vector<Carte> Joueur::getFamillesSurTable() const { return famillesSurTable; }

unsigned Joueur::getNbFamilles() const{ return nbFamilles; }

void Joueur::ajouterCarte(const Carte& carte) { cartesEnMain.push_back(carte); }

Carte Joueur::demanderCarte() const {
    // Choix de famille aleatoire
    unsigned short choixFamille = cartesEnMain.at(rand() % cartesEnMain.size()).getFamille();

    // Genere les cartes possibles
    vector<Carte> cartesPossibles;
    for (char c = 'A'; c < 'A' + CARTES_PAR_FAMILLE; ++c) {
        cartesPossibles.emplace_back(choixFamille, c);
    }

    // Supprime les cartes presentes dans la main
    for (const Carte& c : cartesEnMain) {
        auto position = find(cartesPossibles.begin(), cartesPossibles.end(), c);
        if (position != cartesPossibles.end()) {
            cartesPossibles.erase(position);
        }
    }

    // Choix de carte aleatoire
    return cartesPossibles.at(rand() % cartesPossibles.size());
}

bool Joueur::donnerCarte(Joueur& demandeur, const Carte& carte) {
    auto itCarte = find(cartesEnMain.begin(), cartesEnMain.end(), carte);
    if(itCarte == cartesEnMain.end()){
        return false;
    } else{
        demandeur.ajouterCarte(carte);
        cartesEnMain.erase(itCarte);
        return true;
    }
}

void Joueur::detecterFamille() {
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
            cartesEnMain.erase(cartesEnMain.begin() + debut, cartesEnMain.begin() + debut + CARTES_PAR_FAMILLE);

            // Incremente le nombre de famille
            ++nbFamilles;
            return;
        }
    }
}

bool Joueur::mainVide() const { return cartesEnMain.empty(); }

void Joueur::viderCartes() {
    cartesEnMain.clear();
    famillesSurTable.clear();
}
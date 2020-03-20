/*
 -----------------------------------------------------------------------------------
 Laboratoire : 00
 Fichier     : MeilleurJoueur.cpp
 Auteur(s)   : Miguel Do Vale Lopes
 Date        : 20.03.2020

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : g++ 7.4.0
 -----------------------------------------------------------------------------------
*/

#include "MeilleurJoueur.h"
#include "ParametresJeu.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

MeilleurJoueur::MeilleurJoueur(const std::string &nom) : Joueur(nom) {}


// /!\ Les cartes en mains doivent être triées
Carte MeilleurJoueur::demanderCarte() const {

    // Choix de famille qu'il possède le plus
    unsigned compteurPresent = 0;
    unsigned compteurPasse = 0;
    unsigned short familleCourante = cartesEnMain.front().getFamille();
    unsigned short choixFamille;
    for (auto carte : cartesEnMain) {
        if (carte.getFamille() == familleCourante) {
            compteurPresent++;
        } else {
            compteurPresent = 1;
            familleCourante = carte.getFamille();
        }
        if (compteurPresent > compteurPasse) {
            compteurPasse = compteurPresent;
            choixFamille = familleCourante;
        }
    }

    // Genere les cartes possibles
    vector<Carte> cartesPossibles;
    for (char c = 'A'; c < 'A' + CARTES_PAR_FAMILLE; ++c) {
        cartesPossibles.emplace_back(choixFamille, c);
    }

    // Supprime les cartes presentes dans la main
    for (const Carte &c : cartesEnMain) {
        auto position = find(cartesPossibles.begin(), cartesPossibles.end(), c);
        if (position != cartesPossibles.end()) {
            cartesPossibles.erase(position);
        }
    }

    // Choix de carte aleatoire
    return cartesPossibles.at(rand() % cartesPossibles.size());
}
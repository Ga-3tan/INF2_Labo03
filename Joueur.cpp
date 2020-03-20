/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Joueur.cpp
 Auteur(s)   : Do Vale Lopes Miguel, Tevaearai Rébecca, Zwick Gaétan
 Date        : 06.03.2020

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : g++ 7.4.0
 -----------------------------------------------------------------------------------
*/
#include "Joueur.h"
#include "ParametresJeu.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


Joueur::Joueur(const string& nom) : nom(nom) {
    nbFamilles = 0;
    nbVictoires = 0;
}

unsigned Joueur::getNbrDeFamilles() const{ return nbFamilles; }

unsigned Joueur::getNbrDePartiesGagnees() const{ return nbVictoires; }

void Joueur::setNbrDeFamilles(unsigned i) { nbFamilles = i; }

void Joueur::setNbrDePartiesGagnees(unsigned i) { nbVictoires = i; }

void Joueur::ajouterCarte(const Carte& carte) {
    cartesEnMain.push_back(carte);
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

// TODO  ajouter warning a doxygen: " /!\ Verifier que la main du joueur n'est pas vide "
Carte Joueur::demanderCarte() const {
    // Choix de famille aleatoire
    unsigned short choixFamille = cartesEnMain.at(rand() % cartesEnMain.size()).getFamille();

    // Genere les cartes possibles
    vector<Carte> cartesPossibles;
    for (char c = 'A'; c < 'A' + CARTES_PAR_FAMILLE; ++c) {
        cartesPossibles.emplace_back(choixFamille, c);
    }

    // Supprime les cartes presentes dans la main
    for (const Carte &c : cartesEnMain) {
        auto itCarte = find(cartesPossibles.begin(), cartesPossibles.end(), c);
        if (itCarte != cartesPossibles.end()) {
            cartesPossibles.erase(itCarte);
        }
    }

    // Choix de carte aleatoire
    return cartesPossibles.at(rand() % cartesPossibles.size());
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
            cartesEnMain.erase(cartesEnMain.begin() + debut, cartesEnMain.begin() + debut + CARTES_PAR_FAMILLE);

            //incrémente la variable
            ++nbFamilles;
            return true;
        }
    }
    return false;
}

bool Joueur::mainVide() const { return cartesEnMain.empty(); }

std::string Joueur::getNom() const { return nom; }

bool Joueur::operator==(const Joueur& joueur2) const {
    return this->nom == joueur2.nom;
}

void Joueur::videTout() {
    cartesEnMain.clear();
    famillesSurTable.clear();
}

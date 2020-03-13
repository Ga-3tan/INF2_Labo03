/* ---------------------------
Laboratoire : 03
Fichier :
Auteur(s) : Rébecca Tevaearai, Gaeta, Miguela
Date : 06.03.2020

But :

Remarque(s) :

Compilateur : gcc

--------------------------- */

#ifndef INF2_LABO03_JOUEUR_H
#define INF2_LABO03_JOUEUR_H

#include "Carte.h"
#include <vector>
#include <string>


class Joueur {
public:
    void ajouterCarte(const Carte& carte);
    Carte prendreCarte(const Carte& carte);
    void setNbrDeFamilles(unsigned i);
    void setNbrDePartiesGagnees(unsigned i);
    unsigned getNbrDeFamilles();
    unsigned getNbrDePartiesGagnees();
    bool demanderCarte(Joueur& joueurAdverse);
    bool detecterFamille();
    bool mainVide() const;
    std::string getNom();
    Joueur(std::string nom);
    std::vector<Carte> getCartesEnMain() {
        return cartesEnMain;
    }
    std::vector<Carte> getFamillesSurTable() {
        return famillesSurTable;
    }

private:
    std::vector<Carte> cartesEnMain;
    std::vector<Carte> famillesSurTable;
    std::string nom;
    unsigned nbrDeFamilles;
    unsigned nbrDePartiesGagnees;
};


#endif //INF2_LABO03_JOUEUR_H

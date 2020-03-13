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
#include "Partie.h"

class Joueur {
public:
    void ajouterCarte(const Carte& carte);
    Carte prendreCarte(Carte carte);
    unsigned getNbrDeFamille();
    bool demanderCarte(Joueur& joueurAdverse);
    bool detecterFamille();
    bool mainVide();
    Joueur(std::string nom);
    std::vector<Carte> getCartesEnMain() {
        return cartesEnMain;
    }

private:
    std::vector<Carte> cartesEnMain;
    std::vector<Carte> famillesSurTable;
    std::string nom;
    unsigned nbrDeFamille;
    };


#endif //INF2_LABO03_JOUEUR_H

/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Joueur.h
 Auteur(s)   : Do Vale Lopes Miguel, Tevaearai Rébecca, Zwick Gaétan
 Date        : 06.03.2020

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : g++ 7.4.0
 -----------------------------------------------------------------------------------
*/
#ifndef JOUEUR_H
#define JOUEUR_H

#include "Carte.h"
#include <vector>
#include <string>


class Joueur {
public:
    //TODO Mettre au propre tt ces fonctions (nom trop long ou fct inutile) + Doxygen
    void ajouterCarte(const Carte& carte);
    void setNbrDeFamilles(unsigned i);
    void setNbrDePartiesGagnees(unsigned i);
    unsigned getNbrDeFamilles() const;
    unsigned getNbrDePartiesGagnees() const;
    Carte demanderCarte() const;
    bool donnerCarte(Joueur& demandeur, const Carte& carte);
    bool detecterFamille();
    bool mainVide() const;
    std::string getNom() const;
    Joueur(std::string nom);
    std::vector<Carte> getCartesEnMain() const {
        return cartesEnMain;
    }
    std::vector<Carte> getFamillesSurTable() const {
        return famillesSurTable;
    }

    bool operator== (const Joueur& joueur2) const;

private:
    std::vector<Carte> cartesEnMain;
    std::vector<Carte> famillesSurTable;
    std::string nom;
    unsigned nbFamilles;
    unsigned nbVictoires;
};


#endif //JOUEUR_H
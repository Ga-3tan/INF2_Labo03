/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Joueur.h
 Auteur(s)   : Do Vale Lopes Miguel, Tevaearai Rébecca, Zwick Gaétan
 Date        : 06.03.2020

 But         : Construire un système pouvant jouer au jeu des 7 familles

 Remarque(s) : - Fichier header de la class Joueur qui gère la mains et les
                 familles sur table du joueur.

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
    /**
     * @brief Constructeur à 1 argument
     * @param nom le nom du joueur de type string
     */
    Joueur(const std::string& nom);

    /**
     * @brief Compare le nom des joueurs
     * @param joueur2 le 2eme joueur à comparer
     * @return un booléen, true si les noms sont les memes
     */
    bool operator== (const Joueur& joueur2) const;

    /**
     * @brief Retourne le nom du joueur
     * @return le nom de type string
     */
    std::string getNom() const;

    /**
     * @brief Retourne les cartes en mains du joueur
     * @return un vector de Carte contenant la main du joueur
     */
    std::vector<Carte> getCartesEnMain() const;

    /**
     * @brief Retourne les familles posées du joueur
     * @return un vector de Carte contenant les cartes posées
     */
    std::vector<Carte> getFamillesSurTable() const;

    /**
     * @brief Retourne le nombre de famille du joueur
     * @return le nombre de type unsigned
     */
    unsigned getNbFamilles() const;


    /**
     * @brief Ajoute la carte dans la main du joueur
     * @param carte carte à ajouter de type Carte
     */
    void ajouterCarte(const Carte& carte);

    /**
     * @brief Choisi une carte à demander
     * @return la carte choisie
     * @warning Verifiez que la main du joueur ne soit pas vide avant de demander !
     * @details Stratégie : choix aléatoire
     */
    virtual Carte demanderCarte() const;

    /**
     * @brief Donne la carte choisie au demandeur
     * @param demandeur le joueur qui fait la demande
     * @param carte la carte choisie
     * @return un booléen, true si le joueur possède la carte sinon false
     */
    bool donnerCarte(Joueur& demandeur, const Carte& carte);

    /**
     * @brief Detecte si le joueur possède une famille et la pose cas échéant
     */
    void detecterFamille();

    /**
     * @brief Verifie si la main du joueur est vide
     * @return un booléen, true si elle est vide
     */
    bool mainVide() const;

    /**
     * @brief Vide les cartes en main et les familles sur tables du joueur
     */
    void viderCartes();

protected:
    std::vector<Carte> cartesEnMain;
    std::vector<Carte> famillesSurTable;
    std::string nom;
    unsigned nbFamilles;
};


#endif //JOUEUR_H
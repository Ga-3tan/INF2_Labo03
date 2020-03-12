/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Carte.h
 Auteur(s)   : Miguel Do Vale Lopes
 Date        : 06.03.2020

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : g++ 7.4.0
 -----------------------------------------------------------------------------------
*/

#ifndef INF2_LABO03_CARTE_H
#define INF2_LABO03_CARTE_H

#include <iostream>

class Carte {

    /**
     * @brief Surcharge d'operateur de flux (<<), permet l'affichage d'une carte.
     * @param lhs le flux ostream
     * @param rhs la carte à afficher
     * @return le nouveau flux ostream
     * @details Format: (unsigned short)famille (char)membre,
     *          Exemple: famille 2, membre C -> "2C"
     */
    friend std::ostream& operator<< (std::ostream& lhs, const Carte& rhs);

    /**
     * @brief Surcharge d'operateur du comparateur <, permet de comparer deux familles de carte.
     * @param lhs première Carte
     * @param rhs deuxième Carte
     * @return lhs < rhs
     */
    friend bool operator< (const Carte& lhs, const Carte& rhs);

public:

    /**
     * @brief Constructeur à deux arguments
     * @param famille la famille de carte de type unsigned short
     * @param membre le membre de la carte de type char
     */
    Carte(unsigned short famille, char membre);

    /**
     * @brief Compare la famille des deux carte
     * @param carte la carte à comparer de type Carte
     * @return un booléen, true si les familles sont les mêmes
     */
    bool operator== (const Carte& carte) const;

    /**
     * @brief Retourne la famille de la carte
     * @return un unsigned short correspondant à la famille
     */
    unsigned short getFamille() const;

    /**
     * @brief Retourne le membre de la carte
     * @return un char correspondant au membre
     */
    char getMembre() const;

private:
    unsigned short famille;
    char membre;
};


#endif //INF2_LABO03_CARTE_H
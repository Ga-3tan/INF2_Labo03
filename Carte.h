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

public:

    /**
     * @brief Compare la famille des deux carte
     * @param carte la carte à comparer de type Carte
     * @return un booléen, true si les familles sont les mêmes
     */
    bool operator== (const Carte& carte) const;

private:
    unsigned short famille;
    char membre;
};


#endif //INF2_LABO03_CARTE_H
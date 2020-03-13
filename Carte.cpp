/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : Carte.cpp
 Auteur(s)   : Miguel Do Vale Lopes
 Date        : 06.03.2020

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : g++ 7.4.0
 -----------------------------------------------------------------------------------
*/
#include "Carte.h"

bool Carte::operator==(const Carte& carte) const {
    return this->famille == carte.famille && this->membre == carte.membre;
}

bool Carte::operator<(const Carte& carte) const {
    return this->famille < carte.famille;
}

std::ostream &operator<<(std::ostream& lhs, const Carte& rhs) {
    return lhs << rhs.famille << rhs.membre;
}

Carte::Carte(unsigned short famille, char membre) : famille(famille), membre(membre) {}

unsigned short Carte::getFamille() const { return famille; }

char Carte::getMembre() const { return membre; }


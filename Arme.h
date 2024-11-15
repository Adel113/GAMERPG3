#ifndef ARME_H
#define ARME_H

#include <string>
#include "Objet.hpp"

class Arme : public Objet {
public:
    // Ajout du constructeur avec nom et dégâts
    Arme(const std::string &nom, int degats);
    void changer(const std::string &nom, int degats);
    void afficher() const;
    int getDegats() const;

protected:
    int m_degats;
};

#endif // ARME_H

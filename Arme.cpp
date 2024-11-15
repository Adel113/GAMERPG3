#include "Arme.h"
#include <iostream>

using namespace std;

// Implémentation du constructeur avec nom et dégâts
Arme::Arme(const std::string &nom, int degats)
    : Objet(nom, "", "arme"), m_degats(degats) {}

// Méthode pour changer le nom et les dégâts de l'arme
void Arme::changer(const std::string &nom, int degats) {
    this->nom = nom;
    m_degats = degats;
}

void Arme::afficher() const {
    cout << "Arme : " << nom << "\nDégâts : " << m_degats << endl;
}

int Arme::getDegats() const {
    return m_degats;
}

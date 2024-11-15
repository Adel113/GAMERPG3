//
// Created by sidi ahmed on 12/11/2024.
//

#ifndef OBJET_HPP
#define OBJET_HPP

#include <string>
#include <iostream>

class Objet {
public:
    // Constructeur
    Objet(std::string nom, std::string desc, std::string type);

    // Méthode pour afficher les détails de l'objet
    void afficherObjet() const;

protected:
    std::string nom;
    std::string desc;
    std::string type;
    int effets;
};

#endif // OBJET_HPP

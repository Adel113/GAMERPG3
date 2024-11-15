#include "Objet.hpp"

// Constructeur de Objet
Objet::Objet(std::string nom, std::string desc, std::string type)
    : nom(nom), desc(desc), type(type), effets(0) {}

// Méthode pour afficher les informations de l'objet
void Objet::afficherObjet() const {
    std::cout << "Nom : " << nom << "\nDescription : " << desc
              << "\nType : " << type << "\nEffets : " << effets << std::endl;
}

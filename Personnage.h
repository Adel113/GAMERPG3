#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>
#include "Arme.h" // Inclure la classe Arme

class Personnage {
public:
    // Constructeurs
    Personnage(); // Constructeur par défaut
    Personnage(std::string P_name, const std::string &nomArme, int degatsArme, int vie, int mana); // Constructeur avec paramètres

    // Méthodes
    void afficherEtat() const;
    void recevoirDegats(int degats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(const std::string &nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant() const;

    std::string getNom() const;  // Méthode qui renvoie le nom du personnage
    int getVie() const;  // Méthode qui renvoie la vie du personnage

public:
    Arme arme;  // L'arme du personnage
    int vie;    // La vie du personnage
    int mana;   // Le mana du personnage
    std::string P_name;  // Le nom du personnage
};

#endif // PERSONNAGE_H

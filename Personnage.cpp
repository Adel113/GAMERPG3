//
// Created by sidi ahmed on 28/10/2024.
//

#include "Personnage.h"
#include <iostream>

// Constructeur par défaut
Personnage::Personnage()
    : arme("Épée basique", 10), vie(100), mana(100), P_name("Inconnu") {
    // Initialisation par défaut
}

// Constructeur avec paramètres
Personnage::Personnage(std::string P_name, const std::string &nomArme, int degatsArme, int vie, int mana)
    : P_name(P_name), arme(nomArme, degatsArme), vie(vie), mana(mana) {
}
// Méthode pour recevoir des dégâts
void Personnage::recevoirDegats(int degats) {
    vie -= degats;
    mana -= degats;

    if (vie <= 0 || mana <= 0) { // Pour éviter d'avoir une vie ou un mana négatifs
        vie = 0;
        mana = 0;
        std::cout << "Le personnage est mort." << std::endl;
    }
}

// Méthode pour attaquer un autre personnage
void Personnage::attaquer(Personnage &cible) {
    cible.recevoirDegats(arme.getDegats());
}

// Méthode pour boire une potion de vie
void Personnage::boirePotionDeVie(int quantitePotion) {
    vie += quantitePotion;
    if (vie > 100) {
        vie = 100; // La vie ne doit pas dépasser 100
    }
}

// Méthode pour changer d'arme
void Personnage::changerArme(const std::string &nomNouvelleArme, int degatsNouvelleArme) {
    arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

// Méthode pour afficher l'état du personnage
void Personnage::afficherEtat() const {
    std::cout << "Vie : " << vie << "\nMana : " << mana << std::endl;
    arme.afficher();
    std::cout << std::endl;
}

// Méthode pour vérifier si le personnage est vivant
bool Personnage::estVivant() const {
    return vie > 0;
}

std::string Personnage::getNom() const {
    return P_name;
}

int Personnage::getVie() const {
    return vie;
}


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Personnage.h"

using namespace std;

// Definition de la fonction d'affichage du menu des personnages
void afficherMenuPersonnages() {
    cout << "Choisissez votre personnage : " << endl;
    cout << "1. Magicien" << endl;
    cout << "2. Guerrier" << endl;
    cout << "3. Archer" << endl;
    cout << "Entrez le numero de votre choix : ";
}

// Fonction pour choisir un adversaire aleatoirement
Personnage* choisirAdversaire(Personnage &magicien, Personnage &guerrier, Personnage &archer, const string &nomUtilisateur) {
    srand(time(nullptr)); // Initialisation de la graine pour les nombres aleatoires
    int choix = rand() % 3 + 1; // Genere un nombre entre 1 et 3

    switch (choix) {
        case 1:
            if (nomUtilisateur != "Magicien") return &magicien;
            break;
        case 2:
            if (nomUtilisateur != "Guerrier") return &guerrier;
            break;
        case 3:
            if (nomUtilisateur != "Archer") return &archer;
            break;
    }
    return &guerrier; // Par defaut, retourne Guerrier si aucun autre n'est disponible
}

int main() {

    // Creation des personnages avec leurs armes de base
    Personnage magicien("Magicien", "Baton magique", 25, 100, 100); // Magicien avec baton magique
    Personnage guerrier("Guerrier", "Epee", 30, 100, 50);           // Guerrier avec epee
    Personnage archer("Archer", "Arc long", 20, 100, 60);            // Archer avec arc long

    // Choix de l'utilisateur
    int choixPersonnage;
    afficherMenuPersonnages();
    cin >> choixPersonnage;

    Personnage *joueur = nullptr;
    string nomPersonnage;

    switch (choixPersonnage) {
        case 1:
            joueur = &magicien;
            nomPersonnage = "Magicien";
            break;
        case 2:
            joueur = &guerrier;
            nomPersonnage = "Guerrier";
            break;
        case 3:
            joueur = &archer;
            nomPersonnage = "Archer";
            break;
        default:
            cout << "Choix invalide, vous jouerez en tant que Guerrier par defaut." << endl;
            joueur = &guerrier;
            nomPersonnage = "Guerrier";
    }

    // Choix aleatoire de l'adversaire
    Personnage *adversaire = choisirAdversaire(magicien, guerrier, archer, nomPersonnage);
    cout << "\nVotre adversaire est un " << adversaire->getNom() << " avec " << adversaire->getVie() << " points de vie." << endl;

    // Deroulement du combat
    while (joueur->getVie() > 0 && adversaire->getVie() > 0) {
        // Tour de l'utilisateur
        joueur->attaquer(*adversaire); // Attaque l'adversaire
        cout << "Vous avez inflige des degats a l'adversaire. Vie restante de l'adversaire : " << adversaire->getVie() << endl;

        // Verification si l'adversaire est mort
        if (adversaire->getVie() <= 0) {
            cout << "Vous avez gagne le combat !" << endl;
            break;
        }

        // Tour de l'adversaire
        adversaire->attaquer(*joueur); // Attaque le joueur
        cout << "L'adversaire vous a inflige des degats. Vie restante : " << joueur->getVie() << endl;

        // Verification si la vie de l'utilisateur atteint 50 ou moins
        if (joueur->getVie() <= 50) {
            cout << "Votre vie est faible ! Voulez-vous : " << endl;
            cout << "1. Ramasser une potion pour recuperer 30 points de vie." << endl;
            cout << "2. Continuer a attaquer." << endl;
            int choix;
            cin >> choix;

            if (choix == 1) {
                joueur->boirePotionDeVie(30); // Soigne le joueur
                cout << "Vous avez recupere des points de vie. Vie actuelle : " << joueur->getVie() << endl;
            }
        }

        // Verification si le joueur est mort
        if (joueur->getVie() <= 0) {
            cout << "Vous avez perdu le combat..." << endl;
        }
    }
}

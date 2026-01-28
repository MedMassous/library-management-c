#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIVRES 100
#define MAX_TITRE 100
#define MAX_AUTEUR 50
#define FICHIER_DATA "bibliotheque.txt"
#define FICHIER_RAPPORT "rapport_bibliotheque.txt"

typedef struct {
    int id;
    char titre[MAX_TITRE];
    char auteur[MAX_AUTEUR];
    int annee;
    int disponible;
} Livre;

typedef struct {
    Livre livres[MAX_LIVRES];
    int nombre;
} Bibliotheque;

// Prototypes des fonctions existantes
void afficherMenu();
void ajouterLivre(Bibliotheque *bib);
void rechercherLivre(Bibliotheque *bib);
void afficherLivresRecursif(Livre *livres, int index, int total);
void afficherTousLesLivres(Bibliotheque *bib);
void emprunterLivre(Bibliotheque *bib);
void retournerLivre(Bibliotheque *bib);
void sauvegarderDonnees(Bibliotheque *bib);
int chargerDonnees(Bibliotheque *bib);
void viderBuffer();
void toLower(char *str);

// Prototypes des nouvelles fonctions
void supprimerLivre(Bibliotheque *bib);
void modifierLivre(Bibliotheque *bib);
void afficherStatistiques(Bibliotheque *bib);
int compterDisponiblesRecursif(Livre *livres, int index, int total);
int compterEmpruntesRecursif(Livre *livres, int index, int total);
void filtrerLivres(Bibliotheque *bib);
void trierLivres(Bibliotheque *bib);
void exporterRapport(Bibliotheque *bib);
void afficherLivresFiltresRecursif(Livre *livres, int index, int total, int filtre);

int main() {
    Bibliotheque biblio;
    biblio.nombre = 0;
    int choix;

    printf("========================================\n");
    printf("  SYSTEME DE GESTION DE BIBLIOTHEQUE\n");
    printf("========================================\n\n");

    if (chargerDonnees(&biblio)) {
        printf("Donnees chargees avec succes (%d livre(s))\n\n", biblio.nombre);
    } else {
        printf("Aucune donnee existante. Nouvelle bibliotheque creee.\n\n");
    }

    do {
        afficherMenu();
        printf("Votre choix : ");

        if (scanf("%d", &choix) != 1) {
            printf("\nErreur: Veuillez entrer un nombre valide.\n\n");
            viderBuffer();
            continue;
        }
        viderBuffer();

        printf("\n");

        switch(choix) {
            case 1:
                ajouterLivre(&biblio);
                break;
            case 2:
                rechercherLivre(&biblio);
                break;
            case 3:
                afficherTousLesLivres(&biblio);
                break;
            case 4:
                emprunterLivre(&biblio);
                break;
            case 5:
                retournerLivre(&biblio);
                break;
            case 6:
                supprimerLivre(&biblio);
                break;
            case 7:
                modifierLivre(&biblio);
                break;
            case 8:
                afficherStatistiques(&biblio);
                break;
            case 9:
                filtrerLivres(&biblio);
                break;
            case 10:
                trierLivres(&biblio);
                break;
            case 11:
                exporterRapport(&biblio);
                break;
            case 12:
                sauvegarderDonnees(&biblio);
                printf("Donnees sauvegardees avec succes!\n");
                break;
            case 0:
                sauvegarderDonnees(&biblio);
                printf("Donnees sauvegardees.\n");
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Reessayez.\n");
        }

        printf("\n");

    } while(choix != 0);

    return 0;
}

void afficherMenu() {
    printf("========================================\n");
    printf("              MENU PRINCIPAL\n");
    printf("========================================\n");
    printf("1.  Ajouter un livre\n");
    printf("2.  Rechercher un livre\n");
    printf("3.  Afficher tous les livres\n");
    printf("4.  Emprunter un livre\n");
    printf("5.  Retourner un livre\n");
    printf("6.  Supprimer un livre\n");
    printf("7.  Modifier un livre\n");
    printf("8.  Afficher les statistiques\n");
    printf("9.  Filtrer les livres\n");
    printf("10. Trier les livres\n");
    printf("11. Exporter un rapport\n");
    printf("12. Sauvegarder les donnees\n");
    printf("0.  Quitter\n");
    printf("========================================\n");
}

void toLower(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

void ajouterLivre(Bibliotheque *bib) {
    if (bib->nombre >= MAX_LIVRES) {
        printf("Erreur: La bibliotheque est pleine!\n");
        return;
    }

    Livre *nouveau = &(bib->livres[bib->nombre]);

    printf("=== AJOUTER UN NOUVEAU LIVRE ===\n\n");

    nouveau->id = bib->nombre + 1;

    printf("Titre du livre : ");
    if (fgets(nouveau->titre, MAX_TITRE, stdin) == NULL) {
        printf("Erreur de lecture.\n");
        return;
    }
    nouveau->titre[strcspn(nouveau->titre, "\n")] = 0;

    if (strlen(nouveau->titre) == 0) {
        printf("Erreur: Le titre ne peut pas etre vide.\n");
        return;
    }

    printf("Auteur : ");
    if (fgets(nouveau->auteur, MAX_AUTEUR, stdin) == NULL) {
        printf("Erreur de lecture.\n");
        return;
    }
    nouveau->auteur[strcspn(nouveau->auteur, "\n")] = 0;

    if (strlen(nouveau->auteur) == 0) {
        printf("Erreur: L'auteur ne peut pas etre vide.\n");
        return;
    }

    printf("Annee de publication : ");
    if (scanf("%d", &(nouveau->annee)) != 1) {
        printf("Erreur: Annee invalide.\n");
        viderBuffer();
        return;
    }
    viderBuffer();

    if (nouveau->annee < 1000 || nouveau->annee > 2100) {
        printf("Erreur: Annee invalide (doit etre entre 1000 et 2100).\n");
        return;
    }

    nouveau->disponible = 1;
    bib->nombre++;

    printf("\nLivre ajoute avec succes! (ID: %d)\n", nouveau->id);
}

void rechercherLivre(Bibliotheque *bib) {
    if (bib->nombre == 0) {
        printf("La bibliotheque est vide!\n");
        return;
    }

    char recherche[MAX_TITRE];
    int trouve = 0;

    printf("=== RECHERCHER UN LIVRE ===\n\n");
    printf("Entrez le titre ou l'auteur : ");
    if (fgets(recherche, MAX_TITRE, stdin) == NULL) {
        printf("Erreur de lecture.\n");
        return;
    }
    recherche[strcspn(recherche, "\n")] = 0;

    if (strlen(recherche) == 0) {
        printf("Erreur: La recherche ne peut pas etre vide.\n");
        return;
    }

    toLower(recherche);

    printf("\n--- Resultats de la recherche ---\n\n");

    for (int i = 0; i < bib->nombre; i++) {
        Livre *livre = &(bib->livres[i]);

        char titre_min[MAX_TITRE], auteur_min[MAX_AUTEUR];
        strcpy(titre_min, livre->titre);
        strcpy(auteur_min, livre->auteur);

        toLower(titre_min);
        toLower(auteur_min);

        if (strstr(titre_min, recherche) != NULL || strstr(auteur_min, recherche) != NULL) {
            printf("ID: %d\n", livre->id);
            printf("Titre: %s\n", livre->titre);
            printf("Auteur: %s\n", livre->auteur);
            printf("Annee: %d\n", livre->annee);
            printf("Statut: %s\n", livre->disponible ? "Disponible" : "Emprunte");
            printf("--------------------------------\n");
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun livre trouve.\n");
    }
}

void afficherLivresRecursif(Livre *livres, int index, int total) {
    if (index >= total) {
        return;
    }

    Livre *livre = &livres[index];

    printf("ID: %d\n", livre->id);
    printf("Titre: %s\n", livre->titre);
    printf("Auteur: %s\n", livre->auteur);
    printf("Annee: %d\n", livre->annee);
    printf("Statut: %s\n", livre->disponible ? "Disponible" : "Emprunte");
    printf("--------------------------------\n");

    afficherLivresRecursif(livres, index + 1, total);
}

void afficherTousLesLivres(Bibliotheque *bib) {
    if (bib->nombre == 0) {
        printf("La bibliotheque est vide!\n");
        return;
    }

    printf("=== LISTE DES LIVRES ===\n\n");
    printf("Total: %d livre(s)\n\n", bib->nombre);

    afficherLivresRecursif(bib->livres, 0, bib->nombre);
}

void emprunterLivre(Bibliotheque *bib) {
    if (bib->nombre == 0) {
        printf("La bibliotheque est vide!\n");
        return;
    }

    int id;
    printf("=== EMPRUNTER UN LIVRE ===\n\n");
    printf("Entrez l'ID du livre : ");

    if (scanf("%d", &id) != 1) {
        printf("\nErreur: ID invalide.\n");
        viderBuffer();
        return;
    }
    viderBuffer();

    int trouve = 0;
    for (int i = 0; i < bib->nombre; i++) {
        Livre *livre = &(bib->livres[i]);

        if (livre->id == id) {
            trouve = 1;

            if (livre->disponible) {
                livre->disponible = 0;
                printf("\nLivre emprunte avec succes!\n");
                printf("Titre: %s\n", livre->titre);
            } else {
                printf("\nCe livre est deja emprunte!\n");
            }
            break;
        }
    }

    if (!trouve) {
        printf("\nLivre non trouve!\n");
    }
}

void retournerLivre(Bibliotheque *bib) {
    if (bib->nombre == 0) {
        printf("La bibliotheque est vide!\n");
        return;
    }

    int id;
    printf("=== RETOURNER UN LIVRE ===\n\n");
    printf("Entrez l'ID du livre : ");

    if (scanf("%d", &id) != 1) {
        printf("\nErreur: ID invalide.\n");
        viderBuffer();
        return;
    }
    viderBuffer();

    int trouve = 0;
    for (int i = 0; i < bib->nombre; i++) {
        Livre *livre = &(bib->livres[i]);

        if (livre->id == id) {
            trouve = 1;

            if (!livre->disponible) {
                livre->disponible = 1;
                printf("\nLivre retourne avec succes!\n");
                printf("Titre: %s\n", livre->titre);
            } else {
                printf("\nCe livre n'etait pas emprunte!\n");
            }
            break;
        }
    }

    if (!trouve) {
        printf("\nLivre non trouve!\n");
    }
}

// NOUVELLE FONCTION: Supprimer un livre
void supprimerLivre(Bibliotheque *bib) {
    if (bib->nombre == 0) {
        printf("La bibliotheque est vide!\n");
        return;
    }

    int id;
    printf("=== SUPPRIMER UN LIVRE ===\n\n");
    printf("Entrez l'ID du livre a supprimer : ");

    if (scanf("%d", &id) != 1) {
        printf("\nErreur: ID invalide.\n");
        viderBuffer();
        return;
    }
    viderBuffer();

    int trouve = 0;
    int position = -1;

    // Trouver le livre
    for (int i = 0; i < bib->nombre; i++) {
        if (bib->livres[i].id == id) {
            trouve = 1;
            position = i;
            break;
        }
    }

    if (!trouve) {
        printf("\nLivre non trouve!\n");
        return;
    }

    // Afficher les infos du livre avant suppression
    printf("\nLivre a supprimer:\n");
    printf("Titre: %s\n", bib->livres[position].titre);
    printf("Auteur: %s\n", bib->livres[position].auteur);

    printf("\nEtes-vous sur de vouloir supprimer ce livre? (o/n) : ");
    char confirmation;
    scanf(" %c", &confirmation);
    viderBuffer();

    if (confirmation != 'o' && confirmation != 'O') {
        printf("\nSuppression annulee.\n");
        return;
    }

    // Décaler tous les livres suivants vers la gauche
    for (int i = position; i < bib->nombre - 1; i++) {
        bib->livres[i] = bib->livres[i + 1];
    }

    bib->nombre--;
    printf("\nLivre supprime avec succes!\n");
}

// NOUVELLE FONCTION: Modifier un livre
void modifierLivre(Bibliotheque *bib) {
    if (bib->nombre == 0) {
        printf("La bibliotheque est vide!\n");
        return;
    }

    int id;
    printf("=== MODIFIER UN LIVRE ===\n\n");
    printf("Entrez l'ID du livre a modifier : ");

    if (scanf("%d", &id) != 1) {
        printf("\nErreur: ID invalide.\n");
        viderBuffer();
        return;
    }
    viderBuffer();

    Livre *livre = NULL;

    // Trouver le livre
    for (int i = 0; i < bib->nombre; i++) {
        if (bib->livres[i].id == id) {
            livre = &(bib->livres[i]);
            break;
        }
    }

    if (livre == NULL) {
        printf("\nLivre non trouve!\n");
        return;
    }

    // Afficher les informations actuelles
    printf("\n--- Informations actuelles ---\n");
    printf("Titre: %s\n", livre->titre);
    printf("Auteur: %s\n", livre->auteur);
    printf("Annee: %d\n", livre->annee);
    printf("Statut: %s\n", livre->disponible ? "Disponible" : "Emprunte");

    printf("\n--- Modification ---\n");
    printf("Laissez vide pour garder la valeur actuelle\n\n");

    // Modifier le titre
    char nouveau_titre[MAX_TITRE];
    printf("Nouveau titre (actuel: %s) : ", livre->titre);
    if (fgets(nouveau_titre, MAX_TITRE, stdin) != NULL) {
        nouveau_titre[strcspn(nouveau_titre, "\n")] = 0;
        if (strlen(nouveau_titre) > 0) {
            strcpy(livre->titre, nouveau_titre);
        }
    }

    // Modifier l'auteur
    char nouvel_auteur[MAX_AUTEUR];
    printf("Nouvel auteur (actuel: %s) : ", livre->auteur);
    if (fgets(nouvel_auteur, MAX_AUTEUR, stdin) != NULL) {
        nouvel_auteur[strcspn(nouvel_auteur, "\n")] = 0;
        if (strlen(nouvel_auteur) > 0) {
            strcpy(livre->auteur, nouvel_auteur);
        }
    }

    // Modifier l'année
    printf("Nouvelle annee (actuelle: %d, 0 pour garder) : ", livre->annee);
    int nouvelle_annee;
    if (scanf("%d", &nouvelle_annee) == 1 && nouvelle_annee != 0) {
        if (nouvelle_annee >= 1000 && nouvelle_annee <= 2100) {
            livre->annee = nouvelle_annee;
        } else {
            printf("Annee invalide, valeur conservee.\n");
        }
    }
    viderBuffer();

    printf("\nLivre modifie avec succes!\n");
}

// NOUVELLE FONCTION RECURSIVE: Compter les livres disponibles
int compterDisponiblesRecursif(Livre *livres, int index, int total) {
    // Cas de base
    if (index >= total) {
        return 0;
    }

    // Compter ce livre s'il est disponible + compter le reste récursivement
    int compte = livres[index].disponible ? 1 : 0;
    return compte + compterDisponiblesRecursif(livres, index + 1, total);
}

// NOUVELLE FONCTION RECURSIVE: Compter les livres empruntés
int compterEmpruntesRecursif(Livre *livres, int index, int total) {
    // Cas de base
    if (index >= total) {
        return 0;
    }

    // Compter ce livre s'il est emprunté + compter le reste récursivement
    int compte = !livres[index].disponible ? 1 : 0;
    return compte + compterEmpruntesRecursif(livres, index + 1, total);
}

// NOUVELLE FONCTION: Afficher les statistiques
void afficherStatistiques(Bibliotheque *bib) {
    printf("=== STATISTIQUES DE LA BIBLIOTHEQUE ===\n\n");

    if (bib->nombre == 0) {
        printf("La bibliotheque est vide!\n");
        return;
    }

    int disponibles = compterDisponiblesRecursif(bib->livres, 0, bib->nombre);
    int empruntes = compterEmpruntesRecursif(bib->livres, 0, bib->nombre);

    printf("Nombre total de livres : %d\n", bib->nombre);
    printf("Livres disponibles     : %d (%.1f%%)\n", 
           disponibles, (float)disponibles / bib->nombre * 100);
    printf("Livres empruntes       : %d (%.1f%%)\n", 
           empruntes, (float)empruntes / bib->nombre * 100);

    // Trouver le livre le plus ancien et le plus récent
    int annee_min = bib->livres[0].annee;
    int annee_max = bib->livres[0].annee;

    for (int i = 1; i < bib->nombre; i++) {
        if (bib->livres[i].annee < annee_min) {
            annee_min = bib->livres[i].annee;
        }
        if (bib->livres[i].annee > annee_max) {
            annee_max = bib->livres[i].annee;
        }
    }

    printf("\nAnnee du plus ancien livre : %d\n", annee_min);
    printf("Annee du plus recent livre : %d\n", annee_max);
}

// NOUVELLE FONCTION RECURSIVE: Afficher les livres filtrés
void afficherLivresFiltresRecursif(Livre *livres, int index, int total, int filtre) {
    if (index >= total) {
        return;
    }

    Livre *livre = &livres[index];

    // filtre: 1 = disponibles, 0 = empruntes
    if (livre->disponible == filtre) {
        printf("ID: %d\n", livre->id);
        printf("Titre: %s\n", livre->titre);
        printf("Auteur: %s\n", livre->auteur);
        printf("Annee: %d\n", livre->annee);
        printf("Statut: %s\n", livre->disponible ? "Disponible" : "Emprunte");
        printf("--------------------------------\n");
    }

    afficherLivresFiltresRecursif(livres, index + 1, total, filtre);
}

// NOUVELLE FONCTION: Filtrer les livres
void filtrerLivres(Bibliotheque *bib) {
    if (bib->nombre == 0) {
        printf("La bibliotheque est vide!\n");
        return;
    }

    int choix;
    printf("=== FILTRER LES LIVRES ===\n\n");
    printf("1. Afficher uniquement les livres disponibles\n");
    printf("2. Afficher uniquement les livres empruntes\n");
    printf("Votre choix : ");

    if (scanf("%d", &choix) != 1) {
        printf("\nErreur: Choix invalide.\n");
        viderBuffer();
        return;
    }
    viderBuffer();

    printf("\n");

    if (choix == 1) {
        int disponibles = compterDisponiblesRecursif(bib->livres, 0, bib->nombre);
        printf("--- Livres Disponibles (%d) ---\n\n", disponibles);
        afficherLivresFiltresRecursif(bib->livres, 0, bib->nombre, 1);
    } else if (choix == 2) {
        int empruntes = compterEmpruntesRecursif(bib->livres, 0, bib->nombre);
        printf("--- Livres Empruntes (%d) ---\n\n", empruntes);
        afficherLivresFiltresRecursif(bib->livres, 0, bib->nombre, 0);
    } else {
        printf("Choix invalide.\n");
    }
}

// NOUVELLE FONCTION: Trier les livres
void trierLivres(Bibliotheque *bib) {
    if (bib->nombre == 0) {
        printf("La bibliotheque est vide!\n");
        return;
    }

    int choix;
    printf("=== TRIER LES LIVRES ===\n\n");
    printf("1. Trier par titre (A-Z)\n");
    printf("2. Trier par auteur (A-Z)\n");
    printf("3. Trier par annee (croissant)\n");
    printf("Votre choix : ");

    if (scanf("%d", &choix) != 1) {
        printf("\nErreur: Choix invalide.\n");
        viderBuffer();
        return;
    }
    viderBuffer();

    // Tri à bulles simple
    for (int i = 0; i < bib->nombre - 1; i++) {
        for (int j = 0; j < bib->nombre - i - 1; j++) {
            int echanger = 0;

            if (choix == 1) {
                // Trier par titre
                char titre1[MAX_TITRE], titre2[MAX_TITRE];
                strcpy(titre1, bib->livres[j].titre);
                strcpy(titre2, bib->livres[j + 1].titre);
                toLower(titre1);
                toLower(titre2);
                if (strcmp(titre1, titre2) > 0) {
                    echanger = 1;
                }
            } else if (choix == 2) {
                // Trier par auteur
                char auteur1[MAX_AUTEUR], auteur2[MAX_AUTEUR];
                strcpy(auteur1, bib->livres[j].auteur);
                strcpy(auteur2, bib->livres[j + 1].auteur);
                toLower(auteur1);
                toLower(auteur2);
                if (strcmp(auteur1, auteur2) > 0) {
                    echanger = 1;
                }
            } else if (choix == 3) {
                // Trier par année
                if (bib->livres[j].annee > bib->livres[j + 1].annee) {
                    echanger = 1;
                }
            }

            if (echanger) {
                Livre temp = bib->livres[j];
                bib->livres[j] = bib->livres[j + 1];
                bib->livres[j + 1] = temp;
            }
        }
    }

    printf("\nLivres tries avec succes!\n");
    printf("Voulez-vous afficher les livres tries? (o/n) : ");
    char afficher;
    scanf(" %c", &afficher);
    viderBuffer();

    if (afficher == 'o' || afficher == 'O') {
        printf("\n");
        afficherTousLesLivres(bib);
    }
}

// NOUVELLE FONCTION: Exporter un rapport
void exporterRapport(Bibliotheque *bib) {
    FILE *fichier = fopen(FICHIER_RAPPORT, "w");

    if (fichier == NULL) {
        printf("Erreur lors de la creation du rapport!\n");
        return;
    }

    fprintf(fichier, "========================================\n");
    fprintf(fichier, "   RAPPORT DE LA BIBLIOTHEQUE\n");
    fprintf(fichier, "========================================\n\n");

    // Statistiques générales
    int disponibles = compterDisponiblesRecursif(bib->livres, 0, bib->nombre);
    int empruntes = compterEmpruntesRecursif(bib->livres, 0, bib->nombre);

    fprintf(fichier, "STATISTIQUES:\n");
    fprintf(fichier, "-------------\n");
    fprintf(fichier, "Nombre total de livres : %d\n", bib->nombre);
    fprintf(fichier, "Livres disponibles     : %d\n", disponibles);
    fprintf(fichier, "Livres empruntes       : %d\n", empruntes);
    fprintf(fichier, "\n");

    // Liste complète des livres
    fprintf(fichier, "LISTE COMPLETE DES LIVRES:\n");
    fprintf(fichier, "==========================\n\n");

    for (int i = 0; i < bib->nombre; i++) {
        Livre *livre = &(bib->livres[i]);
        fprintf(fichier, "ID: %d\n", livre->id);
        fprintf(fichier, "Titre: %s\n", livre->titre);
        fprintf(fichier, "Auteur: %s\n", livre->auteur);
        fprintf(fichier, "Annee: %d\n", livre->annee);
        fprintf(fichier, "Statut: %s\n", livre->disponible ? "Disponible" : "Emprunte");
        fprintf(fichier, "--------------------------------\n");
    }

    fprintf(fichier, "\n");
    fprintf(fichier, "Fin du rapport.\n");

    fclose(fichier);

    printf("Rapport exporte avec succes dans '%s'!\n", FICHIER_RAPPORT);
}

void sauvegarderDonnees(Bibliotheque *bib) {
    FILE *fichier = fopen(FICHIER_DATA, "w");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour sauvegarde!\n");
        return;
    }

    fprintf(fichier, "%d\n", bib->nombre);

    for (int i = 0; i < bib->nombre; i++) {
        Livre *livre = &(bib->livres[i]);
        fprintf(fichier, "%d\n", livre->id);
        fprintf(fichier, "%s\n", livre->titre);
        fprintf(fichier, "%s\n", livre->auteur);
        fprintf(fichier, "%d\n", livre->annee);
        fprintf(fichier, "%d\n", livre->disponible);
    }

    fclose(fichier);
}

int chargerDonnees(Bibliotheque *bib) {
    FILE *fichier = fopen(FICHIER_DATA, "r");

    if (fichier == NULL) {
        return 0;
    }

    if (fscanf(fichier, "%d\n", &(bib->nombre)) != 1) {
        fclose(fichier);
        return 0;
    }

    if (bib->nombre < 0 || bib->nombre > MAX_LIVRES) {
        fclose(fichier);
        bib->nombre = 0;
        return 0;
    }

    for (int i = 0; i < bib->nombre; i++) {
        Livre *livre = &(bib->livres[i]);

        if (fscanf(fichier, "%d\n", &(livre->id)) != 1) {
            bib->nombre = i;
            fclose(fichier);
            return 1;
        }

        if (fgets(livre->titre, MAX_TITRE, fichier) == NULL) {
            bib->nombre = i;
            fclose(fichier);
            return 1;
        }
        livre->titre[strcspn(livre->titre, "\n")] = 0;

        if (fgets(livre->auteur, MAX_AUTEUR, fichier) == NULL) {
            bib->nombre = i;
            fclose(fichier);
            return 1;
        }
        livre->auteur[strcspn(livre->auteur, "\n")] = 0;

        if (fscanf(fichier, "%d\n", &(livre->annee)) != 1) {
            bib->nombre = i;
            fclose(fichier);
            return 1;
        }

        if (fscanf(fichier, "%d\n", &(livre->disponible)) != 1) {
            bib->nombre = i;
            fclose(fichier);
            return 1;
        }
    }

    fclose(fichier);
    return 1;
}

void viderBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

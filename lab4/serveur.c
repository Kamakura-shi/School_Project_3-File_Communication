/**
 * Programme principal - serveur.c
 *
 * Par : Hani Ouali
 * Date : mars 2023
 *
 * Le programme main permet a un utilisateur de rentrer manuellement des 
 * parametre de recherche. Il permet aussi de tester des fonctions.
 *
 * Exemple d'exécution:
 *  ./Debug/serveur
 */

#include "recherche.h"
#include <fcntl.h>

#define FIFO_CLIENT "fifo_client"
#define FIFO_SERVEUR "fifo_serveur"

#define TAILLE_MAX 200

int main(void) {
    int descripteur_fifo_ecriture = 0;
    int descripteur_fifo_lecture = 0;

    printf(" [*] Démarrage du serveur\n");
    printf(" [*] En attente du client...\n");

    printf("En attente d'une connexion au FIFO CLIENT en lecture...\n");
    descripteur_fifo_lecture = open(FIFO_CLIENT, O_RDONLY);

    if (descripteur_fifo_ecriture < 0) {
        printf("Erreur lors de l'ouverture du FIFO CLIENT en lecture");
        exit(1);
    }

    printf("En attente d'une connexion au FIFO CLIENT en écriture...\n");
    descripteur_fifo_ecriture = open(FIFO_SERVEUR, O_WRONLY);

    if (descripteur_fifo_ecriture < 0) {
        printf("Erreur lors de l'ouverture du FIFO CLIENT en écriture");
        exit(1);
    }

    printf(" [*] Connexion établie avec un client\n");
    
    // Création de la structure critere et stockage des arguments reçus
    t_critere critere = creer_critere();

    // Comm-HLR02: Le serveur récupère les critères d'une opération de recherche 
    printf(" [*] Réception des critères de recherche...\n");

    char * message_ecrit = (char *)malloc(TAILLE_MAX*sizeof(char));
    char * message_lu = (char *)malloc(TAILLE_MAX*sizeof(char));
    char * titre = (char *)malloc(TAILLE_MAX*sizeof(char));
    char * categorie = (char *)malloc(TAILLE_MAX*sizeof(char));
    char * annees = (char *)malloc(TAILLE_MAX*sizeof(char));
    char * genre = (char *)malloc(TAILLE_MAX*sizeof(char));

    read(descripteur_fifo_lecture, message_lu, TAILLE_MAX*sizeof(char));
    titre = message_lu;
    set_titre(critere, titre);

    printf("     [+] Titre : %s\n", titre);

    read(descripteur_fifo_lecture, message_lu, TAILLE_MAX*sizeof(char));
    categorie = message_lu;
    set_categorie(critere, categorie);

    if (categorie != "NULL") {
        printf("     [+] Catégorie : %s\n", categorie);
    }

    read(descripteur_fifo_lecture, message_lu, TAILLE_MAX*sizeof(char));
    annees = message_lu;

    if (annees != "NULL") {
        printf("     [+] Années : %s\n", message_lu);
    }

    set_intervalle_annees(critere, annees);

    read(descripteur_fifo_lecture, message_lu, TAILLE_MAX*sizeof(char));
    genre = message_lu;
    set_genre(critere, genre);

    if (genre != "NULL") {
        printf("     [+] Genre : %s\n", genre);
    }

    // Comm-HLR03: Le serveur retourne les résultats d'une opération de recherche 
    printf(" [*] Exploration de la base de données\n");
    printf(" [*] Visualisation des résultats\n");
    
    strcpy(message_ecrit, "3");
    write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));

    printf("    [+] %s résultats de titre trouvés\n", message_ecrit);

    strcpy(message_ecrit, "The Matrix");
    write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));

    printf("    [1] Titre : %s\n", message_ecrit);
    printf("    [2] Titre : %s\n", message_ecrit);
    printf("    [3] Titre : %s\n", message_ecrit);
    printf(" [*] Envoi des résultats au client...\n");

    // Phase 4

    // Comm-HLR07: Le serveur reçoit le titre à évaluer
    char * nb_choisi = (char *)malloc(TAILLE_MAX*sizeof(char));

    read(descripteur_fifo_lecture, message_lu, TAILLE_MAX*sizeof(char));
    nb_choisi = message_lu;
    printf("nb_choisi : %s\n", message_lu);

    // Comm-HLR08: Le serveur envoie la cote de classement du titre choisi
    strcpy(message_ecrit, "tt0133093");
    write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));
    printf(" Titre :  %s\n", message_ecrit);
    
    strcpy(message_ecrit, "4.5");
    write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));
    printf(" Cote de classement moyenne :  %s \n", message_ecrit);

    strcpy(message_ecrit, "20");
    write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));
    printf(" Nombre de votes :  %s\n", message_ecrit);

    // Comm-HLR11: Le serveur reçoit l'évaluation
    printf(" [*] Réception de l'évaluation\n");

    char * evaluation = (char *)malloc(TAILLE_MAX*sizeof(char));

    read(descripteur_fifo_lecture, message_lu, TAILLE_MAX*sizeof(char));
    evaluation = message_lu;
    printf("nb_choisi : %s\n", message_lu);

    // Comm-HLR12: Le serveur envoie la nouvelle cote de classement du titre
    printf(" [*] Envoi de la nouvelle cote de classement\n");

    strcpy(message_ecrit, "tt0133093");
    write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));
    printf(" Titre :  %s\n", message_ecrit);
    
    strcpy(message_ecrit, "4.6");
    write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));
    printf(" Cote de classement moyenne :  %s \n", message_ecrit);

    strcpy(message_ecrit, "20");
    write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));
    printf(" Nombre de votes :  %s\n", message_ecrit);

    printf(" [-] Fermeture du serveur\n");

    close(descripteur_fifo_ecriture);
    close(descripteur_fifo_lecture);

    return 0;
}


/**
 * Programme principal - client.c
 *
 * Par : Hani Ouali
 * Date : mars 2023
 *
 * Le programme main permet a un utilisateur de rentrer manuellement des 
 * parametre de recherche. Il permet aussi de tester des fonctions.
 *
 * Exemple d'exécution:
 *  ./Debug/client -t "The Matrix" -c "Action,Sci-Fi" -a "1990:2000"
 */

#include "recherche.h"
#include <unistd.h>
#include <fcntl.h>

#define FIFO_CLIENT "fifo_client"
#define FIFO_SERVEUR "fifo_serveur"

#define PERMISSIONS 0666

#define TAILLE_MAX 200

int main(int argc, char *argv[]) {
    char *titre = NULL, *genre = NULL, *annees = NULL, *categorie = NULL;
    int a_evalue;
    // Lab2-HLR01 - Arguments provenant du terminal
    // Si aucun argument n'est donné, le programme s'arrête
    if (argc < 2) {
       printf("Invalide! Pas assez de paramètres!\n");
       return -1;
    }

    // Lab2-HLR02 - Arguments possibles

    //lab3
    int opt;
    while ((opt = getopt(argc, argv, "t:c:a:g:v:")) != -1) {
        switch(opt) {
            
        // Option de titre
        case 't':
            // On passe a l'argument qui vient après l'option
            titre = optarg;
            break;
        
        // Option de catégorie
        case 'c':
            // On passe a l'argument qui vient après l'option
            categorie = optarg;
            break;

        // Option d'années
        case 'a':
            // On passe a l'argument qui vient après l'option
            annees = optarg;
            break;

        // Option de genre
        case 'g':
            // On passe a l'argument qui vient après l'option
            genre = optarg;
            break;

        // Option d'évaluation
        case 'v':
            // On passe a l'argument qui vient après l'option
            a_evalue = 1;
            break;
        }
    
    }

    // Lab2-HLR03 - Argument obligatoire
    if (titre == NULL) {
        printf("Commande invalide");
        return 0;
        
    }

    // Création de la structure critere et stockage des arguments reçus
    // t_critere critere = creer_critere();

    // set_titre(critere, titre);
    // if (categorie) 
    //     set_categorie(critere, categorie);
    // if (genre) 
    //     set_genre(critere, genre);
    // if (annees) 
    //     set_intervalle_annees(critere, annees);

    // Phase 1
    // printf("Titre :  %s\n", get_titre(critere));
    // printf("Categorie :  %s \n", get_categorie(critere));
    // printf("Annees :  %d:%d\n", get_annee_parution_min(critere), get_annee_parution_max(critere));

    int erreur = 0;

    int socket_serveur = 0;

    // erreur = mkfifo(FIFO_CLIENT, PERMISSIONS);
    // if (erreur != 0) {
    //     printf("Erreur lors de la création du FIFO_CLIENT");
    //     exit(1);
    // }

    socket_serveur = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_serveur == -1) {
        printf("Erreur lors de la création du socket");
        exit(1);
    }

    // erreur = mkfifo(FIFO_SERVEUR, PERMISSIONS);
    // if (erreur != 0) {
    //     printf("Erreur lors de la création du FIFO_SERVEUR");
    //     exit(1);
    // }

    // printf("FIFOs crées avec succès\n");

    // int descripteur_fifo_ecriture = 0;
    // int descripteur_fifo_lecture = 0;

    int descripteur_socket = socket(AF_INET, SOCK_STREAM, 0);

    // printf("En attente d'une connexion au FIFO CLIENT en écriture...\n");
    // descripteur_fifo_ecriture = open(FIFO_CLIENT, O_WRONLY);

    // if (descripteur_fifo_ecriture < 0) {
    //     printf("Erreur lors de l'ouverture du FIFO CLIENT en écriture");
    //     exit(1);
    // }

    // printf("En attente d'une connexion au FIFO CLIENT en lecture...\n");
    // descripteur_fifo_lecture = open(FIFO_SERVEUR, O_RDONLY);

    // if (descripteur_fifo_ecriture < 0) {
    //     printf("Erreur lors de l'ouverture du FIFO CLIENT en lecture");
    //     exit(1);
    // }

    struct sockaddr_in adresse_client;
    socklen_t taille_adresse_client = sizeof(adresse_client);
    socket_client = accept(socket_serveur, (struct sockaddr*)&adresse_client, &taille_adresse_client);
    if (socket_client == -1) {
        printf("Erreur lors de l'acceptation de la connexion entrante");
        exit(1);
    }

    bind(descripteur_socket, (struct sockaddr*)&adresse, sizeof(adresse));

    listen(descripteur_socket, 1);

    printf(" [*] Connexion établie avec le serveur\n");

    // Comm-HLR01: Le client fait une opération de recherche
    printf(" [*] Envoi des critères de recherche...\n");

    char * message_ecrit = (char *)malloc(TAILLE_MAX*sizeof(char));
    char * message_lu = (char *)malloc(TAILLE_MAX*sizeof(char));

    strcpy(message_ecrit, titre);
    write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));

    printf("     [+] Titre : %s\n", message_ecrit);

    if (categorie) {
        strcpy(message_ecrit, categorie);
        write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));

        printf("     [+] Catégorie : %s\n", message_ecrit);
    }
    else {
        strcpy(message_ecrit, "");
        write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));
    }

    if (annees){
        strcpy(message_ecrit, annees);
        write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));

        printf("     [+] Années : %s\n", message_ecrit);
    }
    else {
        strcpy(message_ecrit, "");
        write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));
    }

    if (genre){
        strcpy(message_ecrit, genre);
        write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));

        printf("     [+] Genre : %s\n", message_ecrit);
    }
    else {
        strcpy(message_ecrit, "");
        write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));
    }

    // Comm-HLR04: Le client récupère les résultats d'une opération de recherche 
    printf(" [*] Réception des résultats\n");
    
    char * nb_resultat = (char *)malloc(TAILLE_MAX*sizeof(char));

    read(descripteur_fifo_lecture, message_lu, TAILLE_MAX*sizeof(char));
    nb_resultat = message_lu;

    printf("    [+] %s résultats reçus\n", nb_resultat);

    char * resultat = (char *)malloc(TAILLE_MAX*sizeof(char));

    read(descripteur_fifo_lecture, message_lu, TAILLE_MAX*sizeof(char));
    resultat = message_lu;

    printf("    [1] Titre : %s\n", resultat);
    printf("    [2] Titre : %s\n", resultat);
    printf("    [3] Titre : %s\n", resultat);

    // Phase 4

    if (a_evalue) {
        printf("     [+] Demande d'évaluation\n");
    }

    // Comm-HLR05: Le client demande à l'utilisateur le titre à évaluer
    char * nb_choisi = (char *)malloc(TAILLE_MAX*sizeof(char));

    printf("Veuillez choisir un titre à évaluer.\n");
    printf(" >");
    scanf("%s", nb_choisi);
    printf("nb_choisi (test) : %d\n", nb_choisi);

    // Comm-HLR06: Le client envoie au serveur le titre à évaluer
    strcpy(message_ecrit, nb_choisi);
    write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));
    printf("nb_choisi : %s\n", message_ecrit);

    // Comm-HLR09: Le client récupère la cote de classement du titre
    char * c_titre = (char *)malloc(TAILLE_MAX*sizeof(char));

    read(descripteur_fifo_lecture, message_lu, TAILLE_MAX*sizeof(char));
    c_titre = message_lu;
    printf(" Titre :  %s\n", message_lu);

    char * c_cote = (char *)malloc(TAILLE_MAX*sizeof(char));

    read(descripteur_fifo_lecture, message_lu, TAILLE_MAX*sizeof(char));
    c_cote = message_lu;
    printf(" Cote de classement moyenne :  %s \n", message_lu);

    char * c_vote = (char *)malloc(TAILLE_MAX*sizeof(char));

    read(descripteur_fifo_lecture, message_lu, TAILLE_MAX*sizeof(char));
    c_vote = message_lu;
    printf(" Nombre de votes :  %s\n", message_lu);

    // Comm-HLR10: Le client envoie au serveur l'évaluation de l'utilisateur
    char * evaluation = (char *)malloc(TAILLE_MAX*sizeof(char));

    printf("Quelle note sur 10 donnez-vous au titre ?\n");
    printf(" >");
    scanf("%s", evaluation);
    printf("évaluation (test) : %s\n", evaluation);

    strcpy(message_ecrit, evaluation);
    write(descripteur_fifo_ecriture, message_ecrit, TAILLE_MAX*sizeof(char));
    printf("évaluation : %s\n", message_ecrit);

    printf(" [*] Envoi de l'évaluation\n");
    
    // Comm-HLR13: Le client récupère la nouvelle cote de classement du titre
    printf(" [*] Nouvelle côte de classement reçue\n");

    char * nc_titre = (char *)malloc(TAILLE_MAX*sizeof(char));

    read(descripteur_fifo_lecture, message_lu, TAILLE_MAX*sizeof(char));
    nc_titre = message_lu;
    printf(" Titre :  %s\n", message_lu);

    char * nc_cote = (char *)malloc(TAILLE_MAX*sizeof(char));

    read(descripteur_fifo_lecture, message_lu, TAILLE_MAX*sizeof(char));
    nc_cote = message_lu;
    printf(" Cote de classement moyenne :  %s \n", message_lu);

    char * nc_vote = (char *)malloc(TAILLE_MAX*sizeof(char));

    read(descripteur_fifo_lecture, message_lu, TAILLE_MAX*sizeof(char));
    nc_vote = message_lu;
    printf(" Nombre de votes :  %s\n", message_lu);
    
    printf(" [-] Fermeture de l'application\n");

    // close(descripteur_fifo_ecriture);
    // close(descripteur_fifo_lecture);

    close(socket_client);
    close(socket_serveur);

    unlink(FIFO_CLIENT);
    unlink(FIFO_SERVEUR);

    return 0;
}


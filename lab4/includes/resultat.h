/**
 * Module resultat - resultat.h
 *
 * Par :Samuel Yactayo-Goulet et Hani OUali
 * Date : Janvier 2023
 * Le module resultat est responsable de gérer les resultats
 * de la recherche effectuee à l'aide de structures encapsulees de données
 */

#ifndef RESULTAT_H
#define RESULTAT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Encapsulation de la structure titre (HLR04)
 * Les champs sont accessibles seulement à l'intérieur du module resultat.c
 */
typedef struct titre* t_titre;

/**
 * Encapsulation de la structure resultat (HLR06)
 * Les champs sont accessibles seulement à l'intérieur du module resultat.c
 */
typedef struct resultat* t_resultat;

/**
 * Constructeur de titre (HLR05)
 *
 * Cette fonction publique permet d'allouer dynamiquement une structure de titre.
 * Elle place des valeurs par défaut dans les membres de celle-ci.
 *
 * Retour : pointeur vers la structure allouée
 */
t_titre creer_titre(void);

/**
 * Constructeur de resultat (HLR07)
 *
 * Cette fonction publique permet d'allouer dynamiquement une structure de resultat.
 * Elle place des valeurs par défaut dans les membres de celle-ci.
 *
 * Retour : pointeur vers la structure allouée
 */
t_resultat creer_resultat(void);


/* MUTATEURS DES CRITÈRES */

/**
 * Mutateur de titre (HLR08)
 *
 * Permet d'ajouter une donnée de titre à la structure resultat.
 *
 * resultat : la structure à modifier
 * titre : chaine de caractères constituant le titre à ajouter
 */
void add_titre(t_resultat resultat, t_titre titre, int numligne);

/* OBSERVATEURS DES TITRES */
t_titre *get_titres(t_resultat resultat);

/**
 * Observateur de d'année de début
 *
 * Permet d'obtenir l'année de début de la structure titre
 *
 * titre : la structure à observer
 *
 * Retour : l'année constituant le début de l'intervalle de la structure donnée
 *          en paramètre
 */
int get_nb_titre(t_resultat resultat);
/**
 * Observateur de constante d'identification
 *
 * Permet d'obtenir la constante d'identification de la structure titre
 *
 * titre : la structure à observer
 *
 * Retour : chaine de caractères constituant la constante d'identification de la structure donnée
 *          en paramètre
 */
char* get_tconst(t_titre titre);

/**
 * Observateur de titre principal
 *
 * Permet d'obtenir le titre principal de la structure titre
 *
 * titre : la structure à observer
 *
 * Retour : chaine de caractères constituant le titre principal de la structure donnée
 *          en paramètre
 */
char* get_primaryTitle(t_titre titre);

/**
 * Observateur de d'année de début
 *
 * Permet d'obtenir l'année de début de la structure titre
 *
 * titre : la structure à observer
 *
 * Retour : l'année constituant le début de l'intervalle de la structure donnée
 *          en paramètre
 */
int get_startYear(t_titre titre);

/**
 * Observateurs de genres
 *
 * Permet d'obtenir les genres de la structure titre
 *
 * titre : la structure à observer
 *
 * Retour : chaine de caractères constituant les genres de la structure donnée
 *          en paramètre
 */
char* get_genres(t_titre titre);

/**
 * Observateurs de type de titre
 *
 * Permet d'obtenir le type de titre de la structure titre
 *
 * titre : la structure à observer
 *
 * Retour : chaine de caractères constituant le type de titre de la structure donnée
 *          en paramètre
 */
char* get_titleType(t_titre titre);
char * get_resultat_tconst(t_resultat resultat, int nb_resultat);

char* get_resultat_genres(t_resultat resultat, int nb_resultat);

char* get_resultat_primaryTitle(t_resultat resultat, int nb_resultat);

int get_resultat_startYear(t_resultat resultat, int nb_resultat);

char* get_resultat_titleType(t_resultat resultat, int nb_resultat);

/**
/* Permet de definir le titre
*
* critere : la structure a modifier
* titre :  titre a ecrire
*/
void set_primaryTitle(t_titre critere, char *titre);
/**
/* Permet de definir le genre
*
* critere : la structure a modifier
* titre :  le genre a ecrire
*/
void set_genres(t_titre critere, char *genre) ;
/**
/* Permet de definir l anner de parution min
*
* critere : la structure a modifier
* titre :  le anner de parution min a ecrire
*/
void set_startYear(t_titre critere, int annee) ;
/**
/* Permet de definir le Tcons
*
* critere : la structure a modifier
* titre :  le Tconst a ecrire
*/
void set_tconst(t_titre critere, char *tconst);
/**
/* Permet de detruire une structure titre
*
* titre : la structure a modifier
*
*/
void detruire_titre(t_titre titre);

/**
/* Permet d ecrire dans un fichier.tsv
*
* Reslultat_ptr : pointeur vers la structure
* nom_fichier :  Le nom du fichier a /crire a l<int/rieur
*/

void t_resultat_ecrire(t_resultat resultat_ptr, const char* nom_fichier);
/**
/* Permet d ecrire dans un fichier.tsv
*
* Reslultat_ptr : pointeur vers la structure
* nom_fichier :  Le nom du fichier a /crire a l<int/rieur
*/
void add_cote(t_resultat resultat, t_titre titre, int nb);
/**
/* Permet d ecrire dans un fichier.tsv
*
* Reslultat_ptr : pointeur vers la structure
* nom_fichier :  Le nom du fichier a /crire a l<int/rieur
*/
int get_resultat_NumVotes(t_resultat resultat, int nb_resultat);
/**
/* Permet d ecrire dans un fichier.tsv
*
* Reslultat_ptr : pointeur vers la structure
* nom_fichier :  Le nom du fichier a /crire a l<int/rieur
*/
double get_resultat_averageRating(t_resultat resultat, int nb_resultat);
/**
/* Permet d afficher les resultat
*
* Reslultat : liste a afficher

*/
affichage_resultat(t_resultat resultat);
/**
/* Permet d ecrire dans un fichier.tsv
*
* Reslultat : lib/ration de la memoire d une stucture
*/
Detruire_resultat(t_resultat resultat);

//HLR05 serveur
/**
/* Calcule de la nouvelle moyenne
*
* titre: titre a evaluer
* evaluation : nouvelle note
*/
void nouvelle_moyenne(t_titre titre,double evaluation);
/**
/* avoir la note d un titre
*
* Titre : titre 
* 
*/
double get_averageRating(t_titre titre);
#endif
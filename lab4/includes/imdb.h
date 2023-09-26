/**
 * Module imbd.h - resultat.h
 *
 * Par :Samuel Yactayo-Goulet
 * Date : Janvier 2023
 * Le module imbd est responsable la recherche filtrer dans les base de donnees et de les stocker dans
 * des structure.
 */
#define _CRT_SECURE_NO_WARNINGS
#define IMBD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "recherche.h"
#include "resultat.h"

#define SUCCESS 1
#define ECHEC 0
//#define DATA_TITRE "../../BD/title_basics.tsv"
//hlr10-11-14
/* Permet de lire dans un fichier TSV tous les résultats
*
* critere : la structure à visualiser
* resultat_rechercher: fichier à lire
*/
t_resultat get_critere(t_critere critere,t_resultat resultat_rechercher);
//hlr12
/* Permet de decomposer une liste de titre d un document
*
* critere : la structure à visualiser
* str : fichier à lire
*/
void decomposition_titre(t_titre critere, char* str);
/**
 * HLR13
 * Permet de comparer un titre du fichier title_basics.tsv aux critères de recherches (HLR13).
 *
 * critere : la structure à modifier
 * titre : chaine de caractères constituant le titre à ajouter
 * resultat : la structure à modifier
 */
int comparer_titre_critere(t_critere critere, t_titre titre);

/**
 * HLR18-HLR19-HLR22
 *
 * Permet de comparer un titre du fichier title_basics.tsv aux critères de recherches et
 * d'ajouter une donnée de titre à la structure resultat.
 *
 * critere : la structure à modifier
 * nom_fichier : lien vers le fichier
 * resultat : la structure à modifier
 * 
 * Retour : pointeur vers la structure allouée
 */
void get_cote(t_resultat critere);
//hlr20
/* Cette fonction permet de decomposer une liste de cote en plusieurs token
*
* critere : le pointeur qui nous permettra de stocker
* str : la ligne a decomposer
*/
void decomposition_cote(t_titre critere, char* str);
/**
 * Permet de comparer un titre du fichier title_ratings.tsv aux titre retenue (HLR21).
 *
 * tconst : la valeaur qui compare les titre.
 * titre : chaine de caractères constituant le titre à ajouter
 */
int comparer_cote_titre(t_resultat resultat, t_titre titre);
//affichage_result(t_resultat resultat);
//hlr7 void changer_cote(t_titre titre);

/**
/* Nouveau document pour les cotes
*
*  Titre: titre a evaluer
* evaluation : Nouvelle note
*/
void changer_cote(t_titre titre,double evaluation);
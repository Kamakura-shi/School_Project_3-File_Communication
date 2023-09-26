
#include "../includes/resultat.h"

/**
 * Structure de données représentant les champs d'une entrée de titre du fichier title_basics.tsv
 *
 * tconst: identifiant unique du film
 * primaryTitle: titre du film
 * startYear: année de parution
 * genres: catégorie du titre
 * titleType: catégorie du titre
 */
struct titre {
    char *tconst;
    char *primaryTitle;
    int startYear;
    char *genres; 
    char *titleType;
    //HLR15
    double averageRating;
    int numVotes;
    int NumLigne ;

};

/**
 * Structure de données représentant les les résultats de recherche
 *
 * t_titre: liste des titres retenus
 * nb_titre: nombre de titres retenus
 */
struct resultat {
    t_titre titre;
    int nb_titre;
};

// Constructeur
t_titre creer_titre(void) {
    t_titre titre;

    titre = (t_titre) malloc(sizeof(struct titre));
    
    if (titre) {
        titre->tconst = NULL;
        titre->primaryTitle = NULL;
        titre->startYear = -1;
        titre->genres = NULL;
        titre->titleType = NULL;
        titre->averageRating = 0;
        titre->numVotes = 0;
    }
    
    return titre;
}

t_resultat creer_resultat(void) {
    t_resultat resultat;

    resultat = (t_resultat)malloc(sizeof(struct resultat));
    
   
    resultat->titre = (t_titre *) malloc((10000)*sizeof(t_titre));
    resultat->nb_titre = 0;

    return resultat;
}

// Mutateurs
void add_titre(t_resultat resultat, t_titre titre, int NumLigne) {


//resultat->titre = (t_titre *) realloc(resultat->titre,(resultat->nb_titre+5)*sizeof(t_titre));
/*if (resultat->titre=NULL){
resultat->titre = (t_titre *) malloc((1000000)*sizeof(t_titre));

}*/

resultat->titre[resultat->nb_titre].tconst=strdup(titre->tconst);
resultat->titre[resultat->nb_titre].genres=strdup(titre->genres);
resultat->titre[resultat->nb_titre].primaryTitle=strdup(titre->primaryTitle);
resultat->titre[resultat->nb_titre].startYear=titre->startYear;
resultat->titre[resultat->nb_titre].titleType=titre->titleType;
resultat->titre[resultat->nb_titre].NumLigne=NumLigne;



/*printf("%s \n",resultat->titre[resultat->nb_titre].tconst);
printf("%s \n",resultat->titre[resultat->nb_titre].genres);
printf("%s \n",resultat->titre[resultat->nb_titre].primaryTitle);
printf("%d \n",resultat->titre[resultat->nb_titre].startYear);
printf("%s \n",resultat->titre[resultat->nb_titre].titleType);*/
//printf("\n");
resultat->nb_titre++;
}
/*HLR16*/
void add_cote(t_resultat resultat, t_titre titre, int nb) {
    resultat->titre[nb].averageRating = titre->averageRating;
    resultat->titre[nb].numVotes = titre->numVotes;
    printf(" %f ",resultat->titre[nb].averageRating);
}

// Observateurs
t_titre *get_titres(t_resultat resultat) {
    return resultat->titre;
}
int get_i_eme_titre(int i, t_resultat resultat) {
    for (int i = 0; i < resultat->nb_titre; i++)
        if (i == resultat->nb_titre)
            return resultat->nb_titre;
}
int get_nb_titre(t_resultat resultat) {
    return resultat->nb_titre;
}

char* get_tconst(t_titre titre) {
    return titre->tconst;
}

char* get_primaryTitle(t_titre titre) {
    return titre->primaryTitle;
}

int get_startYear(t_titre titre) {
    return titre->startYear;
}

char* get_genres(t_titre titre) {
    return titre->genres;
}

char* get_titleType(t_titre titre) {
    return titre->titleType;
}
double get_averageRating(t_titre titre){
    return titre->averageRating;
}

int* get_numVotes(t_titre titre){
    return titre->numVotes;
}

char* get_resultat_tconst(t_resultat resultat, int nb_resultat)
{
    char* tconst = get_tconst(&resultat->titre[nb_resultat].tconst);
return tconst;
}

char* get_resultat_genres(t_resultat resultat, int nb_resultat)
{
return get_genres(&resultat->titre[nb_resultat].genres);
}

char* get_resultat_primaryTitle(t_resultat resultat, int nb_resultat)
{
return get_primaryTitle(&resultat->titre[nb_resultat].primaryTitle);
}

int get_resultat_startYear(t_resultat resultat, int nb_resultat)
{
return get_startYear(resultat->titre[nb_resultat].startYear);

}
char* get_resultat_titleType(t_resultat resultat, int nb_resultat)
{
return get_titleType(&resultat->titre[nb_resultat].titleType);
}

int get_resultat_NumVotes(t_resultat resultat, int nb_resultat)
{
return get_numVotes(resultat->titre[nb_resultat].numVotes);
}

double get_resultat_averageRating(t_resultat resultat, int nb_resultat)
{
return get_averageRating(&resultat->titre[nb_resultat].averageRating);
}

int get_resultat_nb_titre(t_resultat resultat){
return resultat->nb_titre;
}
void set_primaryTitle(t_titre critere, char *titre) {
    critere->primaryTitle= titre;
}

void set_genres(t_titre critere, char *genre) {
    critere->genres = genre;
}

void set_startYear(t_titre critere, int annee) {
    critere->startYear = annee;
}
void set_tconst(t_titre critere, char *tconst) {
    critere->tconst = tconst;
}
void set_titleType(t_titre critere, char *titleType) {
    critere->titleType= titleType;
}
void detruire_titre(t_titre titre) {
    

    free(titre);
}
void set_averageRating(t_titre critere, double averageRating) {
    critere->averageRating = averageRating;
}
void set_numVotes(t_titre critere, int *numVotes) {
    critere->numVotes = numVotes;
}
void t_resultat_ecrire(t_resultat resultat_ptr, const char* nom_fichier)
{
    char* titre = get_titres(resultat_ptr);
    int nb_titre = get_nb_titre(resultat_ptr);
    
    /* Ouvrir le fichier */
	FILE* fichier_ptr = fopen(nom_fichier, "w");

	/* Valider */
	if (fichier_ptr == NULL)
	{
		printf("Impossible d'ouvrir le fichier\n");
		EXIT_FAILURE;
	}

	/* Sauvegarde les composants d'un resultat */
	fprintf(fichier_ptr, "%s\n", titre);
	fprintf(fichier_ptr, "%i\n", nb_titre);

	/* Fermer le fichier */
	fclose(fichier_ptr);

}
affichage_resultat(t_resultat resultat)
{
        int i=0;
int nb_titre = get_nb_titre(resultat);
for(i;i<nb_titre;i++){

printf("[%d] %s %s %s %d %s %0.1lf %d \n",i,resultat->titre[i].tconst,resultat->titre[i].genres,
resultat->titre[i].primaryTitle,resultat->titre[i].startYear,resultat->titre[i].titleType,
resultat->titre[i].averageRating,resultat->titre[i].numVotes);
/*printf("Tconst: %s \n",resultat->titre[i].tconst);
printf("Genre: %s \n",resultat->titre[i].genres);
printf("Primary Title: %s \n",resultat->titre[i].primaryTitle);
printf("Annee :%d \n",resultat->titre[i].startYear);
printf(" Title type: %s \n",resultat->titre[i].titleType);
printf("Rating: %f \n",resultat->titre[i].averageRating);
printf("Nombre de vote: %d \n",resultat->titre[i].numVotes);
printf("Numero de la ligne: %d \n",resultat->titre[i].NumLigne);
printf("\n");*/
}}

Detruire_resultat(t_resultat resultat)
{
        int i=0;
int nb_titre = get_nb_titre(resultat);
for(i;i<nb_titre;i++){
free(resultat->titre[i].tconst);
free(resultat->titre[i].genres);
free(resultat->titre[i].primaryTitle);
//free(resultat->titre[i].startYear);
//free(resultat->titre[i].titleType);
//free(resultat->titre[i].numVotes);

}}
//HLR05 serveur
nouvelle_moyenne(t_titre titre,double evaluation)
{

double Note_actuel;
int nb_vote;
double nouvelle_note;
Note_actuel = get_averageRating(titre);
nb_vote = get_numVotes(titre);
if(nb_vote==0)
    {
        set_averageRating(titre,evaluation);
        set_numVotes(titre,nb_vote+1);
        return;
    }
nouvelle_note = (((Note_actuel*nb_vote)+evaluation)/(nb_vote+1));
        set_averageRating(titre,nouvelle_note);
        set_numVotes(titre,nb_vote+1);

}
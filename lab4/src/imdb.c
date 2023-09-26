


#include "imdb.h"
#include "recherche.h"
#include "resultat.h"

/*H10-H11-H14*/
/*Cette fonction permet daller chercher tout les critere de selection*/
t_resultat get_critere(t_critere critere,t_resultat resultat_rechercher)
{
	const char* nom_fichier;
	char store[1024];
	int i;
	int resultat=0;
    int Numligne = 0;
	t_titre titre = creer_titre();
  //  t_resultat resultat_1 = creer_resultat();
	/* Ouvrir le fichier */
	FILE* fichier_ptr ;
	fichier_ptr = fopen("data/title_basics.tsv", "r");
	//ok
	/* Valider */
	if (fichier_ptr == NULL)
	{
		printf("Impossiiiiiible d'ouvrir le fichier\n");
		return EXIT_FAILURE;
	}
/*passer la premiere ligne*/
//fgets(store,1000,fichier_ptr);
/* Lecture de chaque titre */
 while(fgets(store,sizeof(store),fichier_ptr)!= NULL)
{
if((feof(fichier_ptr)== 0) && (fgets(store,sizeof(store),fichier_ptr)!= NULL))
{
decomposition_titre(titre,store);

resultat = comparer_titre_critere(critere,titre);
    if (resultat == SUCCESS)
    {
    add_titre(resultat_rechercher,titre,Numligne);
    }
    Numligne++;
}
//fgets(store,1024,fichier_ptr);
}
	/*Liberatuion memoire*/
//	detruire_titre(titre);
 //   free(critere);

	/* Fermer le fichier */
	fclose(fichier_ptr);

return resultat_rechercher;
};


//hlr12
void decomposition_titre(t_titre critere, char* str){
//permet de sauter un espace
char* skip;
int ligne;
ligne=0;
//entre les valeur dans une structure titre
set_tconst(critere,strsep(&str, "\t"));
set_titleType(critere,strsep(&str, "\t"));
set_primaryTitle(critere,strsep(&str, "\t"));
skip = strsep(&str, "\t");
skip = strsep(&str, "\t");
set_startYear(critere,atoi(strsep(&str, "\t")));
skip = strsep(&str, "\t");
skip = strsep(&str, "\t");
skip = strsep(&str, "\t");

ligne = strlen(skip);
	skip[ligne - 1] = 0;
	set_genres(critere, skip);

}

int comparer_titre_critere(t_critere critere, t_titre titre) 
{
    
    int valide = SUCCESS;
    int mem_genre = 1, mem_categorie = 1, mem_startyear = 1;
    // La fonction compare : le titre donné; avec : l'argument -t et le titre du champ primaryTitle d'une ligne du
    // fichier de base de données. Le -t indique des titres (primaryTitle).
    // Si un genre, une catégorie de titre et/ou des années de parution sont présents dans les critères de recherches
    // Ils doivent être utilisés pour filtrer les résultats retenus
    // Si les titre corresponde on entre dans la fonction
    if((strcmp(get_titre(critere), get_primaryTitle(titre)) == 0))
    {
            if (get_genre(critere) != 0)
            {
                if(strcmp(get_genres(titre),get_genre(critere))!= 0){
                mem_genre =0;
            }
        }
        if (get_categorie(critere))
        {
            if(strcmp(get_titleType(titre),get_categorie(critere))!= 0)
            {
                mem_categorie = 0;

            }
        }
        if (get_annee_parution_min(critere) != -1 && get_annee_parution_min(critere) != -1)
        {
            if(get_annee_parution_min(critere) <= get_startYear(titre) && get_annee_parution_max(critere) >= get_startYear(titre))
            {
                mem_startyear = 1;
            }
        }
        if(mem_genre == 1 && mem_categorie == 1 && mem_genre == 1)
        {

        return SUCCESS;

        }
        
    }
    return 0;
}


        
    
    // Si le titre donné et celui du champ ne concordent pas, l'entrée n'est pas conservée dans les résultats

void decomposition_cote(t_titre titre, char* str)
{
char* averageRating_temp;
set_tconst(titre,strsep(&str, "\t"));
// atof pour convertir en double
set_averageRating(titre,atof(strsep(&str, "\t")));
// atoi pour convertir en int
set_numVotes(titre,atoi(strsep(&str, "\t")));

}
/*HLR18*/
void get_cote(t_resultat liste)
{
    //initiation variable
	char store[1000];
	char* token;
	int i;
	int resultat=0;
	t_titre titre = creer_titre();
    

	/* Ouvrir le fichier */
	FILE* fichier_ptr ;
	fichier_ptr = fopen("data/title_ratings.tsv", "r");
	
	/* Valider */
	if (fichier_ptr == NULL)
	{
		printf("Impossible d'ouvrir le fichier\n");
		return EXIT_FAILURE;
	}
	/*passer la premiere ligne*/
     fgets(store,1000,fichier_ptr);
/* Lecture de chaque titre */
 while(fgets(store,1000,fichier_ptr)!= NULL)
{
if((feof(fichier_ptr)== 0) && (fgets(store,1000,fichier_ptr)!= NULL))
{
decomposition_cote(titre,store);
comparer_cote_titre(liste,titre);



}}
//Liberatuion memoire
	detruire_titre(titre);
 //Fermer le fichier 
	fclose(fichier_ptr);
    return SUCCESS;
}

int comparer_cote_titre(t_resultat resultat, t_titre titre) {
    int valide = SUCCESS, numVotes = get_numVotes(titre);
    double averageRating = get_averageRating(titre);
    int nb = get_resultat_nb_titre(resultat);
    int i=0;
    for(i;i<nb;i++)
    {
        char* tconst_resultat = get_resultat_tconst(resultat,i);
        char* tconst = get_tconst(titre);
        // Si la cote n'est pas celle d'un des titres retenus, on retourne un indicateur d'échec
            if (strcmp(tconst,tconst_resultat) == 0){
    
            // Il faut que les données de la cote soient ajoutées à la structure de titre qui lui correspond
            add_cote(resultat,titre,i);
             }

    }
    
   return valide = ECHEC;
    
}

/*affichage_result(t_resultat resultat)

{
    int i=0;
int nb_titre = get_nb_titre(resultat);
for(i;i<nb_titre;i++)
    {
        printf("%s \n",get_resultat_tconst(resultat,i));
        printf("%s \n",get_resultat_titleType(resultat,i));
       // printf("%s \n",get_resultat_genres(resultat,i));
       // print*f("%d \n",get_resultat_NumVotes(resultat,i));
        //printf("%s \n",get_resultat_primaryTitle(resultat,i));
       // printf("%f \n",get_resultat_averageRating(resultat,i));
        
        printf("\n");

    }



}*/

//hlr07 a hlr011
void changer_cote(t_titre titre,double evaluation)
{

char* store = (char*)calloc(50,sizeof(char));
char temp[50];
char temporaire[50];
char* tab[3];
t_titre UnTitre =creer_titre();

FILE* lecture;
lecture = fopen("data/title_ratings.tsv", "r");

FILE* ecriture = fopen("data/temp_cote.tsv","w+");


   // fgets(store,1000,lecture);
    /* Lecture de chaque titre */
    sprintf(temporaire,"tconst\t averageRating\tnumVotes");
    fprintf(ecriture,"%s\n",temporaire);
    fgets(store,1000,lecture);
     while(fgets(store,1000,lecture)!= NULL)
    {
         //&& (fgets(store,1000,lecture)!= NULL)
        if((feof(lecture)== 0))
        {
          decomposition_cote(UnTitre,store);
            if (strcmp(get_tconst(titre),get_tconst(UnTitre))!=NULL)
            {
                
                sprintf(temporaire,"%s\t%.1f\t%d",get_tconst(UnTitre),get_averageRating(UnTitre),get_numVotes(UnTitre));
                fprintf(ecriture,"%s\n",temporaire);
		    }
            }
            if (strcmp(get_tconst(titre),get_tconst(UnTitre))==NULL)
         
            {
                //hlr08
             nouvelle_moyenne(UnTitre,evaluation);
                sprintf(temp,"%s\t%.1lf\t%d",get_tconst(UnTitre),get_averageRating(UnTitre),get_numVotes(UnTitre));
                fprintf(ecriture,"%s\n",temp);
            }

        
        //free(temporaire);
        }
         
    
    fclose(ecriture);
    fclose(lecture);
//hlr09
remove("data/title_ratings.tsv");
rename("data/temp_cote.tsv","data/title_ratings.tsv");
}
       

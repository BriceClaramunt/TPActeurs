//
// Created by Brice Claramunt on 09/11/2020.
//
#include "actors.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//Fonction permettant de récupérer la propriété nameJob d'un artiste, de type enum job, et d'afficher une string à partir de cette variable
void writeJob(enum job nameJob) {
    switch (nameJob) {
        case 0:
            printf("Metier : Acteur\n");
            break;
        case 1:
            printf("Metier : Realisateur\n");
            break;
        case 2:
            printf("Metier : Acteur-Realisateur\n");
            break;
        default:
            printf("Metier non reconnu\n");
    }}

//fonction permettant de comparer un token avec la string voulue, si la condition est respectée la propriété nameJob prendra la valeur voulue.
enum job writeEnum (char *token, enum job nameJob)
{
    if(strcmp(token,"Acteur") == 0)
        nameJob = actor;
    if(strcmp(token,"Realisateur") == 0)
        nameJob = director;
    if(strcmp(token,"Acteur-Realisateur") == 0)
        nameJob = actorDirector;
    return nameJob;

}

//fonction permettant d'afficher la fiche Artiste d'un artiste spécifique, spécifié comme paramètre de la fonction.
void displayArtist (artist artistName)
{
    printf("\nFiche ARTISTE \n");
    printf("Nom : %s %s \n", artistName.surname, artistName.name);
    printf("Date de naissance : %s \n", artistName.dateOfBirth);
    printf("Nationalite : %s \n", artistName.nationality);
    writeJob(artistName.nameJob);
    printf("Films associes a l'artiste: %s\n", artistName.moviesPlayed);


}

//fonction qui affiche la liste entière des artistes contenant dans le fichier .txt
void displayAllArtists (FILE* fileRead)
{
    FILE* file= fopen("acteurs.txt","r+");

    if (file == NULL) {
        perror("Le fichier acteurs.txt ne peut pas être lu");
        exit(1);
    }

    char string[200];



    while (fgets(string, sizeof(string), file)) {
        int i = 0;
        artist tmp;

        char *token;
        token = strtok(string,";");
        while (token != NULL) {
            switch (i) {
                case 0:
                    tmp.surname = token;
                    break;
                case 1:
                    tmp.name = token;
                    break;
                case 2:
                    tmp.dateOfBirth= token;
                    break;
                case 3:
                    tmp.nationality = token;
                    break;
                case 4:
                    tmp.nameJob = writeEnum(token, tmp.nameJob);
                    break;
                case 5:
                    tmp.moviesPlayed = token;
                    break;

            }
            token = strtok(NULL,";");
            ++i;

        }
        displayArtist(tmp);

    }
    fclose(file);
}

//fonction qui ajoute un artiste dans le fichier .txt
void addArtist()
{
    char* prenom= malloc(sizeof(*prenom) * 256);
    char* nom= malloc(sizeof(*nom) * 256);
    char* date= malloc(sizeof(*date) * 256);
    char* nationalite= malloc(sizeof(*nationalite) * 256);
    char* job= malloc(sizeof(*job) * 256);
    char* films= malloc(sizeof(*films) * 256);




    printf("Quel est le prenom de l'artiste que vous voulez ajouter? \n");
    scanf("%s",prenom);

    printf("Le nom : \n");
    scanf("%s", nom);

    printf("La date de naissance : \n");
    scanf("%s", date);

    printf("La nationalite : \n");
    scanf("%s", nationalite);

    printf("Le metier : (Acteur, Realisateur ou bien Acteur-Realisateur)\n");
    scanf("%s", job);

    printf("Les films auquel il a contribue : \n");
    scanf("%s", films);

    FILE *fichier = fopen("acteurs.txt", "a");
    fprintf(fichier, "%s;%s;%s;%s;%s;%s\n", prenom, nom, date, nationalite, job, films);
    printf("Votre artiste a bien ete ajoute!");
    fclose(fichier);

}

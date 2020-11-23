//
// Created by Brice Claramunt on 09/11/2020.
//

#include <stdio.h>
#include "film.h"
#include <string.h>
#include <stdlib.h>


//fonction qui permet de récupérer la propriété du genre du film, de type enum movieGenre, et d'afficher la string voulue suivant la valeur de movieGenre.
void writeGenre(enum movieGenre nameGenre) {
    switch (nameGenre) {
        case 0:
            printf("Genre : Action\n");
            break;
        case 1:
            printf("Genre : Horreur\n");
            break;
        case 2:
            printf("Genre : Comedie\n");
            break;
        case 3:
            printf("Genre : Documentaire\n");
            break;
        case 4:
            printf("Genre : Policier\n");
            break;
        case 5:
            printf("Genre : Drame\n");
            break;
        case 6:
            printf("Genre : Animation\n");
            break;
        case 7:
            printf("Genre : Science-Fiction\n");
            break;
        default:
            printf("Genre inexistant\n");
    }
}

//fonction qui compare un token à la string souhaitée, et par la suite attribue la valeur voulue à la propriété nameGenre si les deux chaines sont égales.
enum movieGenre writeMovieGenre (char *token, enum movieGenre nameGenre)
{
    if(strcmp(token,"Action") == 0)
        nameGenre = Action;
    if(strcmp(token,"Horreur") == 0)
        nameGenre = Horreur;
    if(strcmp(token,"Comedie") == 0)
        nameGenre = Comedie;
    if(strcmp(token,"Documentaire") == 0)
        nameGenre = Documentaire;
    if(strcmp(token,"Policier") == 0)
        nameGenre = Policier;
    if(strcmp(token,"Drame") == 0)
        nameGenre = Drame;
    if(strcmp(token,"Animation") == 0)
        nameGenre = Animation;
    if(strcmp(token,"Science-Fiction") == 0)
        nameGenre = ScienceFiction;
    return nameGenre;

}

//fonction qui affiche une fiche film d'un film rentré en paramètre
void displayMovie(movie movieName)
{
    printf("\nFiche FILM\n");
    printf( "%s (%u) \n", movieName.title, movieName.yearRelease);
    printf("Realisateur : %s %s \n", movieName.nameDirector.surname, movieName.nameDirector.name);
    printf("Acteurs : %s %s, %s %s, %s %s \n", movieName.mainActor1.surname, movieName.mainActor1.name, movieName.mainActor2.surname, movieName.mainActor2.name, movieName.mainActor3.surname, movieName.mainActor3.name);
    printf("Duree : %u min \n", movieName.movieTime);
    writeGenre(movieName.nameGenre);

}

//fonction qui affiche tous les films contenus dans le fichier .txt
void displayAllMovies (FILE* fileRead)
{
    FILE* file= fopen("films.txt","r+");

    if (file == NULL) {
        perror("Le fichier films.txt ne peut pas être lu");
        exit(1);
    }

    char string[200];



    while (fgets(string, sizeof(string), file)) {
        int i = 0;
        movie tmp;

        char *token;
        token = strtok(string,";");
        while (token != NULL) {
            switch (i) {
                case 0:
                    tmp.title = token;
                    break;
                case 1:
                    tmp.yearRelease = strtol(token,NULL,0);
                    break;
                case 2:
                    tmp.nameDirector.surname = token;
                    break;
                case 3:
                    tmp.nameDirector.name = token;
                    break;
                case 4:
                    tmp.mainActor1.surname = token;
                    break;
                case 5:
                    tmp.mainActor1.name = token;
                    break;
                case 6:
                    tmp.mainActor2.surname = token;
                    break;
                case 7:
                    tmp.mainActor2.name = token;
                    break;
                case 8:
                    tmp.mainActor3.surname = token;
                    break;
                case 9:
                    tmp.mainActor3.name = token;
                    break;
                case 10:
                    tmp.movieTime = strtol(token,NULL,0);;
                    break;
                case 11:
                    tmp.nameGenre = writeMovieGenre(token, tmp.nameGenre);
                    break;
            }
            token = strtok(NULL,";");
            ++i;

        }
        displayMovie(tmp);

    }
    fclose(file);
}


//fonction de recherche d'un film dans le fichier .txt, à partir d'un titre entré par l'utilisateur
void findMovie(char *titre) {
    FILE *thefile = fopen("films.txt", "r+");

    if (thefile == NULL) {
        perror("Unable to open the file");
        exit(1);
    }
    char line[200];
    char line1[200];
    int i = 0;
    while (fgets(line, sizeof(line), thefile)) {
        strcpy(line1, line);

        char *token;
        token = strtok(line, ";");

        if (strcmp(token, titre) == 0) {
            printf("Le film %s existe bien dans notre liste\n", line);
            printf("%s", line1);
            printf("N'hesitez pas a afficher la liste de tous nos films pour retrouver la fiche FILM de %s\n", line);
            token = strtok(NULL, ";");
            i++;
        }
        fclose(thefile);
    }
    if (i == 0)
        printf("On a pas de film %s dans notre filmotheque", titre);

}

//fonction qui permet d'ajouter un film dans le fichier .txt
void addMovie()
{
    char * title= malloc(sizeof(*title) * 256);
    char* yearRelease= malloc(sizeof(*yearRelease) * 256);
    char* surnameDirector= malloc(sizeof(*surnameDirector) * 256);
    char* nameDirector= malloc(sizeof(*nameDirector) * 256);
    char* surnameMainActor1= malloc(sizeof(*surnameDirector) * 256);
    char* nameMainActor1= malloc(sizeof(*nameMainActor1) * 256);
    char* surnameMainActor2= malloc(sizeof(*surnameMainActor2) * 256);
    char* nameMainActor2= malloc(sizeof(*nameMainActor2) * 256);
    char* surnameMainActor3= malloc(sizeof(*surnameMainActor3) * 256);
    char* nameMainActor3= malloc(sizeof(*nameMainActor3) * 256);
    char* movieTime= malloc(sizeof(*movieTime) * 256);
    char* nameGenre= malloc(sizeof(*nameGenre) * 256);


    printf("Quel est le titre du film que vous voulez ajouter? \n");
    scanf("%s",title);
    printf("L'annee de sortie du film: \n");
    scanf("%s", yearRelease);
    printf("Le prenom du realisateur : \n");
    scanf("%s", surnameDirector);
    printf("Le nom du réalisateur : \n");
    scanf("%s", nameDirector);
    printf("Le prenom du 1er acteur principal : \n");
    scanf("%s", surnameMainActor1);
    printf("Le nom du 1er acteur principal : \n");
    scanf("%s", nameMainActor1);
    printf("Le prenom du 2eme acteur principal : \n");
    scanf("%s", surnameMainActor2);
    printf("Son nom : \n");
    scanf("%s", nameMainActor2);
    printf("Le prenom du 3eme acteur principal : \n");
    scanf("%s", surnameMainActor3);
    printf("Le nom du 3eme acteur principal : \n");
    scanf("%s", nameMainActor3);
    printf("La duree du film (en minutes) :\n");
    scanf("%s", movieTime);
    printf("Quel est le genre du film ? (Parmi : Action, Horreur, Comedie, Documentaire, Policier, Drame, Animation, ScienceFiction)\n");
    scanf("%s", nameGenre);

    FILE* fichier = fopen("films.txt","a");
    fprintf(fichier, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",title, yearRelease, surnameDirector, nameDirector, surnameMainActor1, nameMainActor1, surnameMainActor2, nameMainActor2, surnameMainActor3, nameMainActor3, movieTime, nameGenre);
    printf("Votre film a bien ete ajoute!");
    fclose(fichier);

}


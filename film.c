//
// Created by Brice Claramunt on 09/11/2020.
//

#include <stdio.h>
#include "film.h"
#include <string.h>
#include <stdlib.h>



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
    return nameGenre;

}


void displayMovie(movie movieName)
{
    printf("\nFiche FILM\n");
    printf( "%s (%u) \n", movieName.title, movieName.yearRelease);
    printf("Realisateur : %s %s \n", movieName.nameDirector.surname, movieName.nameDirector.name);
    printf("Acteurs : %s %s, %s %s, %s %s \n", movieName.mainActor1.surname, movieName.mainActor1.name, movieName.mainActor2.surname, movieName.mainActor2.name, movieName.mainActor3.surname, movieName.mainActor3.name);
    printf("Duree : %u min \n", movieName.movieTime);
    writeGenre(movieName.nameGenre);

}

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

}



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
//on peut rajouter un nouveau film ici et lui attribuer toutes ses propriétés si j'ai le temps, afin de pouvoir utiliser displayMovie

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

void addMovie(FILE *file)
{
    FILE* fichier = fopen("films.txt","a");
    movie movieAdded;
    printf("Quel est le titre du film que vous voulez ajouter? \n");
    scanf("%s",movieAdded.title);
    printf("L'annee de sortie du film: \n");
    scanf("%u", &movieAdded.yearRelease);
    printf("Le prénom du realisateur : \n");
    scanf("%s", movieAdded.nameDirector.surname);
    printf("Le nom du realisateur : \n");
    scanf("%s", movieAdded.nameDirector.name);
    printf("Le prenom du 1er acteur principal : \n");
    scanf("%s", movieAdded.mainActor1.surname);
    printf("Son nom : \n");
    scanf("%s", movieAdded.mainActor1.name);
    printf("Le prenom du 2eme acteur principal : \n");
    scanf("%s", movieAdded.mainActor2.surname);
    printf("Son nom : \n");
    scanf("%s", movieAdded.mainActor2.name);
    printf("Le prenom du 3eme acteur principal : \n");
    scanf("%s", movieAdded.mainActor3.surname);
    printf("Son nom : \n");
    scanf("%s", movieAdded.mainActor3.name);
    printf("La duree du film (en minutes)");
    scanf("%u", &movieAdded.movieTime);
    printf("Quel est le genre du film ? (Parmi : Action, Horreur, Comedie, Documentaire, Policier, Drame, Animation, ScienceFiction");
    scanf("%s", movieAdded.nameGenre);


    fprintf(fichier, "%s;%u;%s;%s;%s;%s;%s;%s;%s;%s;%u;%s", movieAdded.title, movieAdded.yearRelease, movieAdded.nameDirector.surname, movieAdded.nameDirector.name, movieAdded.mainActor1.surname, movieAdded.mainActor1.name, movieAdded.mainActor2.surname, movieAdded.mainActor2.name, movieAdded.mainActor3.surname, movieAdded.mainActor3.name, movieAdded.movieTime, movieAdded.nameGenre);


}


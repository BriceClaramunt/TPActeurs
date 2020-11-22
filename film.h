//
// Created by Brice Claramunt on 11/11/2020.
//

#ifndef UNTITLED_FILM_H
#define UNTITLED_FILM_H

#endif //UNTITLED_FILM_H

#include <stdio.h>
#include "actors.h"

enum movieGenre { Action, Horreur, Comedie, Documentaire, Policier, Drame, Animation, ScienceFiction } ;

//structure contenant toutes les propriétés d'un film
//faire une fonction créer artiste avec le rôle soit de réalisateur soit d'acteur
//ATTENTION, probablement revoir les pointeurs car l'idéal serait que le réalisateur et les acteurs pointent vers leur emplacement mémoire afin de récupérer leur nom.
typedef struct s_movie
{
    char *title;
    unsigned int yearRelease;
    artist nameDirector;
    artist mainActor1;
    artist mainActor2;
    artist mainActor3;
    unsigned int movieTime;
    enum movieGenre nameGenre;
} movie;



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
    printf("Fiche FILM\n");
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

movie findMovie (movie movieTitle)
{
    
}
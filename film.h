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



void displayMovie(movie movieName)
{
    printf("Fiche FILM\n");
    printf( "%s (%u) \n", movieName.title, movieName.yearRelease);
    printf("Realisateur : %s %s \n", movieName.nameDirector.surname, movieName.nameDirector.name);
    printf("Acteurs : %s %s, %s %s, %s %s \n", movieName.mainActor1.surname, movieName.mainActor1.name, movieName.mainActor2.surname, movieName.mainActor2.name, movieName.mainActor3.surname, movieName.mainActor3.name);
    printf("Duree : %u min \n", movieName.movieTime);
    writeGenre(movieName.nameGenre);

}



movie findMovie (movie movieTitle)
{
    
}
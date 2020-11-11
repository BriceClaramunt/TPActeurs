//
// Created by Brice Claramunt on 11/11/2020.
//

#ifndef UNTITLED_FILM_H
#define UNTITLED_FILM_H

#endif //UNTITLED_FILM_H

#include <stdio.h>
#include "actors.h"

//structure contenant toutes les propriétés d'un film
//ATTENTION, le genre du film parmi une sélection : comment faire ?
//ATTENTION, probablement revoir les pointeurs car l'idéal serait que le réalisateur et les acteurs pointent vers leur emplacement mémoire afin de récupérer leur nom.
typedef struct s_movie
{
    char *title;
    unsigned int yearRelease;
    director nameDirector;
    actor mainActor1;
    actor mainActor2;
    actor mainActor3;
    unsigned int movieTime;
    char *movieGenre;
} movie;

void displayMovie(movie movieName)
{
    printf("Fiche FILM\n");
    printf( "%s (%u) \n", movieName.title, movieName.yearRelease);
    printf("Realisateur : %s %s \n", movieName.nameDirector.surname, movieName.nameDirector.name);
    printf("Acteurs : %s %s, %s %s, %s %s \n", movieName.mainActor1.surname, movieName.mainActor1.name, movieName.mainActor2.surname, movieName.mainActor2.name, movieName.mainActor3.surname, movieName.mainActor3.name);
    printf("Duree : %u min \n", movieName.movieTime);
    printf("Genre : %s \n", movieName.movieGenre);
}

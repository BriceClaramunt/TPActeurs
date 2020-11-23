//
// Created by Brice Claramunt on 11/11/2020.
//

#ifndef UNTITLED_FILM_H
#define UNTITLED_FILM_H
#include "actors.h"

#endif //UNTITLED_FILM_H

enum movieGenre { Action, Horreur, Comedie, Documentaire, Policier, Drame, Animation, ScienceFiction } ;

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

void writeGenre(enum movieGenre nameGenre);
enum movieGenre writeMovieGenre (char *token, enum movieGenre nameGenre);
void displayMovie(movie movieName);
void displayAllMovies (FILE* fileRead);
void findMovie(char *titre);
void addMovie(FILE *file);


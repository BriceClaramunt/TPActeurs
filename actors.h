//
// Created by Brice Claramunt on 09/11/2020.
//

#include <mbstring.h>

#ifndef UNTITLED_ACTORS_H
#define UNTITLED_ACTORS_H

#endif //UNTITLED_ACTORS_H

enum job {actor, director, actorDirector};


typedef struct s_art
{
    char *name;
    char *surname;
    char *dateOfBirth;
    char *nationality;
    enum job nameJob;
    char *moviesPlayed;
} artist;

void writeJob(enum job nameJob);
enum job writeEnum (char *token, enum job nameJob);
void displayArtist (artist artistName);
void displayAllArtists (FILE* fileRead);
void addArtist(FILE *file);
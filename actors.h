//
// Created by Brice Claramunt on 09/11/2020.
//

#ifndef UNTITLED_ACTORS_H
#define UNTITLED_ACTORS_H

#endif //UNTITLED_ACTORS_H

//structure contenant toutes les propriétés d'un acteur.
typedef struct s_act
{
    const char *name;
    const char *surname;
    const char *dateOfBirth;
    const char *nationality;
} actor;

//structure contenant toutes les propriétés d'un réalisateur.
typedef struct s_director
{
    const char *name;
    const char *surname;
    const char *dateOfBirth;
    const char *nationality;
} director;

//on peut facilement améliorer la date de naissance, en faisant une structure pour cette dernière.
//Si j'ai le temps, faire cette date de naissance (voir page 23 du cours 6)


void displayDirector (director directorName)
{
    printf("Fiche REALISATEUR \n");
    printf("Nom : %s %s \n", directorName.surname, directorName.name);
    printf("Date de naissance : %s \n", directorName.dateOfBirth);
    printf("Nationalite : %s \n\n", directorName.nationality);
}
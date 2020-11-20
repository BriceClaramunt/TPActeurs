#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "film.h"
#define STRING_SIZE 1000



//vérifier si les prototypes doivent aussi être mis dans le .h
void displayMovie (movie);
void displayArtist (artist);
void mainMenu();

int main() {

    mainMenu();

    movie avatar;
    artist jamesCameron;
    artist zoeSaldana;
    artist samWorthington;
    artist sigourneyWeaver;
    zoeSaldana.surname = "Zoe";
    zoeSaldana.name = "Saldana";
    samWorthington.surname = "Sam";
    samWorthington.name = "Worthington";
    sigourneyWeaver.surname = "Sigourney";
    sigourneyWeaver.name = "Weaver";
    jamesCameron.name = "Cameron";
    jamesCameron.surname = "James";
    jamesCameron.dateOfBirth = "16 Aout 1954";
    jamesCameron.nationality = "Canadienne";
    jamesCameron.nameJob = actorDirector;
    avatar.nameDirector = jamesCameron;
    avatar.title = "Avatar";
    avatar.yearRelease = 2010;
    avatar.mainActor1 = jamesCameron;
    avatar.mainActor2 = zoeSaldana;
    avatar.mainActor3 = sigourneyWeaver;
    avatar.movieTime = 162;
    avatar.nameGenre = ScienceFiction;

    displayMovie(avatar);
    displayArtist(jamesCameron);

    FILE* fichier = NULL;
    char string[STRING_SIZE] = "";
    char tmp[10];

    fichier = fopen("acteurs.txt", "r+");
    if (fichier != NULL)
    {
        while (fgets(string, STRING_SIZE, fichier) != NULL)
        {
            //test avec la date, nationalité et le métier
            fscanf(fichier, ": %s; %s; %s;", &tmp[0], &tmp[1], &tmp[2]);
            printf("Date Nationalite et metier : %s, %s et %s", &tmp[0], &tmp[1], &tmp[2]);


        }

    }
    else
    {
        // On affiche un message d'erreur
        printf("Le fichier acteurs.txt ne peut pas être lu.");
    }

    return 0;
}


void mainMenu ()
{
    unsigned int choice;
    printf("Bienvenue dans cette application pour les cinephiles!\nMENU =\n\n[1] Lister les films\n[2] Lister les artistes\n[3] Rajouter un film\n[4] Rajouter un artiste\n[5] Rechercher un film par titre\n[6] Quitter l'application\n\n");
    printf("Entrez votre choix :\n\n");
    //scanf("%u", choice);
    switch (choice) {

    }
}

//ce qu'il reste à faire : implémenter la base de données (fichier .txt ou .csv), puis les fonction du menu c'est-à-dire:
//rechercher un film par son titre(film existe ou non), lister tous les films et tous les artistes?, rechercher un artiste, rajouter un film
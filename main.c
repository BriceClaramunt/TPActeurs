#include <stdio.h>
#include <stdlib.h>
#include "film.h"



//vérifier si les prototypes doivent aussi être mis dans le .h
void displayMovie (movie);
void displayDirector (director);
void mainMenu();

int main() {

    mainMenu();
    movie avatar;
    director jamesCameron;
    actor zoeSaldana;
    actor samWorthington;
    actor sigourneyWeaver;
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
    avatar.nameDirector = jamesCameron;
    avatar.title = "Avatar";
    avatar.yearRelease = 2010;
    avatar.mainActor1 = samWorthington;
    avatar.mainActor2 = zoeSaldana;
    avatar.mainActor3 = sigourneyWeaver;
    avatar.movieTime = 162;
    avatar.movieGenre = "Science-Fiction";
    displayMovie(avatar);
    displayDirector(jamesCameron);
    return 0;
}


void mainMenu ()
{
    unsigned int choice;
    printf("Bienvenue dans cette application pour les cinephiles!\nMENU =\n\n[1] Lister les films\n[2] Lister les realisateurs\n[3] Rechercher un film par titre\n[4] Quitter l'application\n\n");
    printf("Entrez votre choix :");
    scanf("%u", choice);
    switch (choice) {
        case 1:


    }
}
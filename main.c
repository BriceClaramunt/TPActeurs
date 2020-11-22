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

    //mainMenu();

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

//    displayMovie(avatar);
//    displayArtist(jamesCameron);

    FILE* fichier = NULL;
    displayAllMovies(fichier);
}


//void mainMenu ()
//{
//    unsigned int choice;
//    FILE* fichier = NULL;
//    printf("Bienvenue dans cette application pour les cinephiles!\nMENU =\n\n[1] Lister les films\n[2] Lister les artistes\n[3] Rajouter un film\n[4] Rajouter un artiste\n[5] Rechercher un film par titre\n[6] Quitter l'application\n\n");
//    printf("Entrez votre choix :\n\n");
//    //scanf("%u", choice);
//    switch (choice) {
//        case 1:
//            displayAllMovies(fichier);
//            break;
//        case 2:
//            displayAllArtists(fichier);
//            break;
//        case 3:
//            addMovie(fichier);
//            break;
//        case 4:
//            addArtist(fichier);
//            break;
//        case 5:
//            findMovie(movieTitle);
//            break;
//        case 6:
//              Quitter l'application (exit 0? mettre un default ??)
//
//    }
//}

//ce qu'il reste à faire : implémenter la base de données (fichier .txt ou .csv), puis les fonctions du menu c'est-à-dire:
//rechercher un film par son titre(film existe ou non), rechercher un artiste, rajouter un film
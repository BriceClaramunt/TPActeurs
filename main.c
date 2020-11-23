#include <stdio.h>
#include <stdlib.h>
#include "film.h"

//Nous avons fait ce programme, Brice CLARAMUNT et Nabil EL BARKAOUI, et vous pouvez retrouvez le code sur ce git :
//https://github.com/BriceClaramunt/TPActeurs
//Nous sommes plutôt satisfaits des fonctions remplies par notre programme, même si nous sommes conscients de certaines faiblesses:
//la sensibilité à la casse, la non-vérification dans les fichiers .txt des artistes ajoutés ou bien des films.


void mainMenu();



int main() {

    mainMenu();


}


//fonction permettant de déployer le menu du programme.
void mainMenu ()
{
    unsigned int choice;
    FILE* fichier = NULL;
    int quitter=0;
    char *titre = malloc(sizeof(*titre) * 256);
    printf("Bienvenue dans cette application pour les cinephiles!\nMENU =\n\n[1] Lister les films\n[2] Lister les artistes\n[3] Rajouter un film\n[4] Rajouter un artiste\n[5] Rechercher un film par titre\n[6] Quitter l'application\n\n");
    printf("SVP, veuillez a bien respecter la casse, a eviter les espaces lorsque vous rentrez le nom d'un artiste ou d'un film \n(preferez un - ou un /)\n");
    printf("Entrez votre choix :\n");
    scanf("%u", &choice);

        switch (choice) {
            case 1:
                displayAllMovies(fichier);
                break;
            case 2:
                displayAllArtists(fichier);
                break;
            case 3:
                addMovie();
                displayAllMovies(fichier);
                break;
            case 4:
                addArtist();
                displayAllArtists(fichier);
                break;
            case 5:
                printf("Tapez le nom du film que vous cherchez :\n");
                scanf("%s", titre);
                findMovie(titre);
                break;
            case 6:
                printf("Merci d'avoir utilise notre application !");
                break;
            default:
                printf("Tapez un numero parmi les choix possibles svp!");
                break;

    }
}

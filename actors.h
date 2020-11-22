//
// Created by Brice Claramunt on 09/11/2020.
//

#ifndef UNTITLED_ACTORS_H
#define UNTITLED_ACTORS_H

#endif //UNTITLED_ACTORS_H

enum job {actor, director, actorDirector};

//structure contenant toutes les propriétés d'un acteur.
//afficher artiste 0 = afficher que les artistes, 1 que les réalisateurs, 2 acteur réalisateurs
typedef struct s_art
{
    const char *name;
    const char *surname;
    const char *dateOfBirth;
    const char *nationality;
    enum job nameJob;
} artist;


//on peut facilement améliorer la date de naissance, en faisant une structure pour cette dernière.
//Si j'ai le temps, faire cette date de naissance (voir page 23 du cours 6)

void writeJob(enum job nameJob) {
    switch (nameJob) {
        case 0:
            printf("Metier : Acteur\n");
            break;
        case 1:
            printf("Metier : Realisateur\n");
            break;
        case 2:
            printf("Metier : Acteur-Realisateur\n");
            break;
        default:
            printf("Metier non reconnu\n");
    }}

void displayArtist (artist artistName)
{
    printf("\nFiche ARTISTE \n");
    printf("Nom : %s %s \n", artistName.surname, artistName.name);
    printf("Date de naissance : %s \n", artistName.dateOfBirth);
    printf("Nationalite : %s \n", artistName.nationality);
    writeJob(artistName.nameJob);

}

//ou alors récupérer chaque nom d'artiste dans la liste, et appeler displayArtist pour chacun des artistes ?
void displayAllArtists (FILE* fileRead)
{
    FILE* file= fopen("acteurs.txt","r+");

    if (file == NULL) {
        perror("Le fichier acteurs.txt ne peut pas être lu");
        exit(1);
    }

    char string[200];



    while (fgets(string, sizeof(string), file)) {
        int i = 0;
        artist tmp;

        char *token;
        token = strtok(string,";");
        while (token != NULL) {
            switch (i) {
                case 0:
                    tmp.surname = token;
                    break;
                case 1:
                    tmp.name = token;
                    break;
                case 2:
                    tmp.dateOfBirth= token;
                    break;
                case 3:
                    tmp.nationality = token;
                    break;
                case 4:
                    tmp.nameJob = actor;
                    break;

            }
            token = strtok(NULL,";");
            ++i;

        }
        displayArtist(tmp);
//        printf("\n");
    }

}

//
// Created by Brice Claramunt on 09/11/2020.
//

#ifndef UNTITLED_ACTORS_H
#define UNTITLED_ACTORS_H

#endif //UNTITLED_ACTORS_H

enum job {actor, director, actorDirector};


typedef struct s_art
{
    const char *name;
    const char *surname;
    const char *dateOfBirth;
    const char *nationality;
    enum job nameJob;
    const char *moviesPlayed;
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

enum job writeEnum (char *token, enum job nameJob)
{
    if(strcmp(token,"Acteur") == 0)
        nameJob = actor;
    if(strcmp(token,"Realisateur") == 0)
        nameJob = director;
    if(strcmp(token,"Acteur-Realisateur") == 0)
        nameJob = actorDirector;
    return nameJob;

}

void displayArtist (artist artistName)
{
    printf("\nFiche ARTISTE \n");
    printf("Nom : %s %s \n", artistName.surname, artistName.name);
    printf("Date de naissance : %s \n", artistName.dateOfBirth);
    printf("Nationalite : %s \n", artistName.nationality);
    writeJob(artistName.nameJob);
    printf("Films associes a l'artiste: %s\n", artistName.moviesPlayed);


}

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
                    tmp.nameJob = writeEnum(token, tmp.nameJob);
                    break;
                case 5:
                    tmp.moviesPlayed = token;
                    break;

            }
            token = strtok(NULL,";");
            ++i;

        }
        displayArtist(tmp);
    }
}


void addArtist()
{

}

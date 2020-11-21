//
// Created by Brice Claramunt on 09/11/2020.
//

#ifndef UNTITLED_ACTORS_H
#define UNTITLED_ACTORS_H

#endif //UNTITLED_ACTORS_H

enum job {actor, director, actorDirector};

//structure contenant toutes les propriétés d'un acteur.
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
displayAllArtists (FILE* fileRead)
{
    char *string1;
    fileRead = fopen("acteurs.txt", "r+");

    if (fileRead != NULL)
    {
        while (fgets(string1, sizeof(string1), fileRead) != NULL)
        {
            printf("%s", string1);
        }
        fclose(fileRead);
    }
    else
    {
    // On affiche un message d'erreur
    printf("Le fichier acteurs.txt ne peut pas être lu.");
    }
    return 0;
}
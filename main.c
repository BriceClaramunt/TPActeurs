#include <stdio.h>
#include "film.h"

void displayMovie (movie);
void displayDirector (director);

int main() {

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

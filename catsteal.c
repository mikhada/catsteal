#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BASE_CATS_PER_MINUTE 5   // Base rate of stealing cats per minute
#define FERRET_CHANCE 5          // Chance to accidentally steal a ferret

int main() {
    int total_cats, cats_stolen = 0, ferrets_stolen = 0;
    int police_arrival_time;

    // Seed the random number generator
    srand(time(NULL));

    // Get number of cats in the store
    printf("Enter the number of cats in the pet store: ");
    if (scanf("%d", &total_cats) != 1 || total_cats <= 0) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    police_arrival_time = (rand() % 9) + 2; //(2 to 10 minutes)

    for (int i = 0; i < police_arrival_time; i++) {
        int cats_this_minute = BASE_CATS_PER_MINUTE - (rand() % 3);

        for (int j = 0; j < cats_this_minute; j++) {
            if (cats_stolen + ferrets_stolen >= total_cats) {
                break;
            }

            if ((rand() % 100) < FERRET_CHANCE) {
                ferrets_stolen++;
            } else {
                cats_stolen++;
            }
        }
    }

    // Output result
    printf("The police arrived in %d minutes.\n", police_arrival_time);
    printf("You managed to steal %d cats before getting caught.\n", cats_stolen);
    if (ferrets_stolen > 0) {
        printf("You also accidentally stole %d ferret%s.\n", ferrets_stolen, ferrets_stolen == 1 ? "" : "s");
    }

    return 0;
}

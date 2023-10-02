#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber, guess, attempts = 1;
    srand(time(0));
    secretNumber = rand() % 100 + 1;

    do {
        printf("Guess the number between 1 to 100\n");
        scanf("%d", &guess);

        if (guess > secretNumber) {
            printf("Lower number please\n");
        } else if (guess < secretNumber) {
            printf("Higher number please\n");
        } else {
            printf("You guessed it in %d attempts\n", attempts);
        }

        attempts++;
    } while (guess != secretNumber);

    return 0;
}

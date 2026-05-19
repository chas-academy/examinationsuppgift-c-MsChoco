//W#include <stdio.h>
#include <ctype.h>

void formatName(char name[]) {
    name[0] = toupper(name[0]);

    for (int i = 1; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }
}

int main() {

    char names[5][11];
    int scores[5][13];

    float averages[5];
    float totalAverage = 0;

    for (int i = 0; i < 5; i++) {

        scanf("%10s", names[i]);

        int sum = 0;

        for (int j = 0; j < 13; j++) {

            scanf("%d", &scores[i][j]);

            sum += scores[i][j];
        }

        averages[i] = sum / 13.0;

        totalAverage += averages[i];
    }

    totalAverage = totalAverage / 5.0;

    for (int i = 0; i < 5; i++) {
        formatName(names[i]);
    }

    int bestIndex = 0;

    for (int i = 1; i < 5; i++) {

        if (averages[i] > averages[bestIndex]) {
            bestIndex = i;
        }
    }

    printf("%s\n", names[bestIndex]);

    for (int i = 0; i < 5; i++) {

        if (averages[i] < totalAverage &&
            i != bestIndex) {

            printf("%s\n", names[i]);
        }
    }

    return 0;
}


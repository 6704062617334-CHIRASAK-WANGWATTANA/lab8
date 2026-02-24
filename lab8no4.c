#include <stdio.h>

void select(int score[], int best3[], int size);
void sort(int score[], int best3[], int size);
void printAr(int numAr[], int numArSize);

int main() {

    int score1[4] = {65, 80, 75, 90};
    int score2[4] = {65, 80, 75, 90};
    int best3[3];
    int i;

    select(score1, best3, 4);

    printAr(best3, 3);

    sort(score2, best3, 4);

    printAr(best3, 3);

    return 0;
}

void printAr(int numAr[], int numArSize) {
    int i;
    for (i = 0; i < numArSize; i++)
        printf("%d ", numAr[i]);
    printf("\n");
}

void select(int score[], int best3[], int size) {
    int i, j, max, idx;

    for (i = 0; i < 3; i++) {

        max = score[0];
        idx = 0;

        for (j = 1; j < size; j++) {
            if (score[j] > max) {
                max = score[j];
                idx = j;
            }
        }

        best3[i] = max;
        score[idx] = -1;
    }
}

void sort(int score[], int best3[], int size) {
    int i, j, temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (score[j] > score[j+1]) {
                temp = score[j];
                score[j] = score[j+1];
                score[j+1] = temp;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        best3[i] = score[size - 1 - i];
    }
}

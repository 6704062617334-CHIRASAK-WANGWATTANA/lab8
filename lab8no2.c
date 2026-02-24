#include <stdio.h>

int checkscore(char std[]);
int CorrectQ1(char ans[][10], int stdCount);
int hardQuestion(char ans[][10], int stdCount);
char keys[10] = {'D','B','D','C','C','D','A','E','A','D'};

int main() {
    int i;

    char ans[8][10] = {
        {'A','B','A','C','C','D','E','E','A','D'},
        {'D','B','A','B','C','A','E','E','A','D'},
        {'E','D','D','A','C','B','E','E','A','D'},
        {'C','B','A','E','D','C','E','E','A','D'},
        {'A','B','D','C','C','D','E','E','A','D'},
        {'B','B','E','C','C','D','E','E','A','D'},
        {'B','B','A','C','C','D','E','E','A','D'},
        {'E','B','E','C','C','D','E','E','A','D'}
    };

    for(i = 0; i < 8; i++) {
        printf("std %d => %d\n", i+1, checkscore(ans[i]));
    }

    printf("\nCorrect Q1 = %d\n", CorrectQ1(ans, 8));
    printf("Hard Question = Q%d\n", hardQuestion(ans, 8));

    return 0;
}

int checkscore(char std[]) {
    int i, score = 0;

    for(i = 0; i < 10; i++) {
        if(std[i] == keys[i])
            score++;
    }

    return score;
}

int CorrectQ1(char ans[][10], int stdCount) {
    int i, count = 0;

    for(i = 0; i < stdCount; i++) {
        if(ans[i][0] == keys[0])
            count++;
    }

    return count;
}

int hardQuestion(char ans[][10], int stdCount) {
    int i, j;
    int correctCount[10] = {0};

    for(i = 0; i < stdCount; i++) {
        for(j = 0; j < 10; j++) {
            if(ans[i][j] == keys[j])
                correctCount[j]++;
        }
    }

    int minIndex = 0;

    for(j = 1; j < 10; j++) {
        if(correctCount[j] < correctCount[minIndex])
            minIndex = j;
    }

    return minIndex + 1;
}

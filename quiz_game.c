#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 15
#define MAX_LENGTH 256

typedef struct {
    char question[MAX_LENGTH];
    char choices[4][MAX_LENGTH];
    int correct_answer;
} Question;

void load_questions(Question questions[]);
void ask_question(Question *q, int *score);

int main() {
    Question questions[MAX_QUESTIONS];
    int score = 0;

    srand(time(NULL));
    load_questions(questions);

    printf("Welcome to the Quiz Game!\n");
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        ask_question(&questions[i], &score);
    }

    printf("Game Over! Your final score is: %d/%d\n", score, MAX_QUESTIONS);
    return 0;
}

void load_questions(Question questions[]) {
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].choices[0], "Paris");
    strcpy(questions[0].choices[1], "London");
    strcpy(questions[0].choices[2], "Berlin");
    strcpy(questions[0].choices[3], "Madrid");
    questions[0].correct_answer = 1;

    strcpy(questions[1].question, "Which planet is known as the Red Planet?");
    strcpy(questions[1].choices[0], "Earth");
    strcpy(questions[1].choices[1], "Mars");
    strcpy(questions[1].choices[2], "Jupiter");
    strcpy(questions[1].choices[3], "Venus");
    questions[1].correct_answer = 2;

    strcpy(questions[2].question, "Who wrote 'Hamlet'?");
    strcpy(questions[2].choices[0], "Charles Dickens");
    strcpy(questions[2].choices[1], "William Shakespeare");
    strcpy(questions[2].choices[2], "Mark Twain");
    strcpy(questions[2].choices[3], "Jane Austen");
    questions[2].correct_answer = 2;

    strcpy(questions[3].question, "What is the largest ocean on Earth?");
    strcpy(questions[3].choices[0], "Atlantic Ocean");
    strcpy(questions[3].choices[1], "Indian Ocean");
    strcpy(questions[3].choices[2], "Pacific Ocean");
    strcpy(questions[3].choices[3], "Arctic Ocean");
    questions[3].correct_answer = 3;

    strcpy(questions[4].question, "What is the chemical symbol for water?");
    strcpy(questions[4].choices[0], "O2");
    strcpy(questions[4].choices[1], "H2O");
    strcpy(questions[4].choices[2], "CO2");
    strcpy(questions[4].choices[3], "NaCl");
    questions[4].correct_answer = 2;

    strcpy(questions[5].question, "Who developed the theory of relativity?");
    strcpy(questions[5].choices[0], "Isaac Newton");
    strcpy(questions[5].choices[1], "Albert Einstein");
    strcpy(questions[5].choices[2], "Galileo Galilei");
    strcpy(questions[5].choices[3], "Nikola Tesla");
    questions[5].correct_answer = 2;

    strcpy(questions[6].question, "What is the capital of Japan?");
    strcpy(questions[6].choices[0], "Seoul");
    strcpy(questions[6].choices[1], "Beijing");
    strcpy(questions[6].choices[2], "Tokyo");
    strcpy(questions[6].choices[3], "Bangkok");
    questions[6].correct_answer = 3;

    strcpy(questions[7].question, "Which element has the chemical symbol 'O'?");
    strcpy(questions[7].choices[0], "Oxygen");
    strcpy(questions[7].choices[1], "Gold");
    strcpy(questions[7].choices[2], "Osmium");
    strcpy(questions[7].choices[3], "Oxalate");
    questions[7].correct_answer = 1;

    strcpy(questions[8].question, "What is the tallest mountain in the world?");
    strcpy(questions[8].choices[0], "K2");
    strcpy(questions[8].choices[1], "Mount Everest");
    strcpy(questions[8].choices[2], "Kilimanjaro");
    strcpy(questions[8].choices[3], "Mount McKinley");
    questions[8].correct_answer = 2;

    strcpy(questions[9].question, "What is the hardest natural substance on Earth?");
    strcpy(questions[9].choices[0], "Gold");
    strcpy(questions[9].choices[1], "Iron");
    strcpy(questions[9].choices[2], "Diamond");
    strcpy(questions[9].choices[3], "Platinum");
    questions[9].correct_answer = 3;
}

void ask_question(Question *q, int *score) {
    printf("\n%s\n", q->question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q->choices[i]);
    }
    
    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);

    if (answer == q->correct_answer) {
        printf("Correct!\n\n");
        (*score)++;
    } else {
        printf("Wrong! The correct answer was: %s\n\n", q->choices[q->correct_answer - 1]);
    }
}

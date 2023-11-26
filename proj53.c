#include <stdio.h>

void readScores(int *test1, int *test2, int *test3, double *average, double *avgTest2Test3);
char letterGrade(double average, int test3, double avgTest2Test3);
void printResults(char grade);

int main() {
    int score1, score2, score3;
    double avg, avgTest2Test3;

    readScores(&score1, &score2, &score3, &avg, &avgTest2Test3);
    
    char grade = letterGrade(avg, score3, avgTest2Test3);
    printResults(grade);

    return 0;
}

void readScores(int *test1, int *test2, int *test3, double *average, double *avgTest2Test3) 
{
    printf("Enter the score for test 1: ");
    scanf("%d", test1); 
    
    printf("Enter the score for test 2: ");
    scanf("%d", test2);

    printf("Enter the score for test 3: ");
    scanf("%d", test3);

    *average = (*test1 + *test2 + *test3) / 3.0;
    *avgTest2Test3 = (*test2 + *test3) / 2.0;
}

char letterGrade(double average, int test3, double avgTest2Test3) 
{
    if (average >= 90 && average >= 100) {
        return 'A';
    } else if (average >= 70 && average < 90) {
        if (test3 > 90) {
            return 'A';
        } else {
            return 'B';
        }
    } else if (average >= 50 && average < 70) {
        if (avgTest2Test3 > 70) {
            return 'C'; 
        } else {
            return 'D';
        }
    } else if (average < 50) {
        return 'F';
    } else {
        printf("There's an error in your test score!\n");
        return 'E'; // Placeholder for error condition
    }
}

void printResults(char grade) 
{
    printf("Your Grade is %c. Congrats!\n", grade);
}








#include <stdio.h>

void readScores(int *test1, int *test2, int *test3, double *average, double *avgTest2Test3);
char letterGrade(double average, int test3, double avgTest2Test3);
void printResults(char grade);

int main() {
    int score1, score2, score3;
    double avg, avgTest2Test3;

    readScores(&score1, &score2, &score3, &avg, &avgTest2Test3);
    
    char grade = letterGrade(avg, score3, avgTest2Test3);
    printResults(grade);

    return 0;
}

// This function reads the scores for the three tests
void readScores(int *test1, int *test2, int *test3, double *average, double *avgTest2Test3) 
{
    printf("Enter the score for test 1: ");
    scanf("%d", test1); 
    
    printf("Enter the score for test 2: ");
    scanf("%d", test2);

    printf("Enter the score for test 3: ");
    scanf("%d", test3);

    *average = (*test1 + *test2 + *test3) / 3.0;
    *avgTest2Test3 = (*test2 + *test3) / 2.0;
}

// This function calculates the letter grade based on the average scores and test 3 score
char letterGrade(double average, int test3, double avgTest2Test3) 
{
    if (average > 100) {
        printf("Error! The average score is more than 100. Please recheck the scores.\n");
        return'E';
    } else if (average >= 90) {
        return 'A';
    } else if (average >= 70) {
        if (test3 > 90) {
            return 'A';
        } else {
            return 'B';
        }
    } else if (average >= 50) {
        if (avgTest2Test3 > 70) {
            return 'C'; 
        } else {
            return 'D';
        }
    } else {
        return 'F';
    }
}

// This function prints the calculated letter grade
void printResults(char grade) 
{
    switch(grade) {
        case 'A':
            printf("Congratulations! You have achieved an A grade.\n");
            break;
        case 'B':
            printf("You have achieved a B grade. Good job!\n");
            break;
        case 'C':
            printf("You have achieved a C grade. Keep working hard!\n");
            break;
        case 'D':
            printf("You have achieved a D grade. You can do better.\n");
            break;
        case 'F':
            printf("Unfortunately, you have achieved an F grade. Please review your study habits.\n");
            break;
    }
}


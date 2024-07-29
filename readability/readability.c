#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
/*
index = 0.0588 * L - 0.296 * S - 15.8
where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
Takes a text and determines reading level 'index' = "Grade 3" for example. if plus 16 say +16.
Your program must prompt the user for a string of text using get_string.
Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output "Grade 16+" instead of giving the exact index number. If the index number is less than 1, your program should output "Before Grade 1".



*/
int sentenceCount(string input);
int countword(string input);
int countLetters(string input);
int calculateAlgorithm(int sentenceC, int lettersC, int wordC);
int printGrade(int grade);
int main(void)
{
    string user = get_string("Text: ");
    int wordc = countword(user);
    int sen = sentenceCount(user);
    int charr = countLetters(user);
    int gradeC = calculateAlgorithm(sen, charr, wordc);
    int done = printGrade(gradeC);

}
int sentenceCount(string input){
    int sentences = 0;
    string words = input;
    for(int i=0; i < strlen(words);i++){
        char l = words[i];
        if (l == '.' || l == '?' || l == '!'){
            sentences++;

        }
    }
 //   printf("sentenceC: %i\n",sentences);
    return sentences;
}
int countword(string input){
    int wordcount = 1;
    string words = input;
    for(int i=0; i < strlen(words);i++){
        char l = words[i];
        if (l == ' '){
            wordcount++;

        }
    }
//    printf("wordcount: %i\n",wordcount);
    return wordcount;
}
int countLetters(string input){
    int letterCount = 0;
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
    char l = input[i];
    if ((l >= 'A' && l <= 'Z') || (l >= 'a' && l <= 'z')) {
            letterCount++;
        }
    }
    return letterCount;

}
int calculateAlgorithm(int sentenceC, int lettersC, int wordC){
    float L = (lettersC/(float)wordC)*100.00;
    float S = (sentenceC/(float)wordC)*100.00;

    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int grade = round(index);


    return grade;
}
int printGrade(int grade){
    if (grade < 1){
        printf("Before Grade 1\n");
    }
    else if(grade>16){
        printf("Grade 16+\n");
    }
    else{
        printf("Grade %i\n",grade);
    }
    return 0;
}
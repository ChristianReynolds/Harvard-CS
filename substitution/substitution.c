#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool checkargument(int argCount,int length, string arg);
void convertCipher (int length, string arg, string plaintext);

int main(int argc, string argv[])
{
    if(argc < 2 || argc > 2){
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int length = strlen(argv[1]); // need to ask for length of argv[1] aftwards or will segmentation error due to not having the info when compiling

    if(length != 26){
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if(checkargument(argc,length,argv[1]) == false){
        printf("Error\n");
        return 1;
    }
    else{
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        convertCipher(length,argv[1],plaintext);

    }

}

bool checkargument(int argCount,int length, string arg){
    string jLetters = arg;
    for(int i=0; i<length;i++){
        char l = arg[i];
        if ((l < 'A' || l > 'Z') && (l < 'a' || l > 'z')){ //should look back on
                return false;
        }
        else if (l < 'a' && l > 'z'){
            return false;
        }

        for(int j=i+1; j<length; j++){
            char k = jLetters[j];
            if( k == l){
                return false;
            }
        }

    }
    return true;
}

void convertCipher (int length, string arg, string plaintext){
    int plainTextL = strlen(plaintext);
    for(int i=0;i<plainTextL;i++){
    char l = plaintext[i];


    if (isupper(l)){
        int tempN = l-65;
        char tempChar = arg[tempN];
        tempChar = toupper(tempChar);
        printf("%c",tempChar);

    }
    else if(islower(l)){
        int tempN = l-97;
        char tempChar = arg[tempN];
        tempChar = tolower(tempChar);
        printf("%c",tempChar);
    }
    else{
        printf("%c",plaintext[i]);
    }

}
printf("\n");
}


#include <stdio.h>
#include <cs50.h>

int getHeight(void);
void printFS(int height);
void printSHash(int numHash);
void printSpaces(void);
void printFuction(int height);

int main(void){
    int h = getHeight();
    printFuction(h);




}
int getHeight(void){
  int height=0;

  while(height<1||height>8){
    height = get_int("Height: ");
    }
    return height;
}
//potnetially printing the space in the front side of the pyramid. //
void printFS(int numSpaces){
  for(int i=0;i < numSpaces-1;i++){
    printf(" ");
 }

}
//print the first set of hashes
void printHash(int numHash){
  for(int i=0; i<numHash;i++){
    printf("#");
  }
}
//print the double space
void printSpaces(void){
  for(int i=0; i<2;i++){
    printf(" ");
}
}
//print the second half of hashes
void printSHash(int numHash){
  for(int i=0; i<numHash;i++){
    printf("#");
  }
  printf("\n");
}
//could've put in the main but function all the pieces together
void printFuction(int height){
  int subtractS = height;
  int addH = 1;

  for(int i=0;i<height;i++){
  printFS(subtractS);
  printHash(addH);
  printSpaces();
  printSHash(addH);
  subtractS--;
  addH++;
  }



}









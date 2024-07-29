#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
//coded on https://www.onlinegdb.com/online_c_compiler
long cardN(void);
int cardLength(long cardNum);
bool cardcheck(int length);
bool algorithm(long cardNum,int length);
void typeCard(long cardNum,int length);

int main(void)
{
    long cardNum = cardN();
    int length = cardLength(cardNum);
    bool check = cardcheck(length);
    if (check == true){
       bool check2= algorithm(cardNum,length);
       if(check2==true){
        typeCard(cardNum,length);

       }

    }
    else if(check == false){

    }


}
//request card number
long cardN(void){
    long cardNumber = get_long("Number: ");
    return cardNumber;
}
//gives a number of the length of the card
int cardLength(long cardNum){
    int i = 0;
    long tempNum = cardNum;
    while (tempNum>0){
        tempNum = tempNum / 10;
        i++;

    }
    return i;
}
//chekcs the length of numbers if it qualifies itll return true if not it will return false.
bool cardcheck(int length){
    int l = length;
    if (l == 13 || l == 15 || l == 16 ){
        return true;
    }
    else{
        printf("INVALID\n");
        return false;


    }

}

//400360000000001
//123456789112345
// Luhn's Algorithm
bool algorithm(long cardNum,int length){
    long c = cardNum;
    int l = length;
    long sum =0;
    long tempSum =0;
    long j;

    for(int i=1;i<length+1;i++){
        j=c%10;
        c=c/10;

    if(i%2==0){
        long dig =0;

        dig = (j*2);
        if(dig>9){
            sum += (dig % 10);
            sum += (dig /10);
        }
        else{
            sum+=dig;
        }
    }

    else{
        tempSum += j;

    }
    }
     if((tempSum+sum)%10==0){
        return true;
     }
     else{
        printf("INVALID\n");
        return false;

     }
}
//takes it down to the 2 last numbers and compares
void typeCard(long cardNum,int length){
    long c = cardNum;
    for(int i=1;i<length-1;i++){
        c=c/10;
    }
    if(c==34||c==37){
            printf("AMEX\n");
        }
    else if(c>=51&&c<=55){
            printf("MASTERCARD\n");
    }
    else if(c>=40 &&c<50){
            printf("VISA\n");
    }
    else{
            printf("INVALID\n");

}

}

   /*
    long c = 4003600000000014 ;
    int i=0;
    long sum =0;
    long tempSum =0;
    long j =c%10;
    c=c/10;
    printf("%ld\n",j);
    printf("%ld\n",c);

    if(i%2==0){
        sum = sum + (j*2);
        printf("%ld\n",sum);
    }
    else{
        printf("shit not working\n");
    }
    i++;
    j =c%10;
    c=c/10;
    printf("%ld\n",j);
    printf("%ld\n",c);

    if(i%2==0){
        sum = sum + (j*2);
        printf("%ld",sum);
    }
    else{
        printf("shit not working\n");
        tempSum += j;
    }
        printf("%ld\n",sum);
        printf("%ld\n",tempSum);



}
*/
/*

         long c = 4003600000000014 ;
        long tempSum = 0;
        long sum = 0;
        int i = 0;
    //iterates until card number is less than one since the numebr will
        while(c > 1){
        //gets the the last digit
        long j =c%10;
        c=c/10;
        if (i%2!=0){
            sum += j*2;
        }

        else if(i%2==0){
            tempSum+=j;
        }
        i++;

    }
    printf("%ld",tempSum);
}
*/
/*
4003600000000014
6543210987654321

8
1
8
1
8
1
8
1
8
1
8
7
14
7
14
11
*/
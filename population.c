    #include <stdio.h>
    #include <cs50.h>

    int get_start(void);
    int get_end(int startNum);
    int get_year (int startNum, int endNum);
    void print_years(int getyear);



    int main(void){
       int startNum=get_start();
       int endNum=get_end(startNum);
       int getyear=get_year(startNum,endNum);
       print_years(getyear);


        }

// Prompt User for Starting Population Size (which needs to be 9 or Greater)
    int get_start(void){
        int startN;

        do{
        startN = get_int("Starting Size: ");
        }
        while(startN<9);

        return startN;
    }
// Prompt User for End Population Size (which needs to be greater or equal to Starting Population)
    int get_end(startNum){
        int endN;
        do{
        endN = get_int("End Size: ");
        }
        while(endN<startNum);

        return endN;
    }

// Calculate Year to reach population
    int get_year (startN,endN){
        float x;
        float y;
        int n = 0 ;
        while(startN < endN){
        x = startN/3;
        y = startN/4;
        n++;
        startN += x-y;
        }
        return n;


    }
    void print_years(int getyear){
        printf("Years: %i\n", getyear);
    }

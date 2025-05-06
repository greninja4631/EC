#include <stdio.h>
#include <stdlib.h>

int compare(const void *a , const void *b){
    return (*(int*)a - *(int*)b);
}

   //  int scores[] = {60 , 70 , 70 , 85 , 85 , 90 , 90 , 90};

int main() {
    int scores[] = {70, 85, 90, 70, 85, 90, 90, 60};
    int n = sizeof(scores)/sizeof(scores[0]);





    // printf("最頻値 = %d\n" , past_value);

    return 0;
}
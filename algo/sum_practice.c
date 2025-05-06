#include <stdio.h>
#include <stdlib.h>

// 昇順で並べ替える比較関数
int compare(const void *a , const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int scores[] = {60 , 70 , 70 , 85 , 85 , 90 , 90 , 90};
    int n = sizeof(scores) / sizeof(scores[0]);

    


    printf("最頻値 = %d\n", past_value);

    return 0;
}


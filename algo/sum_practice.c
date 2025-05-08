#include <stdio.h>
#include <stdlib.h>

// 昇順で並べ替える比較関数
int compare(const void *a , const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int scores[] = {60 , 70 , 70 , 85 , 85 , 90 , 90 , 90};
    int n = sizeof(scores) / sizeof(scores[0]);

int current_count = 1;
int current_value = scores[0];
int past_count = 1;
int past_value = scores[0];

for(int i = 1; i < n; i++) {
    if(scores[i] == current_value) {
        corrent_count ++;
    }

   }else{
    current_value = scores[i]
    corrent_count = 1;
}


    printf("最頻値 = %d\n", past_value);

    return 0;
}


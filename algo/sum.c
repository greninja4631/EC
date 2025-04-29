#include <stdio.h>
#include <stdlib.h>

int compare(const void *a , const void *b){
    return (*(int*)a - *(int*)b);
}

int main() {
    int scores[] = {70, 85, 90, 70, 85, 90, 90, 60};
    int n = sizeof(scores)/sizeof(scores[0]);

    int sum = 0;
    int max = scores[0];
    int min = scores[0];

    for(int i = 0; i < n; i++) {
        int val = scores[i];
        sum += val;
        if(val > max) max = val;
        if(val < min) min = val;
    }

    float average = (float)sum / n;

    qsort(scores , n , sizeof(int) , compare);

    float median;
    if(n % 2 == 0){
        median = (scores[n/2 -1] + scores[n/2]) / 2.0;
    } else {
        median = scores[n/2];
    }

    int current_count = 1;
    int current_value = scores[0];
    int max_count = 1;
    int mode_value = scores[0];

    for(int i = 1; i < n; i++){
        if(scores[i] == current_value){
            current_count++;
        } else {
            current_value = scores[i];
            current_count = 1;
        }

        if(current_count > max_count ||
          (current_count == max_count && current_value < mode_value)){
            max_count = current_count;
            mode_value = current_value;
        }
    }

    printf("合計値 = %d\n" , sum);
    printf("最大値 = %d\n" , max);
    printf("最小値 = %d\n" , min);
    printf("平均値 = %.1f\n" , average);
    printf("中央値 = %.1f\n" , median);
    printf("最頻値 = %d\n" , mode_value);

    return 0;
}
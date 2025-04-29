#include <stdio.h>
#include <stdlib.h>

// 昇順で並べ替える比較関数
int compare(const void *a , const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int scores[] = {60 , 70 , 70 , 85 , 85 , 90 , 90 , 90};
    int n = sizeof(scores) / sizeof(scores[0]);

    int sum = 0;
    int max = scores[0];
    int min = scores[0];

    // 合計・最大・最小の計算
    for(int i = 0; i < n; i++){
        int val = scores[i];
        sum += val;
        if(val > max) max = val;
        if(val < min) min = val;
    }

    float average = (float)sum / n;

    // 並び替え
    qsort(scores, n, sizeof(int), compare);

    // 中央値の計算
    float median;
    if(n % 2 == 0 ){
        median = (scores[n / 2 - 1] + scores[n / 2]) / 2.0;
    } else {
        median = scores[n / 2];
    }

   //  int scores[] = {60 , 70 , 70 , 85 , 85 , 90 , 90 , 90};

    // 最頻値を求める処理
    int past_value = scores[0];
    int past_max_count = 1;
    int current_value = scores[0];
    int current_count = 1;

    for(int i = 1; i < n; i++){
        if(scores[i] == current_value){
            current_count++;
        } else {
            current_value = scores[i];
            current_count = 1;
        }
   //  int scores[] = {60 , 70 , 70 , 85 , 85 , 90 , 90 , 90};
   //&&の方が||より優先度が高い。
        if(current_count > past_max_count ||
           (current_count == past_max_count && current_value < past_value)){
            past_max_count = current_count;
            past_value = current_value;
        }
    }

// 配列（ソート後）：
// 60 70 70 85 85 90 90 90

	// •	左側 current_count > past_max_count が true なら、
	// •	右側 (current_count == past_max_count && current_value < past_value) は評価されない！
	// •	→ ✅ 「問答無用で更新」してOK！

// 処理の流れ：

// i = 0 → current_value = 60 → current_count = 1  
// i = 1 → 70 != 60 → current_value = 70, current_count = 1  
// i = 2 → 70 == 70 → current_count = 2 ←ここでカウント進む  
// i = 3 → 85 != 70 → current_value = 85, current_count = 1  
// i = 4 → 85 == 85 → current_count = 2  
// i = 5 → 90 != 85 → current_value = 90, current_count = 1  
// i = 6 → 90 == 90 → current_count = 2  
// i = 7 → 90 == 90 → current_count = 3 ←最頻値確定！

// 	•	左側：current_count > past_max_count （単独の条件）
// 	•	右側：(current_count == past_max_count && current_value < past_value) （カッコでひとまとまり）

// になっている！

// ⸻

// ✅ だから正しい評価順はこう：
// 	1.	まず current_count > past_max_count を評価（これがA）
// 	2.	もしこれが true なら、もうその時点でif全体はtrue（ショートサーキット！）
// 	3.	もしこれが false なら、カッコ内 (current_count == past_max_count && current_value < past_value) を評価（これがB）
// 	•	ここでは&&が普通に使われていて、両方trueならOK

    // 出力
    printf("合計値 = %d\n", sum);
    printf("最大値 = %d\n", max);
    printf("最小値 = %d\n", min);
    printf("平均値 = %.1f\n", average);
    printf("中央値 = %.1f\n", median);
    printf("最頻値 = %d\n", past_value);

    return 0;
}


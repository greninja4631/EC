#include <stdio.h>

int main() {
    int a[] = {70, 80, 75, 80, 90, 70, 80, 60, 70, 70};
    int n = sizeof(a) / sizeof(a[0]);
    int current_value, current_count;
    int max_count = 0;
    int mode_value = a[0];

    // 各要素を基準にして、その値が何回出てくるかを数える
    for (int i = 0; i < n; i++) {
        current_value = a[i];
        current_count = 0;

        // current_value と同じ値を数える
        for (int j = 0; j < n; j++) {
            if (a[j] == current_value) {
                current_count++;
            }
        }

        // 出現回数が最大なら最頻値を更新
        if (current_count > max_count || 
           (current_count == max_count && current_value < mode_value)) {
            max_count = current_count;
            mode_value = current_value;
        }
    }

    printf("最頻値: %d（%d回出現）\n", mode_value, max_count);

    return 0;
}
#include <stdio.h>

int main() {
    int values[] = {1, 2, 3, 4, 5};        // ← 変数名を 'values' に変更
    printf("%d\n", values[3]);            // ← 正しく配列アクセス
    return 0;                             // ← セミコロン忘れずに！
}
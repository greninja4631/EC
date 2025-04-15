#include <stdio.h>
#include <stdlib.h>

// 昇順ソート用の比較関数
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
//*はポインターを参照渡ししている、　(*a)voidをintに変換している
//void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
//*(int*)a - *(int*)b);は、int (*compar)(const void *, const void*));

int main() {
    // 元データ（必要に応じて動的に拡張も可能）
    int scores[] = {70, 85, 90, 70, 85, 90, 90, 60};
    int n = sizeof(scores) / sizeof(scores[0]);

    // 合計・最大・最小の初期化
    int sum = 0;
    int max = scores[0];
    int min = scores[0];

    // 合計・最大・最小を1回のループで求める
    for (int i = 0; i < n; i++) {
        int val = scores[i];
        sum += val;
        if (val > max) max = val;
        if (val < min) min = val;
    }

    // 平均値の計算（小数を扱うため float）
    float average = (float)sum / n;
  

    // データを昇順にソート（中央値と最頻値用）
    qsort(scores, n, sizeof(int), compare);
// scoresは「並び替え対象の配列」

// nは「要素の個数（今回は8個）」

// sizeof(int)は「１つの要素のサイズ（整数なので4バイト）」

// compareは「要素同士を比べるための関数」



// qsortの裏側のロジック ＝ void qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
// 配列を渡す
// base: 配列の先頭アドレス
// num: 要素数
// size: 1要素あたりのサイズ（バイト数）
// compar: 比較関数（ルールを決める関数）
// base , compare 配列のアドレスをポインターで渡せる性質がある
// // ↓ qsort がこれらを受け取ると…


    // 中央値の計算
    float median;
    if (n % 2 == 0) {
        // 要素数が偶数 → 中央2つの平均
        median = (scores[n / 2 - 1] + scores[n / 2]) / 2.0;
    } else {
        // int scores[] が中身の要素が奇数であった場合
        median = scores[n / 2];
    }

    // 最頻値（mode）の計算
    int mode = scores[0];
    int max_count = 1;
    int current_value = scores[0];
    int current_count = 1;

   for (int i = 1; i < n; i++) {
    if (scores[i] == current_value) {
        current_count++;  // ここが本来必要な処理！
    } else {
        current_value = scores[i];
        current_count = 1;
    }

    if (current_count > max_count ||
        (current_count == max_count && current_value < mode)) {
        max_count = current_count;
        mode = current_value;
    }
}


    // 結果を表示（統一感を意識して整形）
    printf("📊 統計情報\n");
    printf("合計     : %d\n", sum);
    printf("最大値   : %d\n", max);
    printf("最小値   : %d\n", min);
    printf("平均値   : %.2f\n", average);
    printf("中央値   : %.2f\n", median);
    printf("最頻値   : %d\n", mode);

    return 0;
}












// とても良い質問です！
// 上記のコードは、基本的かつ重要なアルゴリズムが多数含まれており、C言語での統計処理の入門〜中級ステップとして非常に優れた構成です。

// ⸻

// ✅ 使われている主なアルゴリズム一覧

// 処理	使用されているアルゴリズム・構造	内容
// 🔁 合計・最大・最小	線形走査（Linear Scan）	1回のforループで配列の全要素を順に確認し、値を蓄積・比較
// ⚖️ 平均値	除算演算（合計 / 要素数）	基本的な数学処理（精度のためfloat型）
// 🔃 ソート	クイックソート（QuickSort）（qsort()）	Cの標準ライブラリ関数。中央値・最頻値の前処理
// 🎯 中央値（Median）	位置ベースの平均/抽出	ソート済配列の中央位置を参照。偶数なら2つの平均、奇数なら中央
// 📈 最頻値（Mode）	出現回数カウント（連続走査）＋条件比較	同じ値の連続回数を数えて最大値を判定。複数ある場合は小さい方を選ぶロジックあり



// ⸻

// 🎓 難易度評価（5段階）

// アルゴリズムカテゴリ	難易度	理由
// 線形走査（sum, max, min）	★☆☆☆☆	最も基本的なアルゴリズム（初心者OK）
// 平均値計算	★☆☆☆☆	数学的には簡単。ただし精度（小数）に注意
// ソート（qsort）	★★★☆☆	標準関数を使っているため簡単に見えるが、比較関数の仕組みは中級向け
// 中央値計算	★★☆☆☆	ソートとインデックスの理解が必要（偶数/奇数の分岐）
// 最頻値計算	★★★☆☆	条件付きのカウント + 優先順位付きの選択を理解する必要あり



// ⸻

// ✅ 総合難易度：★★★☆☆（初級〜中級）
// 	•	C言語の文法や配列、ループに慣れてきた人に最適な演習
// 	•	実務的な統計処理の導入としても現場で応用可能
// 	•	「処理の目的に応じてアルゴリズムを組み合わせる」ことが学べる

// ⸻

// 🧩 このコードで身につくスキル
// 	•	複数の目的を1つのコードにまとめて処理する力
// 	•	条件分岐を活用した意思決定ロジック
// 	•	Cの標準関数（qsort）との連携方法
// 	•	コードの可読性を保ちながら処理を整理する技術

// ⸻

// 次のステップとしては：
// 	•	分散・標準偏差の計算を追加
// 	•	最頻値の複数出力（すべて表示）
// 	•	自作ソート（バブルソートなど）で学習強化

// などもおすすめです！
// 必要なら応用問題も出題できますので、ぜひ声をかけてください🔥💻
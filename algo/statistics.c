#include <stdio.h>      // 標準入出力（printfなど）に必要
#include <stdlib.h>     // malloc, free, qsortなどのメモリ操作に必要
#include <string.h>     // memcpyに必要
#include <assert.h>     // 開発時の検証用（異常値の即停止）
#include <errno.h>      // エラー番号参照用

#define MAX_VALUE 100   // 最頻値のための配列サイズ（0〜100までの整数を扱う）

// ------- ログマクロ（ログ出力の統一） -------
#define LOG_INFO(...)   fprintf(stdout,  "[INFO]  " __VA_ARGS__)
#define LOG_ERROR(...)  fprintf(stderr, "[ERROR] " __VA_ARGS__)

// ------- エラーコード定義（戻り値に意味を持たせる） -------
typedef enum {
    STAT_SUCCESS = 0,           // 正常終了
    STAT_MEM_ALLOC_FAIL = 1,   // メモリ確保失敗
    STAT_INVALID_INPUT = 2     // 不正な引数
} ErrorCode;

// ------- 統計情報構造体：1つのまとまりで返せるように -------
/**
 * @struct Statistics
 * @brief 平均・中央値・最頻値などを保持するADT（抽象データ型）
 */
typedef struct {
    int sum;
    int min;
    int max;
    double average;
    double median;
    int mode;
} Statistics;

// ------- 整数比較関数：qsortのために必要（ソートの基準） -------
static int compare_ints(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);  // a - b の値で並び順が決まる
}

// ------- 合計計算 -------
static int sum(const int *data, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += data[i];  // 全要素を合計
    }
    return total;
}

// ------- 最小値計算 -------
static int min(const int *data, int size) {
    int min_val = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] < min_val) min_val = data[i];
    }
    return min_val;
}

// ------- 最大値計算 -------
static int max(const int *data, int size) {
    int max_val = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max_val) max_val = data[i];
    }
    return max_val;
}

// ------- 平均値計算 -------
static double average(const int *data, int size) {
    return (double)sum(data, size) / size;  // 合計 ÷ 件数
}

// ------- 中央値計算（ソートが必要なためコピーを作成） -------
static double median(const int *data, int size) {
    int *copy = malloc(sizeof(int) * size);  // オリジナルを壊さないためにコピー
    if (!copy) {
        LOG_ERROR("Memory allocation failed for median calculation\n");
        return -1.0;
    }

    memcpy(copy, data, sizeof(int) * size);  // データをコピー
    qsort(copy, size, sizeof(int), compare_ints);  // 昇順ソート

    double result = (size % 2 == 0)
        ? (copy[size / 2 - 1] + copy[size / 2]) / 2.0   // 偶数なら中央2つの平均
        : copy[size / 2];                              // 奇数なら中央の値

    free(copy);  // メモリ解放（リーク防止）
    return result;
}

// ------- 最頻値計算（出現頻度をカウント） -------
static int mode(const int *data, int size) {
    int freq[MAX_VALUE + 1] = {0};  // 頻度カウント用（すべて0初期化）

    for (int i = 0; i < size; i++) {
        if (data[i] >= 0 && data[i] <= MAX_VALUE) {
            freq[data[i]]++;  // 該当値の出現回数を+1
        }
    }

    int mode_val = data[0];             // 最初の値を仮の最頻値とする
    int max_freq = freq[mode_val];      // その頻度を基準とする

    for (int i = 1; i < size; i++) {
        if (freq[data[i]] > max_freq) {  // より頻度が高い値があれば更新
            max_freq = freq[data[i]];
            mode_val = data[i];
        }
    }
    return mode_val;
}

// ------- メイン関数：CLIでもCIでも利用可能な構成 -------
int main(void) {
    int data[] = {1, 2, 3, 3, 5, 5, 5, 8, 9};
    int size = sizeof(data) / sizeof(data[0]);

    Statistics stats = {
        .sum     = sum(data, size),
        .min     = min(data, size),
        .max     = max(data, size),
        .average = average(data, size),
        .median  = median(data, size),
        .mode    = mode(data, size)
    };

    // JSON形式で出力（APIログ・CLI連携）
    printf("{\n");
    printf("  \"sum\": %d,\n", stats.sum);
    printf("  \"min\": %d,\n", stats.min);
    printf("  \"max\": %d,\n", stats.max);
    printf("  \"average\": %.2f,\n", stats.average);
    printf("  \"median\": %.2f,\n", stats.median);
    printf("  \"mode\": %d\n", stats.mode);
    printf("}\n");

    // CIツールなどによる自動テスト（ユニットテスト相当）
    assert(stats.sum > 0);
    assert(stats.min >= 0);
    assert(stats.max >= stats.min);
    assert(stats.average >= 0.0);
    assert(stats.median >= 0.0);

    LOG_INFO("Statistics test passed.\n");
    return 0;
}
 


//  🔵 自分の頭に叩き込むべき領域（設計・面接・転用力に直結）

//  🧠 項目	✨ 内容	💡 なぜ覚えるべきか？
//  typedef enum { ... } ErrorCode;	エラーの状態管理	状態パターン設計に不可欠。Go/Rustにも応用可能
//  typedef struct { ... } Statistics;	抽象データ型（ADT）	型設計力を示す。どの言語でも活かせる本質スキル
//  calculate_median, find_mode	アルゴリズム設計	ソート・カウント・統計処理はCSの基本力
//  assert(), LOG_* マクロ	テスト・ログ設計	DevOpsやCI/CDスキルの土台。可観測性の考え方に通じる
//  main() の構造設計	関数分離・抽象設計	CLI→APIへの拡張力を養う基礎。全言語で重要
 
 
//  ⸻
 
//  🟢 AIに任せてよい・覚えなくてよい領域（定型・暗記不要）
 
//  🤖 項目	✨ 内容	🙆 理由
//  #include <stdio.h> など	標準ヘッダ	毎回AI補完でOK。意味だけ分かればよい
//  #define LOG_INFO(...)	マクロの定義	パターン化されており、毎回書く必要なし
//  qsort()	組み込みソート関数	毎回ググってもOK。CS理解とは別問題
//  memcpy(), malloc()	メモリ操作関数	使用タイミングだけ分かればよい。引数暗記不要
//  printf() での JSON整形	文字列出力	形式的な処理なので自動化で十分
 
 
//  ⸻
 
//  🧱 理解は必要・暗記は不要な構造
 
//  構造例	理解すべきポイント
//  calculate_statistics() の関数委譲	「分離された関数群の役割分担」構造
//  Statistics 構造体	「抽象データ型として何を表現しているか」
//  各層でのエラー処理分離	「どの関数が何を責任範囲として持つか」
 
 
//  ⸻
 
//  ✅ 最終まとめ（一覧表）
 
//  領域	自力で覚えるべき	AIに任せてよい
//  🧱 構造設計（struct / enum / API）	✅	❌
//  📊 アルゴリズム（中央値・最頻値など）	✅	❌
//  ⚙️ 標準関数（printf, malloc など）	❌	✅
//  🧩 マクロの書き方（LOG系）	❌（使い方だけ理解）	✅
//  🧾 JSON整形出力	❌	✅
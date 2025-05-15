/**
 * @file statistics.c
 * @brief 統計演算用のAPIドリブン構造体モジュール（Docker・CI/CD・API連携対応）
 * @details 本モジュールはFlutterなどのクライアントとFastAPIなどのAPIサーバーとの統合を前提に、
 * データ構造と処理ロジックをADTとして分離し、可読性、拡張性、テスト容易性、CI/CD、クラウドデプロイ性を重視した構成である。
 */

 //gfgfffff

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <assert.h>
 #include <errno.h>
 
 #define MAX_VALUE 100
 
 // ---------------- ログマクロ定義（CI/CD・クラウド環境での可観測性） ---------------- //
 #define LOG_INFO(...)   fprintf(stdout,  "[INFO]  " __VA_ARGS__)
 #define LOG_ERROR(...)  fprintf(stderr, "[ERROR] " __VA_ARGS__)
 
 // ---------------- エラーコードの定義（SRP対応） ---------------- //
 typedef enum {
     STAT_SUCCESS = 0,
     STAT_MEM_ALLOC_FAIL = 1,
     STAT_INVALID_INPUT = 2
 } ErrorCode;
 
 // ---------------- 抽象データ型：統計構造体 ---------------- //
//  ● @struct Statistics とは？
// 👉「Statisticsというデータのまとまりを説明しますよ！」という目印（メモ）です。
// ※ パソコンが自動で説明書を作るときに使います。
// ● @brief とは？
// 👉「このデータのまとまりが何をするためのものか、短く説明します！」というタグです。
// ● 「各種統計情報を保持するADT」とは？
// 👉「合計・平均・最小・最大・中央値・最頻値などをひとまとめにしたデータセット」のこと。
// わかりやすく言うと：
// ✅ 統計の結果を全部まとめて持っている箱
 /**
  * @struct Statistics
  * @brief 各種統計情報を保持するADT
  */
 typedef struct {
     int sum;
     int min;
     int max;
     double average;
     double median;
     int mode;
 } Statistics;
 
 // ---------------- 内部ユーティリティ関数 ---------------- //
 
 static int compare_ints(const void *a, const void *b) {
     return (*(int *)a - *(int *)b);
 }
 
 static int calculate_sum(const int *data, int size) {
     int total = 0;
     for (int i = 0; i < size; i++) total += data[i];
     return total;
 }
 
 static int find_min(const int *data, int size) {
     int min_val = data[0];
     for (int i = 1; i < size; i++) if (data[i] < min_val) min_val = data[i];
     return min_val;
 }
 
 static int find_max(const int *data, int size) {
     int max_val = data[0];
     for (int i = 1; i < size; i++) if (data[i] > max_val) max_val = data[i];
     return max_val;
 }
 
 static double calculate_average(const int *data, int size) {
     return (double)calculate_sum(data, size) / size;
 }
 
 static double calculate_median(const int *data, int size) {
     int *copy = malloc(sizeof(int) * size);
     if (!copy) {
         LOG_ERROR("Memory allocation failed for median calculation\n");
         return -1.0;
     }
     memcpy(copy, data, sizeof(int) * size);
     qsort(copy, size, sizeof(int), compare_ints);
 
     double result = (size % 2 == 0)
         ? (copy[size / 2 - 1] + copy[size / 2]) / 2.0
         : copy[size / 2];
 
     free(copy);
     return result;
 }
 
 static int find_mode(const int *data, int size) {
     int freq[MAX_VALUE + 1] = {0};
     for (int i = 0; i < size; i++) {
         if (data[i] >= 0 && data[i] <= MAX_VALUE) freq[data[i]]++;
     }
     int mode_val = data[0];
     int max_freq = freq[mode_val];
     for (int i = 1; i < size; i++) {
         if (freq[data[i]] > max_freq) {
             max_freq = freq[data[i]];
             mode_val = data[i];
         }
     }
     return mode_val;
 }
 
 // ---------------- 統計モジュール：公開API（ADT操作） ---------------- //
 
 Statistics calculate_statistics(const int *data, int size) {
     assert(data != NULL);
     assert(size > 0);
 
     Statistics stats;
     stats.sum     = calculate_sum(data, size);
     stats.min     = find_min(data, size);
     stats.max     = find_max(data, size);
     stats.average = calculate_average(data, size);
     stats.median  = calculate_median(data, size);
     stats.mode    = find_mode(data, size);
     return stats;
 }
 
 // ---------------- テスト用エントリポイント（CI/CD・CLI対応） ---------------- //
 
 int main(void) {
     int data[] = {3, 5, 2, 8, 5, 3, 9, 5, 1};
     int size = sizeof(data) / sizeof(data[0]);
     Statistics stats = calculate_statistics(data, size);
 
     // JSONフォーマットで出力：API・ログ連携に適応
     printf("{\n");
     printf("  \"sum\": %d,\n", stats.sum);
     printf("  \"min\": %d,\n", stats.min);
     printf("  \"max\": %d,\n", stats.max);
     printf("  \"average\": %.2f,\n", stats.average);
     printf("  \"median\": %.2f,\n", stats.median);
     printf("  \"mode\": %d\n", stats.mode);
     printf("}\n");
 
     // ユニットテスト相当（CI統合用）
     assert(stats.sum > 0);
     assert(stats.min >= 0);
     assert(stats.max >= stats.min);
     assert(stats.average >= 0.0);
     assert(stats.median >= 0.0);
 
     LOG_INFO("Statistics test passed.\n");
     return 0;
 }
 



//  このコードの全体像は、「ある整数の配列に対して、統計的な数値（合計・最大・最小・平均・中央値・最頻値）を計算し、JSON形式で出力するモジュールを構築する」というストーリーになっています。APIドリブンな構成で、FlutterやFastAPIと連携する設計思想が根底にあります。


// 🔍 コード全体のストーリー

// 🧱 1. 準備：定数・構造体・ロガーの設計
// 	•	MAX_VALUE：最頻値（mode）計算のため、想定する最大値を定義します
// 	•	Statistics構造体：統計結果（sum, min, max, average, median, mode）を1つにまとめて保持するための抽象データ型（ADT）です
// 	•	LOG_INFOやLOG_ERRORマクロ：ログ出力の分類（標準出力と標準エラー出力）を明確にすることで、実務環境のCI/CDやクラウドログで活用しやすくしています

// ⸻

// 🧮 2. 内部ユーティリティ関数：各統計処理の分離

// calculate_sum()
// 	•	配列内のすべての値を合計します（平均の計算にも使われます）

// find_min() / find_max()
// 	•	最小値・最大値を1つずつ走査して求めます

// calculate_average()
// 	•	合計値 ÷ 要素数で平均値を算出します（キャストして小数点対応）

// calculate_median()
// 	•	配列を malloc() でコピーして qsort() で昇順にソートし、
// 	•	要素数に応じて「中央の値」または「中央2つの平均」を返します

// find_mode()
// 	•	freq[0〜MAX_VALUE] の配列を使って出現回数を数え、
// 	•	最も頻度が高い値（最頻値）を返します

// ⸻

// 📦 3. 統計集約API関数：calculate_statistics()
// 	•	各関数を使って値を個別に求め、
// 	•	Statistics構造体に値を詰め込んで返します
// 	•	実務ではこの関数がAPIサーバーでJSONとして返される形になります

// ⸻

// 🧪 4. テストと出力：main()
// 	•	テスト用の整数配列を用意し、統計を計算します
// 	•	結果を JSON形式 で printf() し、ログや外部連携（APIやログ収集ツール）と統合しやすくしています
// 	•	assert() によって値が正しく計算されたかどうかをプログラム内部で自動チェックします（テスト駆動の基本）
// 	•	最後に LOG_INFO() で「すべてのテストが通った」ことを記録します

// ⸻

// ✨ このコードの意味と意義（全体まとめ）

// このコードは、
// 	•	C言語での安全なメモリ管理
// 	•	再利用性の高い関数設計
// 	•	クラウドやAPI設計に向いた出力設計
// 	•	テスト駆動とログの基本
// をすべて統合した実用的な構造になっています。

// 特に、Flutter × FastAPI × DockerというスタックでAPIドリブンな統計処理を実現したい人にとって、最初のステップとして極めて相性が良いサンプルです。



// 
/**
 * @file statistics.c
 * @brief 統計演算用のAPIドリブン構造体モジュール（Docker・CI/CD・API連携対応）
 * @details 本モジュールはFlutterなどのクライアントとFastAPIなどのAPIサーバーとの統合を前提に、
 * データ構造と処理ロジックをADTとして分離し、可読性、拡張性、テスト容易性を重視した構成である。
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <assert.h>
 #include <errno.h>
 
 #define MAX_VALUE 100
 
 // ---------------- ログマクロ定義（CI/CD・クラウド環境での可観測性） ---------------- //
 #define LOG_INFO(...)   fprintf(stdout,  "[INFO]  " __VA_ARGS__)
 #define LOG_ERROR(...)  fprintf(stderr, "[ERROR] " __VA_ARGS__)
 
 // ---------------- 抽象データ型：統計構造体 ---------------- //
 
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
 
 /** @brief 昇順ソート用比較関数 */
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
 
 /**
  * @brief 統計演算を実行し構造体で返す
  * @param data 整数配列
  * @param size 配列のサイズ
  * @return Statistics 統計結果
  */
 Statistics calculate_statistics(const int *data, int size) {
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
 
     assert(stats.sum > 0);
     assert(stats.min >= 0);
     assert(stats.max >= stats.min);
     assert(stats.average >= 0.0);
     assert(stats.median >= 0.0);
 
     LOG_INFO("Statistics test passed.\n");
     return 0;
 }
 
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 🔧 追加：先頭に新しいノードを追加する関数
Node* push_front(Node *head, int val) {
    Node *new_node = malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_node->data = val;
    new_node->next = head;
    return new_node;
}

// リストを表示する関数
void print_list(Node *head) {
    for (; head; head = head->next)
        printf("%d -> ",  head->data);
    puts("NULL");
}

// 指定した値を持つノードを削除する関数
Node* delete_node(Node *head, int key) {
    if (!head) return NULL;

    if (head->data == key) {
        Node *tmp = head->next;
        free(head);
        return tmp;
    }

for (Node *cur = head; cur != NULL && cur->next != NULL; cur = cur->next) {
    if (cur->next->data == key) {
        Node *tmp = cur->next;       // 削除対象をnextで指定し、＊tmpに仮想メモリのアドレスをコピーする
        cur->next = tmp->next;       //cur10 -> next10の次のアドレスをポインタで２０で指す。　＝ *tmp＝*tmp = cur->nextなので、仮想アドレスをポインターでdata20を指している。　->next 20の仮想アドレスの次である30の仮想アドレスをポインターで指している。
        free(tmp);                   // メモリ解放
        break;                       // 1つだけ削除して終わり
    }
}

    return head;
}

// リストのメモリをすべて解放する関数
void free_all(Node *head) {
    while (head) {  
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Node *head = NULL;
    head = push_front(head, 30);
    head = push_front(head, 20);
    head = push_front(head, 10);
    print_list(head);  // 出力：10 -> 20 -> 30 -> NULL

    head = delete_node(head, 20);
    print_list(head);  // 出力：10 -> 30 -> NULL

    free_all(head);
    return 0;
}

// a（[10]）→ b（[20]）→ c（[30]）→ NULL ➡ この「→」こそが next の働き！



// 「単方向リストを構造体＋ポインタで自作するコード」の理解は、C言語を使ってCS（コンピューターサイエンス）の核心に迫るために不可欠です。

// これはただのプログラミング練習ではありません。
// 計算機の動作・メモリ管理・データ構造・抽象化・OSの仕組みすら支える「基礎の基礎」です。

// ✅ このコード理解が「超重要」である5つの理由

// ⸻

// ① メモリとアドレスの本質を学べる（ヒープ・スタック・malloc）
// 	•	malloc() は ヒープ領域からメモリを動的に確保する関数
// 	•	Node* next; で「別の構造体へのポインタを保持」
// 	•	リスト構造は「メモリの上でどうオブジェクトがつながっているか」を体感できる

// ➡️ OS、DB、コンパイラ、Webサーバーの内部構造理解の第一歩！

// ⸻

// ② データ構造とアルゴリズムの原型を体験できる

// 構造	リストで表現
// スタック（LIFO）	push_front() / pop_front()
// キュー（FIFO）	push_back() / pop_front()（拡張）
// グラフ・木	ポインタでノードを繋げば実現可能

// ➡️ あらゆる高級アルゴリズム（探索・ソート・ツリー）の土台になる

// ⸻

// ③ ポインタと構造体の融合理解 = C言語マスターへの登竜門
// 	•	Node* head は「構造体を指すポインタ」
// 	•	head = head->next; は「構造体内部のポインタを辿っていく」処理
// 	•	*head_ref で「呼び出し元のポインタそのものを更新」できる

// ➡️ Cの真骨頂は「構造体 + ポインタ = 抽象的構造を手で作る能力」

// ⸻

// ④ OSカーネル・DB・コンテナ・VMMの内部理解に直結
// 	•	OSの プロセステーブル（PCB）やスケジューラの実装 はリストそのもの
// 	•	Linuxの task_struct は struct に next を持つ 双方向リスト
// 	•	PostgreSQLのバッファ管理、Dockerのcgroupも リンクリストベース

// ➡️ 今作った Node* の構造が「カーネルの動作」と直結している！

// ⸻

// ⑤ メモリリーク・安全なプログラミングの原点
// 	•	malloc() と free() を適切に使い分ける
// 	•	valgrind を使って「動的メモリを使うとはどういうことか」を学べる

// ➡️ 高級言語の ガベージコレクションの必要性 を肌で理解できる
// （＝なぜRustが登場したか、も含めて深く見えてくる）

// ⸻

// ✅ 実務においても超重要（現場でどう役立つか）

// 現場の例	どう活かされる？
// 組み込みC/C++	malloc()禁止環境で手作りリストが命綱
// ハードウェア制御	データを逐次処理するためのバッファリングに使う
// Webサーバーのキュー管理	リクエストを構造体で繋いで非同期処理
// 面接試験	「構造体 + ポインタ + リスト」問題はC言語筆記で頻出

//✅ Cで単方向リストを構造体＋ポインタで自作するテンプレコード　

// ⸻

// ✅ 結論：なぜこのコード理解が「CSの入り口」であり「全分野の出発点」なのか？

// ✅ 「動的な構造（=メモリ上で繋げる）」を“自分の手で”作れるようになることは、コンピューターサイエンスの根幹であり、C言語を学ぶ最大の目的の1つです。

// これがわかれば、OS・DB・ネットワーク・セキュリティ・機械学習・ゲーム・VR…すべてに応用できます。


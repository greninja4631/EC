#include <stdio.h>
#include <ctype.h>

void change_words(char *words[], int size, char *(*func)(char *))
{
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", func(words[i])); // 関数ポインタ func を使って処理
    }
}

// 文字列の最初の文字を大文字にする関数
char *capitalize(char *word)
{
    static char buffer[100]; // バッファを用意（ローカル変数のためstaticにする）
    int i = 0;

    while (word[i] != '\0')
    {
        buffer[i] = (i == 0) ? toupper(word[i]) : word[i]; // 先頭文字のみ大文字化
        i++;
    }
    buffer[i] = '\0'; // 文字列の終端を設定
    return buffer;    // 変換後の文字列を返す
}

int main()
{
    char *l[] = {"Mon", "tue", "Wed", "Thu", "fri", "sat", "Sun"};
    int size = sizeof(l) / sizeof(l[0]);

    change_words(l, size, capitalize); // 関数ポインタで処理を渡す
    return 0;
}
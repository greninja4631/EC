#include <stdio.h>

void henkann(char *str)
{
    while (*str)
    {
        if (*str == ' ')
        {
            *str = '_';
        }
        str++; // ✅ ループの最後で str++ する
    }
}

int main()
{
    char s[] = "DETH NOTE"; // ✅ 変更可能な配列
    henkann(s);
    printf("%s\n", s); // ✅ `print` → `printf`
    return 0;
}
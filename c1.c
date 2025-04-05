#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

void *simple_malloc(size_t size)
{
    size_t page_size = sysconf(_SC_PAGESIZE);
    size = (size + page_size - 1) & ~(page_size - 1); // アライメント調整
    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    return ptr == MAP_FAILED ? NULL : ptr;
}

void simple_free(void *ptr, size_t size)
{
    if (ptr)
        munmap(ptr, (size + sysconf(_SC_PAGESIZE) - 1) & ~(sysconf(_SC_PAGESIZE) - 1)); // アライメント調整
}

int main()
{
    int *arr = simple_malloc(10 * sizeof(int)); // メモリ確保
    if (!arr)
        return 1;

    for (size_t i = 0; i < 10; i++)
        printf("arr[%zu] = %d\n", i, (arr[i] = i * 2)); // 配列に値を設定して表示

    simple_free(arr, 10 * sizeof(int)); // メモリ解放
    return 0;
}
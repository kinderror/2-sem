#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

std::size_t type_size = sizeof(int);
int n = 5;

void generic_swap(void *lha, void *rha, std::size_t element_byte_syze)
{
    void * tmp = malloc(element_byte_syze);
    std::memcpy(tmp, lha, element_byte_syze);
    std::memcpy(lha, rha, element_byte_syze);
    std::memcpy(rha, tmp, element_byte_syze);
    free(tmp);
}

int cmp(const void *lha, const void *rha)
{
    int a = *(const int *)lha;
    int b = *(const int *)rha;
    return (b < a) - (a < b);
}

unsigned partition_by_number(void *src_begin, int l_idx, int r_idx, void *pivot, int (*compare)(const void *, const void *))
{
    while(true) {
        while (compare((const char *)src_begin + l_idx * type_size, (const char *)pivot) < 0) ++l_idx;
        while (compare((const char *)pivot, (const char *)src_begin + r_idx * type_size) < 0) --r_idx;
        if (r_idx <= l_idx) {
            return r_idx;
        }
        generic_swap((char *)src_begin + (l_idx++) * type_size, (char *)src_begin + (r_idx--) * type_size, type_size);
    }
    return r_idx;
}

void quick_sort(void *src_begin, int l_idx, int r_idx, int (*compare)(const void *, const void *))
{
    if (!(l_idx < r_idx))
    {
        return;
    }
    auto split_idx = partition_by_number(src_begin, l_idx, r_idx, (char *)src_begin + (l_idx + (r_idx - l_idx) / 2) * type_size, compare);
    quick_sort(src_begin, l_idx, split_idx, compare);
    quick_sort(src_begin, split_idx + 1, r_idx, compare);
}

void qsort(void *src_begin, size_t n_memb, size_t type_size, int(*compare)(const void *, const void *))
{
    quick_sort(src_begin, 0, n - 1, compare);
}

int main()
{
    int m;
    std::cin >> m;
    int data[n];
    for (int i = 0; i < n; i++) {
        std::cin >> data[i];
    }
    int (*bar)(const void *, const void *) = cmp;
    qsort(data, sizeof(int), type_size, bar);
    for (int i = 0; i < n; i++) {
        std::cout << data[i] << ' ';
    }
    return 0;
}

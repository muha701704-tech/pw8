#include <stdio.h>
#include "myarrfunc.h"

static int read_int(const char *message, int *number)
{
    char line[100];
    char extra;

    while (1) {
        printf("%s", message);
        if (fgets(line, sizeof(line), stdin) == NULL)
            return 0;

        if (sscanf(line, " %d %c", number, &extra) == 1)
            return 1;

        printf("Введите одно целое число.\n");
    }
}

int choose_size(size_t *n)
{
    int size;

    while (1) {
        if (!read_int("Размер массива (1-100): ", &size))
            return 0;

        if (size >= 1 && size <= 100) {
            *n = (size_t)size;
            return 1;
        }

        printf("Размер должен быть от 1 до 100.\n");
    }
}

int fill_array(int *arrptr, size_t n)
{
    size_t i;

    for (i = 0; i < n; i++) {
        printf("Элемент [%zu]: ", i);
        if (!read_int("", arrptr + i))
            return 0;
    }

    return 1;
}

void show_array(const int *arrptr, size_t n)
{
    size_t i;

    for (i = 0; i < n; i++) {
        printf("arr[%zu] = %d, адрес = %p\n",
               i, *(arrptr + i), (const void *)(arrptr + i));
    }
}

int read_index_range(size_t n, size_t *k, size_t *m)
{
    int first, last;

    while (1) {
        if (!read_int("Начальный индекс k: ", &first))
            return 0;
        if (!read_int("Конечный индекс m: ", &last))
            return 0;

        if (first >= 0 && last >= first && (size_t)last < n) {
            *k = (size_t)first;
            *m = (size_t)last;
            return 1;
        }

        printf("Нужно 0 <= k <= m < %zu.\n", n);
    }
}

int read_value_range(int *k, int *m)
{
    while (1) {
        if (!read_int("Минимальное значение k: ", k))
            return 0;
        if (!read_int("Максимальное значение m: ", m))
            return 0;

        if (*k <= *m)
            return 1;

        printf("k не должно быть больше m.\n");
    }
}

long long sum_index_range(const int *arrptr, size_t n, size_t k, size_t m)
{
    size_t i;
    long long sum = 0;

    if (k > m || m >= n)
        return 0;

    for (i = k; i <= m; i++)
        sum += *(arrptr + i);

    return sum;
}

int find_value_indexes(const int *arrptr, size_t n, int k, int m)
{
    size_t i;
    int count = 0;

    printf("Подходящие индексы: ");
    for (i = 0; i < n; i++) {
        if (*(arrptr + i) >= k && *(arrptr + i) <= m) {
            printf("%zu ", i);
            count++;
        }
    }

    if (count == 0)
        printf("не найдены");
    printf("\n");

    if (count == 0)
        return -1;

    return count;
}

int find_above_average(const int *arrptr, size_t n)
{
    size_t i;
    long long sum = 0;
    double average;
    int count = 0;

    for (i = 0; i < n; i++)
        sum += *(arrptr + i);

    average = (double)sum / n;
    printf("Среднее значение: %.2f\n", average);
    printf("Индексы элементов выше среднего: ");

    for (i = 0; i < n; i++) {
        if (*(arrptr + i) > average) {
            printf("%zu ", i);
            count++;
        }
    }

    if (count == 0)
        printf("не найдены");
    printf("\n");

    if (count == 0)
        return -1;

    return count;
}

#include <stdio.h>
#include "myarrfunc.h"

int main(void)
{
    int arr[100];
    size_t n = 0, k, m;
    int filled = 0;
    int min_value, max_value;
    char line[20];
    char choice;

    while (1) {
        printf("\na - Задать размер массива\n");
        printf("b - Заполнить массив\n");
        printf("c - Показать массив и адреса\n");
        printf("d - Сумма элементов от индекса k до m\n");
        printf("e - Индексы элементов со значениями от k до m\n");
        printf("f - Индексы элементов выше среднего\n");
        printf("g - Выход\n");
        printf("Выберите пункт: ");

        if (fgets(line, sizeof(line), stdin) == NULL)
            break;

        if (line[1] != '\n' && line[1] != '\0') {
            printf("Выберите одну букву от a до g.\n");
            continue;
        }

        choice = line[0];
        if (choice == 'g')
            break;

        if (choice == 'a') {
            if (!choose_size(&n))
                break;
            filled = 0;
        } else if (choice == 'b') {
            if (n == 0) {
                printf("Сначала задайте размер массива.\n");
                continue;
            }
            if (!fill_array(arr, n))
                break;
            filled = 1;
        } else if (choice == 'c') {
            if (!filled) {
                printf("Сначала задайте размер и заполните массив.\n");
                continue;
            }
            show_array(arr, n);
        } else if (choice == 'd') {
            if (!filled) {
                printf("Сначала заполните массив.\n");
                continue;
            }
            if (!read_index_range(n, &k, &m))
                break;
            printf("Сумма = %lld\n", sum_index_range(arr, n, k, m));
        } else if (choice == 'e') {
            if (!filled) {
                printf("Сначала заполните массив.\n");
                continue;
            }
            if (!read_value_range(&min_value, &max_value))
                break;
            find_value_indexes(arr, n, min_value, max_value);
        } else if (choice == 'f') {
            if (!filled) {
                printf("Сначала заполните массив.\n");
                continue;
            }
            find_above_average(arr, n);
        } else {
            printf("Такого пункта нет.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

int main() {
    int n, choice;
    srand(time(NULL)); // щоб випадкові числа щоразу були новими

    while (1) {
        printf("\n--- МЕНЮ ---\n");
        printf("1. Ввести масив з клавіатури (Варіант А)\n");
        printf("2. Заповнити масив випадково [-100, 100] (Варіант Б)\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        if (choice == 0) break; // вихід з циклу

        printf("Введіть кількість елементів n: ");
        scanf("%d", &n);
        int a[n];

        switch (choice) {
            case 1:
                printf("Введіть %d чисел:\n", n);
                for (int i = 0; i < n; i++) {
                    printf("a[%d] = ", i);
                    scanf("%d", &a[i]);
                }
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    a[i] = rand() % 201 - 100; // Генерація від -100 до 100
                }
                printf("Згенерований масив: ");
                for (int i = 0; i < n; i++) printf("%d ", a[i]);
                printf("\n");
                break;
            default:
                printf("Невірний вибір!\n");
                continue;
        }

        // Тут ми рахуємо

        // Кількість елементів, менших за 7
        int count_less_7 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < 7) count_less_7++;
        }

        // Сума між першим і останнім додатними
        int first_pos = -1, last_pos = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                if (first_pos == -1) first_pos = i;
                last_pos = i;
            }
        }

        long sum_between = 0;
        if (first_pos != -1 && last_pos != -1 && first_pos != last_pos) {
            for (int i = first_pos + 1; i < last_pos; i++) {
                sum_between += a[i];
            }
            printf("Кількість менших за 7: %d\n", count_less_7);
            printf("Сума між першим і останнім додатними: %ld\n", sum_between);
        } else {
            printf("Кількість менших за 7: %d\n", count_less_7);
            printf("Недостатньо додатних чисел для знаходження суми між ними.\n");
        }
    }

    printf("Програму завершено.\n");
    return 0;
}
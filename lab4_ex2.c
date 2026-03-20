#include <stdio.h>

int main() {
    int choice;
    int sum, count, i;
    float average;

    printf("Комплексна програма обчислення середнього арифметичного непарних [1;80]\n");
    printf("Виберіть тип циклу для розрахунку:\n");
    printf("1. А) Цикл з параметром (for)\n");
    printf("2. Б) Цикл з передумовою (while)\n");
    printf("3. В) Цикл з післяумовою (do...while)\n");
    printf("Ваш вибір: ");
    scanf("%d", &choice);

    sum = 0;
    count = 0;

    printf("\nРезультат:\n");

    switch (choice) {
        case 1:
            for (i = 1; i <= 80; i++) {
                if (i % 2 != 0) {
                    sum += i;
                    count++;
                }
            }
            printf("Використано цикл 'for'.\n");
            break;

        case 2:
            i = 1;
            while (i <= 80) {
                if (i % 2 != 0) {
                    sum += i;
                    count++;
                }
                i++;
            }
            printf("Використано цикл 'while'.\n");
            break;

        case 3:
            i = 1;
            do {
                if (i % 2 != 0) {
                    sum += i;
                    count++;
                }
                i++;
            } while (i <= 80);
            printf("Використано цикл 'do...while'.\n");
            break;

        default:
            printf("Помилка: Вибрано неіснуючий варіант!\n");
            return 1;
    }

    if (count > 0) {
        average = (float)sum / count;
        printf("Середнє арифметичне непарних чисел: %.2f\n", average);
    }

    return 0;
}
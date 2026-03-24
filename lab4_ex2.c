#include <stdio.h>

int main() {
    int choice;
    
    do {
        int sum = 0, count = 0, i;
        float average;

        printf("\nМеню обчислення середнього арифметичного непарних [1;80]\n");
        printf("1. Цикл з параметром (for)\n");
        printf("2. Цикл з передумовою (while)\n");
        printf("3. Цикл з післяумовою (do...while)\n");
        printf("0. Вихід з програми\n");
        printf("Ваш вибір: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Помилка: введіть число!\n");
            while(getchar() != '\n'); 
            continue;
        }

        if (choice == 0) {
            printf("Завершення роботи. Бувай!\n");
            break; 
        }

        switch (choice) {
            case 1:
                for (i = 1; i <= 80; i++) {
                    if (i % 2 != 0) {
                        sum += i;
                        count++;
                    }
                }
                printf("\n[Результат]: Використано цикл 'for'.\n");
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
                printf("\n[Результат]: Використано цикл 'while'.\n");
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
                printf("\n[Результат]: Використано 'do...while'.\n");
                break;

            default:
                printf("\nПомилка: Вибрано неіснуючий варіант! Спробуйте ще раз.\n");
                continue; 
        }

        if (count > 0) {
            average = (float)sum / count;
            printf("Середнє арифметичне непарних чисел: %.2f\n", average);
        }

    } while (choice != 0); 

    return 0;
}

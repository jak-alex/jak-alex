#include <stdio.h>

int main() {
    int n;

    do {
        printf("\n==============================\n");
        printf("             МЕНЮ              \n");
        printf("==============================\n");
        printf(" 1-12 - Дізнатися назву місяця\n");
        printf("  0   - Вийти з програми\n");
        printf("------------------------------\n");
        printf("Ваш вибір: ");

        // Перевірка на введення тексту замість числа
        if (scanf("%d", &n) != 1) {
            printf("\n[!] Помилка: Вводьте лише цифри!\n");
            while (getchar() != '\n'); 
            continue; 
        }

       
        if (n == 0) {
            printf("\nЗавершення роботи. Гарного дня!\n");
            break; // Вихід із циклу
        }

        printf("Результат: ");
        switch(n) {
            case 1:  printf("Січень");   break;
            case 2:  printf("Лютий");    break;
            case 3:  printf("Березень"); break;
            case 4:  printf("Квітень");  break;
            case 5:  printf("Травень");  break;
            case 6:  printf("Червень");  break;
            case 7:  printf("Липень");   break;
            case 8:  printf("Серпень");  break;
            case 9:  printf("Вересень"); break;
            case 10: printf("Жовтень");  break;
            case 11: printf("Листопад"); break;
            case 12: printf("Грудень");  break;
            default: printf("Помилка! Введіть число від 1 до 12.");
        }
        printf("\n");

    } while (n != 0); // Цикл працює, поки n не дорівнює 0

    return 0;
}
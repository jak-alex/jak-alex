#include <stdio.h>
#include <math.h>

int main() {
    double a, b, y;
    int c, choice;

    // Меню вибору
    printf("Виберіть варіант програми:\n");
    printf("1 - Варіант А (скорочена форма if)\n");
    printf("2 - Варіант Б (повна форма if...else if)\n");
    printf("Ваш вибір: ");
    scanf("%d", &choice);

    // Введення даних
    printf("\nВведіть дійсні числа a, b та ціле число c: ");
    scanf("%lf %lf %d", &a, &b, &c);

    switch (choice) {
        case 1:
            printf("--- Варіант А ---\n");
            if (c > 0) y = sqrt(b - a) + 2 * sqrt(c);
            if (c == 0) y = b / (c - 6 * a);
            if (c < 0) y = b + 12 * c * c * c;
            break;

        case 2:
            printf("--- Варіант Б ---\n");
            if (c > 0) {
                y = sqrt(b - a) + 2 * sqrt(c);
            } else if (c == 0) {
                y = b / (c - 6 * a);
            } else {
                y = b + 12 * c * c * c;
            }
            break;

        default:
            printf("Помилка: треба було вибрати 1 або 2!\n");
            return 1;
    }

    // Вивід результату
    printf("Результат y = %.2f\n", y);

    return 0;
}
#include <stdio.h>

// Функція-лічильник
int countVariants(int pos, int used_mask, int type) {
    // Якщо ми заповнили всі 3 позиції, ми знайшли 1 правильне число
    if (pos == 3) return 1;

    int count = 0;
    int digits[] = {0, 1, 2, 3, 4, 5};

    for (int i = 0; i < 6; i++) {
        int d = digits[i];

        // Перша цифра не може бути нулем
        if (pos == 0 && d == 0) continue;

        // Цифри не повинні повторюватися
        if (type == 2 && (used_mask & (1 << d))) continue;

        // Цифри мають бути непарними 
        if (type == 3 && (d % 2 == 0)) continue;

        // Рекурсивний виклик для наступної позиції
        count += countVariants(pos + 1, used_mask | (1 << d), type);
    }

    return count;
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Меню ---\n");
        printf("1. Цифри можуть повторюватися\n");
        printf("2. Цифри НЕ повторюються (унікальні)\n");
        printf("3. Цифри непарні та можуть повторюватися\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        if (choice == 0) break;

        int result = 0;
        switch (choice) {
            case 1:
                result = countVariants(0, 0, 1);
                printf("Кількість чисел (з повторами): %d\n", result);
                break;
            case 2:
                result = countVariants(0, 0, 2);
                printf("Кількість чисел (без повторів): %d\n", result);
                break;
            case 3:
                result = countVariants(0, 0, 3);
                printf("Кількість чисел (непарні): %d\n", result);
                break;
            default:
                printf("Невірний вибір.\n");
        }
    }
    return 0;
}
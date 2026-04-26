#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для характеристик комп'ютера
typedef struct {
    char cpu_type[30];
    float frequency; // Частота в ГГц
    int ram;         // Оперативка в ГБ
    int disk;        // Диск в ГБ
    char monitor[30];
} Computer;

void clear_kb() {
    while (getchar() != '\n');
}

int main() {
    int choice, n = 0;
    Computer *list = NULL; 

    while (1) {
        printf("\n--- Меню ---\n");
        printf("1. Ввести дані про комп'ютери\n");
        printf("2. Сортувати за CPU та вивести таблицю\n");
        printf("3. Знайти найкращий комп'ютер\n");
        printf("0. Вихід\n");
        printf("Вибір: ");

        if (scanf("%d", &choice) != 1) { clear_kb(); continue; }
        if (choice == 0) break;

        switch (choice) {
            case 1:
                printf("Скільки комп'ютерів додати? ");
                scanf("%d", &n);
                // Динамічно виділяємо (або перерозподіляємо) пам'ять під n елементів
                list = (Computer*)realloc(list, n * sizeof(Computer));
                for (int i = 0; i < n; i++) {
                    printf("ПК #%d (Формат: CPU Частота RAM Disk Монітор): ", i + 1);
                    // Зчитуємо дані через пробіл
                    scanf("%s %f %d %d %s", list[i].cpu_type, &list[i].frequency, &list[i].ram, &list[i].disk, list[i].monitor);
                }
                break;

            case 2:
                if (n == 0) { printf("Масив порожній!\n"); break; }
                // Сортування за типом процесора (алфавітне)
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (strcmp(list[j].cpu_type, list[j + 1].cpu_type) > 0) {
                            Computer temp = list[j];
                            list[j] = list[j + 1];
                            list[j + 1] = temp;
                        }
                    }
                }
                // Виведення результатів
                printf("\n%-15s %-10s %-8s %-8s %-15s\n", "Процесор", "Freq", "RAM", "Disk", "Монітор");
                for (int i = 0; i < n; i++)
                    printf("%-15s %-10.2f %-8d %-8d %-15s\n", list[i].cpu_type, list[i].frequency, list[i].ram, list[i].disk, list[i].monitor);
                break;

            case 3:
                if (n == 0) break;
                int best_idx = 0;
                // Шукаємо ПК з максимальними показниками (сумарно або за пріоритетом)
                for (int i = 1; i < n; i++) {
                    if (list[i].frequency > list[best_idx].frequency) {
                        best_idx = i;
                    }
                }
                printf("\nПК з макс. частотою: %s (%.2f GHz)\n", list[best_idx].cpu_type, list[best_idx].frequency);
                break;
        }
    }
    free(list); // Очищення пам'яті
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Описуємо структуру: групуємо різні типи даних про один пакет в один об'єкт
typedef struct {
    char name[30];          // Назва
    char manufacturer[30];  // Виробник
    int components;         // Ціле число для кількості частин
    int price;              // Ціле число для ціни
} OfficeSuite;

// Функція для очищення вхідного потоку (щоб програма не косячила при помилках)
void clear_buffer() {
    while (getchar() != '\n');
}

int main() {
    int choice;
    int n = 3; // За умовою у нас 3 рядки в таблиці

    // Виділяємо пам'ять під масив з 3-х структур OfficeSuite
    OfficeSuite *suites = (OfficeSuite*)malloc(n * sizeof(OfficeSuite));

    // Заповнюємо масив даними з картинки (використовуємо strcpy для копіювання рядків)
    strcpy(suites[0].name, "Office"); 
    strcpy(suites[0].manufacturer, "Microsoft"); 
    suites[0].components = 4; suites[0].price = 870;

    strcpy(suites[1].name, "SmartSute"); 
    strcpy(suites[1].manufacturer, "Lotus"); 
    suites[1].components = 5; suites[1].price = 1020;

    strcpy(suites[2].name, "StarOffice"); 
    strcpy(suites[2].manufacturer, "Sun"); 
    suites[2].components = 4; suites[2].price = 9;

    while (1) {
        printf("\n--- Меню: Завдання 1 (Офісні пакети) ---\n");
        printf("1. Вивести відсортовану таблицю\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");

        if (scanf("%d", &choice) != 1) { clear_buffer(); continue; }
        if (choice == 0) break;

        // Сортування за алфавітом 
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                // strcmp повертає > 0, якщо перший рядок "більший" за другий
                if (strcmp(suites[j].name, suites[j + 1].name) > 0) {
                    // Міняємо структури місцями через тимчасову змінну temp
                    OfficeSuite temp = suites[j];
                    suites[j] = suites[j + 1];
                    suites[j + 1] = temp;
                }
            }
        }

        printf("\n--------------------------------------------------------------------------\n");
        printf("| %-15s | %-12s | %-20s | %-8s |\n", "Назва", "Виробник", "Кількість частин", "Ціна ($)");
        printf("--------------------------------------------------------------------------\n");
        
        // Виводимо дані кожного пакета
        for (int i = 0; i < n; i++) {
            printf("| %-15s | %-12s | %-20d | %-8d |\n", 
                    suites[i].name, suites[i].manufacturer, suites[i].components, suites[i].price);
        }
        printf("--------------------------------------------------------------------------\n");
        printf("Зауваження: можливо безкоштовно отримати продукт StarOffice через Internet\n");
    }

    free(suites); // Звільняємо пам'ять перед закриттям
    return 0;
}
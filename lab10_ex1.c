#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char filename[] = "text.txt"; // Назва файлу за замовчуванням
    FILE *file;

    while (1) {
        // Контекстне меню
        printf("\n--- МЕНЮ ПРОГРАМИ ---\n");
        printf("1. Порахувати кількість речень у файлі %s\n", filename);
        printf("2. Довідка про програму\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Помилка: введіть число!\n");
            while (getchar() != '\n'); // Очищення буфера
            continue;
        }

        switch (choice) {
            case 1:
                file = fopen(filename, "r");
                if (file == NULL) {
                    printf("\n[ПОМИЛКА] Не вдалося відкрити файл '%s'.\n", filename);
                    printf("Переконайтеся, що файл створили в папці з проектом.\n");
                } else {
                    int sentence_count = 0;
                    char ch;

                    // Читаємо файл посимвольно до кінця (EOF)
                    while ((ch = fgetc(file)) != EOF) {
                        // Перевірка на знаки завершення речення
                        if (ch == '.' || ch == '?' || ch == '!') {
                            sentence_count++;
                        }
                    }

                    printf("\nРезультат: У тексті знайдено %d речень.\n", sentence_count);
                    fclose(file);
                }
                break;

            case 2:
                printf("\n--- ДОВІДКА ---\n");
                printf("Програма рахує речення за символами '.', '?' та '!'.\n");
                printf("Файл має бути у форматі ANSI або UTF-8 без BOM.\n");
                break;

            case 0:
                printf("Вихід з програми. Гарного дня!\n");
                return 0;

            default:
                printf("Такого пункту не існує. Спробуйте ще раз.\n");
        }
    }

    return 0;
}
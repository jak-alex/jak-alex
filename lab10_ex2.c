#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функція для видалення рядка за його номером
void deleteLine(const char *filename, int lineToDelete) {
    FILE *src = fopen(filename, "r");
    FILE *temp = fopen("temp.tmp", "w");
    
    if (src == NULL || temp == NULL) {
        printf("\n[ПОМИЛКА] Не вдалося відкрити файл для обробки.\n");
        return;
    }

    char buffer[1024];
    int currentLine = 1;
    int found = 0;

    // Читаємо файл рядок за рядком
    while (fgets(buffer, sizeof(buffer), src)) {
        // Якщо номер рядка не збігається з тим, що треба видалити — записуємо його в тимчасовий файл
        if (currentLine != lineToDelete) {
            fputs(buffer, temp);
        } else {
            found = 1;
        }
        currentLine++;
    }

    fclose(src);
    fclose(temp);

    // Видаляємо старий файл і перейменовуємо тимчасовий
    if (found) {
        remove(filename);
        rename("temp.tmp", filename);
        printf("\nРядок №%d успішно видалено.\n", lineToDelete);
    } else {
        remove("temp.tmp");
        printf("\n[УВАГА] Рядок №%d не знайдено у файлі.\n", lineToDelete);
    }
}

int main() {

    int choice;
    char filename[] = "data.txt";

    while (1) {
        printf("\n--- МЕНЮ ---\n");
        printf("1. Переглянути вміст файлу\n");
        printf("2. Видалити рядок за номером\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");

        if (scanf("%d", &choice) != 1) {
            printf("Помилка: введіть число!\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1: {
                FILE *f = fopen(filename, "r");
                if (!f) {
                    printf("Файл не знайдено.\n");
                } else {
                    char buf[1024];
                    int n = 1;
                    printf("\n--- Вміст файлу %s ---\n", filename);
                    while (fgets(buf, sizeof(buf), f)) {
                        printf("%d: %s", n++, buf);
                    }
                    fclose(f);
                }
                break;
            }
            case 2: {
                int lineNum;
                printf("Введіть номер рядка для видалення: ");
                scanf("%d", &lineNum);
                deleteLine(filename, lineNum);
                break;
            }
            case 0:
                return 0;
            default:
                printf("Невірний вибір.\n");
        }
    }
    return 0;
}
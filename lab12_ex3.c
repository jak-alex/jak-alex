#include <stdio.h>
#include <stdlib.h>

// Спрощена структура для файлових операцій
typedef struct {
    char cpu_type[30];
    float frequency;
    int ram;
    int disk;
} CompData;

int main() {
    int choice;
    char filename[] = "storage.dat"; // Ім'я бінарного файлу

    while (1) {
        printf("\n--- Меню ---\n");
        printf("1. Записати дані у файл\n");
        printf("2. Прочитати з файлу та знайти результат\n");
        printf("0. Вихід\n");
        printf("Вибір: ");

        if (scanf("%d", &choice) != 1) { while(getchar()!='\n'); continue; }
        if (choice == 0) break;

        if (choice == 1) {
            // "wb" - write binary (запис у бінарному вигляді)
            FILE *f = fopen(filename, "wb"); 
            if (!f) { printf("Помилка файлу!\n"); continue; }

            int n;
            printf("Кількість ПК для запису: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                CompData temp;
                printf("Введіть (CPU Freq RAM Disk): ");
                scanf("%s %f %d %d", temp.cpu_type, &temp.frequency, &temp.ram, &temp.disk);
                // Записуємо весь блок даних (структуру) одним махом
                fwrite(&temp, sizeof(CompData), 1, f);
            }
            fclose(f); // Закриваємо файл
            printf("Дані збережені у %s\n", filename);

        } else if (choice == 2) {
            // "rb" - read binary (читання бінарного файлу)
            FILE *f = fopen(filename, "rb"); 
            if (!f) { printf("Файл не знайдено!\n"); continue; }

            CompData temp, best;
            int found = 0;
            printf("\n--- Вміст файлу ---\n");
            // fread повертає кількість успішно зчитаних об'єктів (1 або 0 в кінці файлу)
            while (fread(&temp, sizeof(CompData), 1, f)) {
                printf("CPU: %s | RAM: %d GB\n", temp.cpu_type, temp.ram);
                // Логіка пошуку: наприклад, найбільший обсяг RAM
                if (!found || temp.ram > best.ram) {
                    best = temp;
                    found = 1;
                }
            }
            fclose(f);
            
            if (found) {
                printf("\nЗнайдено ПК з найбільшою RAM: %s (%d GB)\n", best.cpu_type, best.ram);
                
                // Додатковий пункт завдання: запис результату в текстовий файл
                FILE *res_file = fopen("result.txt", "w");
                if (res_file) {
                    fprintf(res_file, "Найкращий результат: %s, RAM: %d GB", best.cpu_type, best.ram);
                    fclose(res_file);
                    printf("Результат розрахунку збережено у result.txt\n");
                }
            }
        }
    }
    return 0;
}
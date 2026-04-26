#include <stdio.h>   
#include <stdlib.h>  

// Визначаємо структуру книги
typedef struct {
    char author[50];    // Масив для прізвища автора
    char title[50];     // Масив для назви книги
    char publisher[50]; // Масив для назви видавництва
    int year;           // Ціле число для року видання
} Book;

int main() {
    int choice;
    char binary_filename[] = "library.dat"; // Назва "сирого" бінарного файлу

    while (1) {
        printf("\n==========================================\n");
        printf("                   МЕНЮ                    \n");
        printf("==========================================\n");
        printf("1. Ввести книги та зберегти у бінарний файл\n");
        printf("2. Прочитати файл та відфільтрувати книги (>2000)\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");

        // Захист від введення літер замість цифр
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Очищуємо буфер від "сміття"
            continue;
        }

        if (choice == 0) break; // Вихід з нескінченного циклу

        if (choice == 1) {
            // "wb" - write binary. Створюємо новий файл або перезаписуємо старий
            FILE *f = fopen(binary_filename, "wb"); 
            if (!f) {
                printf("Помилка: не вдалося створити файл!\n");
                continue;
            }

            int n;
            printf("Скільки книг ви хочете внести в базу? ");
            scanf("%d", &n);

            for (int i = 0; i < n; i++) {
                Book temp;
                printf("\n--- Книга #%d ---\n", i + 1);
                printf("Автор (без пробілів): "); scanf("%s", temp.author);
                printf("Назва (без пробілів): "); scanf("%s", temp.title);
                printf("Видавництво: ");          scanf("%s", temp.publisher);
                printf("Рік видання: ");         scanf("%d", &temp.year);

                // fwrite записує блок пам'яті прямо у файл.
                // sizeof(Book) каже комп'ютеру, скільки байтів займає одна структура.
                fwrite(&temp, sizeof(Book), 1, f);
            }

            fclose(f); // ЗАКРИВАЄМО файл, щоб дані реально збереглися на диску
            printf("\nДані успішно збережені у файлі %s\n", binary_filename);

        } else if (choice == 2) {
            // "rb" - read binary. Відкриваємо файл тільки для читання
            FILE *bin_file = fopen(binary_filename, "rb");
            if (!bin_file) {
                printf("Помилка: файл %s не знайдено! Спочатку оберіть пункт 1.\n", binary_filename);
                continue;
            }

            // "w" - звичайний текстовий запис. Створюємо звіт для людини
            FILE *txt_report = fopen("modern_books.txt", "w");
            
            Book b;
            int found = 0;
            printf("\n--- КНИГИ, ВИДАНІ ПІСЛЯ 2000 РОКУ ---\n");
            fprintf(txt_report, "ЗВІТ: Книги після 2000 року\n\n");

            // fread повертає 1, поки успішно зчитує по одному блоку розміром sizeof(Book)
            while (fread(&b, sizeof(Book), 1, bin_file)) {
                // ПЕРЕВІРКА УМОВИ ВАРІАНТА 11
                if (b.year > 2000) {
                    // Виводимо в консоль
                    printf("Автор: %-15s | Назва: %-20s | Рік: %d\n", b.author, b.title, b.year);
                    
                    // Записуємо у текстовий файл через fprintf (як printf, але у файл)
                    fprintf(txt_report, "Автор: %s, Назва: \"%s\", Рік: %d\n", b.author, b.title, b.year);
                    found = 1;
                }
            }

            if (!found) printf("Таких книг у базі немає.\n");

            fclose(bin_file);  // Закриваємо бінарний файл
            fclose(txt_report); // Закриваємо текстовий звіт
            printf("\nРезультати фільтрації збережені у 'modern_books.txt'\n");
        }
    }

    printf("Програму завершено. Успіхів!\n");
    return 0;
}

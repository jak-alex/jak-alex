#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Перевірка на голосні
int is_vowel(char c) {
    c = tolower(c); // Переводимо у нижній регістр
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
        return 1;
    }
    return 0;
}

int main() {
    char str[256] = ""; // Масив для зберігання рядка 
    int choice;

    do {
        printf("\n--- МЕНЮ ---\n");
        printf("1. Ввести текстовий рядок\n");
        printf("2. Слово з найбільшою кількістю голосних (латиниця)\n");
        printf("3. Видалити зайві пробіли з тексту\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            continue;
        }
        
        while (getchar() != '\n'); // Очищення буфера

        switch (choice) {
            case 1:
                printf("Введіть текст (латиницею): ");
                fgets(str, sizeof(str), stdin); // Безпечне введення рядка 
                str[strcspn(str, "\n")] = '\0'; // Видалення символу переходу на новий рядок 
                printf("Рядок збережено.\n");
                break;

            case 2:
                if (strlen(str) == 0) {
                    printf("Помилка: Спочатку введіть текст у пункті 1.\n");
                } else {
                    char temp[256];
                    char max_word[100] = "";
                    int max_count = -1;

                    strcpy(temp, str); // Копіюємо рядок для роботи 
                    char *token = strtok(temp, " ,.!?;-"); // Розбиваємо слова

                    while (token != NULL) {
                        int current_count = 0;
                        for (int i = 0; token[i] != '\0'; i++) {
                            if (is_vowel(token[i])) {
                                current_count++;
                            }
                        }

                        if (current_count > max_count) {
                            max_count = current_count;
                            strcpy(max_word, token);
                        }
                        token = strtok(NULL, " ,.!?;-");
                    }

                    if (max_count > 0)
                        printf("Результат: Слово '%s' має найбільше голосних (%d).\n", max_word, max_count);
                    else
                        printf("Голосних літер у словах не знайдено.\n");
                }
                break;

            case 3:
                if (strlen(str) == 0) {
                    printf("Помилка: Текст порожній!\n");
                } else {
                    printf("Текст без зайвих пробілів: ");
                    int space_found = 0;
                    int i = 0;

                    // Пропускаємо пробіли на самому початку 
                    while (str[i] != '\0' && isspace((unsigned char)str[i])) {
                        i++;
                    }

                    for (; str[i] != '\0'; i++) {
                        if (!isspace((unsigned char)str[i])) {
                            putchar(str[i]); // Виводимо символ 
                            space_found = 0;
                        } else if (space_found == 0) {
                            // Якщо це перший пробіл після слова, і далі не кінець рядка
                            if (str[i+1] != '\0' && !isspace((unsigned char)str[i+1])) {
                                putchar(' ');
                                space_found = 1;
                            }
                        }
                    }
                    printf("\n");
                }
                break;

            case 0:
                printf("Завершення роботи\n");
                break;

            default:
                printf("Невірний вибір, спробуйте ще раз.\n");
        }
    } while (choice != 0);

    return 0;
}
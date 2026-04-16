#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Передаємо адресу n через вказівник
void generateArray(int *arr, int *n); 
void printArray(const int *arr, int n);
int getMinIndex(const int *arr, int n);
long long getProductBeforeZero(const int *arr, int n, int *found);

int main() {
    int n = 0;
    int a[100]; 
    int choice;

    do {
        printf("\n--- ГОЛОВНЕ МЕНЮ ---\n");
        printf("1. Згенерувати масив [-100; 100]\n");
        printf("2. Обчислити результати\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateArray(a, &n); // Передаємо адресу n
                printArray(a, n);
                break;
            case 2:
                if (n == 0) {
                    printf("Помилка: Масив ще не створено!\n");
                } else {
                    // Номер мінімального елемента
                    int minIdx = getMinIndex(a, n);
                    printf("1. Номер мінімального елемента: %d\n", minIdx);

                    // Добуток до першого нуля
                    int hasZero = 0;
                    long long product = getProductBeforeZero(a, n, &hasZero);
                    
                    if (hasZero) {
                        printf("2. Добуток елементів до першого нуля: %lld\n", product);
                    } else {
                        printf("2. Нуль у масиві не знайдено.\n");
                    }
                }
                break;
            case 0:
                printf("Програма завершена\n");
                break;
            default:
                printf("Невірний пункт.\n");
        }
    } while (choice != 0);

    return 0;
}

// Реалізація через вказівники 
void generateArray(int *arr, int *n) {
    printf("Введіть розмір масиву: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        *(arr + i) = rand() % 201 - 100; 
    }
}

void printArray(const int *arr, int n) {
    printf("Масив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int getMinIndex(const int *arr, int n) {
    int minVal = *arr;
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) < minVal) {
            minVal = *(arr + i);
            index = i;
        }
    }
    return index;
}

long long getProductBeforeZero(const int *arr, int n, int *found) {
    long long prod = 1;
    *found = 0;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == 0) {
            *found = 1;
            return prod;
        }
        prod *= *(arr + i);
    }
    return 0;
}
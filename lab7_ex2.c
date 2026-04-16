#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10

// Прототипи функцій
void initArray(int arr[], int n);
void printArray(int arr[], int n);
int countZeros(int arr[], int n);
long long productAfterMaxAbs(int arr[], int n);

int main() {
    int array[SIZE];
    int choice;
    
    // Ініціалізація генератора випадкових чисел 
    srand(time(NULL));

    while (1) {
        printf("\n--- МЕНЮ ---\n");
        printf("1. Сформувати масив випадковими числами [-100, 100]\n");
        printf("2. Вивести масив на екран\n");
        printf("3. Знайти кількість нульових елементів\n");
        printf("4. Знайти добуток елементів після макс. за модулем\n");
        printf("5. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initArray(array, SIZE);
                printf("Масив сформовано.\n");
                break;
            case 2:
                printArray(array, SIZE);
                break;
            case 3:
                printf("Кількість нулів: %d\n", countZeros(array, SIZE));
                break;
            case 4: {
                long long prod = productAfterMaxAbs(array, SIZE);
                if (prod == 0 && array[SIZE-1] != 0) {
                    printf("Після максимального за модулем елементів немає або добуток 0.\n");
                } else {
                    printf("Добуток після макс. за модулем: %lld\n", prod);
                }
                break;
            }
            case 5:
                return 0;
            default:
                printf("Невірний вибір!\n");
        }
    }
}

// Функція ініціалізації масиву випадковими числами 
void initArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 201 - 100; // Діапазон [-100; 100]
    }
}

// Функція виведення масиву 
void printArray(int arr[], int n) {
    printf("Масив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Кількість нульових елементів 
int countZeros(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) count++;
    }
    return count;
}

// Добуток елементів після максимального за модулем 
long long productAfterMaxAbs(int arr[], int n) {
    int maxAbsIndex = 0;
    int maxAbsValue = abs(arr[0]);

    // Шукаємо індекс максимального за модулем елемента
    for (int i = 1; i < n; i++) {
        if (abs(arr[i]) > maxAbsValue) {
            maxAbsValue = abs(arr[i]);
            maxAbsIndex = i;
        }
    }

    // Якщо максимальний елемент останній, добутку не буде
    if (maxAbsIndex == n - 1) return 0;

    long long prod = 1;
    for (int i = maxAbsIndex + 1; i < n; i++) {
        prod *= arr[i];
    }
    return prod;
}

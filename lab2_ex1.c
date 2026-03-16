#include <stdio.h>
#include <math.h> 

int main() {
    // Оголошення змінних
    int num1, num2;
    int remainder, quotient, product;
    
    printf("--- Програма для обчислення чисел (Варіант 6) ---\n");

    // Введення даних
    printf("Введіть перше ціле число: ");
    scanf("%d", &num1);

    printf("Введіть друге ціле число: ");
    scanf("%d", &num2);

    remainder = num2 % num1;

    quotient = num1 / num2;

    product = num1 * num2;

    printf("\n--- Результати обчислень ---\n");
    printf("1) Залишок від ділення %d на %d дорівнює: %d\n", num2, num1, remainder);
    printf("2) Ціла частина від ділення %d на %d дорівнює: %d\n", num1, num2, quotient);
    printf("3) Добуток чисел %d та %d дорівнює: %d\n", num1, num2, product);
    
    

    printf("\nРоботу завершено.");

    return 0;
    
}

#include <stdio.h>

int main() {
    int n, sum;

    printf("Введіть чотиризначне число: ");
    scanf("%d", &n);

    // Рахуємо суму цифр в один рядок
    sum = (n / 1000) + (n / 100 % 10) + (n / 10 % 10) + (n % 10);

    printf("Сума цифр: %d\n", sum);

    if (sum < 25) {
        printf("Так, менша за 25\n");
    } else {
        printf("Ні, не менша за 25\n");
    }

    return 0;
}
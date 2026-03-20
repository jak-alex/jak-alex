#include <stdio.h>

int main() {
    double a;
    int n;
    double total_product = 1.0;
    double current_sum = 0.0;

    printf("Введіть дійсне число a: ");
    scanf("%lf", &a);
    printf("Введіть натуральне число n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        current_sum += i;             
        total_product *= (a + current_sum); 
    }

    printf("\nРезультат обчислення: %.4f\n", total_product);

    return 0;
}
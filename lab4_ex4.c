#include <stdio.h>
#include <math.h>

int main() {
    double a = 1.0, b = 2.0, dx = 0.025;
    double x, y;

    printf("--------------------------\n");
    printf("|    x     |    y=f(x)   |\n");
    printf("--------------------------\n");

    // Цикл для табулювання
    for (x = a; x <= b + dx/2; x += dx) {
        // Перевірка на виключну ситуацію (логарифм від x <= 0)
        if (x <= 0) {
            printf("| %8.3f |  невизначено |\n", x);
        } else {
            // Рахуємо log2(x) через натуральний логарифм
            y = log(x) / log(2.0);
            printf("| %8.3f | %10.4f |\n", x, y);
        }
    }

    return 0;
}
#include <stdio.h>
#include <math.h>

int main() {
    // Оголошення змінних для катетів, гіпотенузи та периметра
    double a = 3.0;
    double b = 4.0;
    double c, p;

    // Обчислення гіпотенузи за теоремою Піфагора
    c = sqrt(pow(a, 2) + pow(b, 2));

    // Обчислення периметра
    p = a + b + c;

    // Результат
    printf("Вхідні дані: a = %.0f, b = %.0f\n", a, b);
    printf("Вихідні дані: c = %.0f, p = %.0f\n", c, p);

    return 0;
}





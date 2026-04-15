#include <stdio.h>
#include <math.h> 

// Прототип функції (оголошення) [cite: 50, 53]
double Leng(double x1, double y1, double x2, double y2);

int main() {
    // Змінні для координат точок A, B, C, D
    double xA, yA, xB, yB, xC, yC, xD, yD;

    printf("Введіть координати точки A (x y): ");
    scanf("%lf %lf", &xA, &yA);

    printf("Введіть координати точки B (x y): ");
    scanf("%lf %lf", &xB, &yB);

    printf("Введіть координати точки C (x y): ");
    scanf("%lf %lf", &xC, &yC);

    printf("Введіть координати точки D (x y): ");
    scanf("%lf %lf", &xD, &yD);

    // Виклик функції для кожного відрізка [cite: 35, 203]
    double lengthAB = Leng(xA, yA, xB, yB);
    double lengthBC = Leng(xB, yB, xC, yC);
    double lengthCD = Leng(xC, yC, xD, yD);

    // Виведення результатів
    printf("\nРезультати:\n");
    printf("Довжина AB: %.2f\n", lengthAB);
    printf("Довжина BC: %.2f\n", lengthBC);
    printf("Довжина CD: %.2f\n", lengthCD);

    return 0;
}

// Визначення (реалізація) функції Leng за формулою з завдання [cite: 34, 202]
double Leng(double x1, double y1, double x2, double y2) {
    // Формула: sqrt((x1-x2)^2 + (y1-y2)^2)
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
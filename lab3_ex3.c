#include <stdio.h>

int main() {
    int episode;

    printf("Введіть номер серії 1-го сезону (1-7): ");
    scanf("%d", &episode);

    printf("\n--- Інформація ---\n");

    switch (episode) {
        case 1:
            printf("Назва: Episode One\nДата прем'єри: 26 вересня 2010\n");
            break;
        case 2:
            printf("Назва: Episode Two\nДата прем'єри: 3 жовтня 2010\n");
            break;
        case 3:
            printf("Назва: Episode Three\nДата прем'єри: 10 жовтня 2010\n");
            break;
        case 4:
            printf("Назва: Episode Four\nДата прем'єри: 17 жовтня 2010\n");
            break;
        case 5:
            printf("Назва: Episode Five\nДата прем'єри: 24 жовтня 2010\n");
            break;
        case 6:
            printf("Назва: Episode Six\nДата прем'єри: 31 жовтня 2010\n");
            break;
        case 7:
            printf("Назва: Episode Seven\nДата прем'єри: 7 листопада 2010\n");
            break;
        default:
            printf("Помилка: у першому сезоні лише 7 серій!\n");
    }

    return 0;
}
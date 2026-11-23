#include <stdio.h>
#include <math.h>

int main() {
    int choice = -1;
    int m, n, s, k;
    double a, b, c;
    double t;
    double x1, y1, x2, y2, x3, y3;
    double res;
    double pi = 3.14159265;

    while (choice != 0) {
        printf("\n===== Меню =====\n");
        printf("Оберіть завдання: 1, 33, 40, 51, 54, 58, 62, 77, 101, 110\n");
        printf("0 - вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            /* Завдання 1: ділимість m на n націло */
            printf("Введіть два цiлих числа m та n: ");
            scanf("%d %d", &m, &n);
            if (n == 0) {
                printf("Завдання 1: помилка, дiлення на нуль\n");
            } else if (m % n == 0) {
                printf("Завдання 1: m дiлиться на n, частка = %d\n", m / n);
            } else {
                printf("Завдання 1: m на n нацiло не дiлиться\n");
            }
            break;

        case 33:
            /* Завдання 33: дiльником яких чисел a, b, c є k */
            printf("Введiть три цiлих числа a, b, c: ");
            scanf("%d %d %d", &m, &n, &s); /* використовуємо m, n, s як a, b, c */
            printf("Введiть k: ");
            scanf("%d", &k);

            if (k == 0) {
                printf("Завдання 33: k не може бути 0\n");
            } else {
                printf("Завдання 33: k = %d є дiльником: ", k);
                if (m % k == 0) printf("a ");
                if (n % k == 0) printf("b ");
                if (s % k == 0) printf("c ");
                printf("\n");
            }
            break;

        case 40:
            /* Завдання 40: пожежний датчик */
            printf("Введiть температуру t: ");
            scanf("%lf", &t);
            if (t > 60) {
                printf("Завдання 40: Пожежонебезпечна ситуацiя\n");
            } else {
                printf("Завдання 40: температура нормальна: %lf\n", t);
            }
            break;

        case 51:
            /* Завдання 51: парнiсть двох чисел */
            printf("Введiть два цiлих числа m та n: ");
            scanf("%d %d", &m, &n);
            if (m % 2 == 0 && n % 2 == 0) {
                printf("Завдання 51: обидва числа парнi\n");
            } else if (m % 2 != 0 && n % 2 != 0) {
                printf("Завдання 51: обидва числа непарнi\n");
            } else if (m % 2 == 0) {
                printf("Завдання 51: m парне, n непарне\n");
            } else {
                printf("Завдання 51: m непарне, n парне\n");
            }
            break;

        case 54:
            /* Завдання 54: чи прямокутний трикутник, якщо нi — кут C */
            printf("Введiть довжини сторiн a, b, c: ");
            scanf("%lf %lf %lf", &a, &b, &c);

            /* без перевiрок iснування, просто пiфагор */
            if (fabs(a * a + b * b - c * c) < 0.0001 ||
                fabs(a * a + c * c - b * b) < 0.0001 ||
                fabs(b * b + c * c - a * a) < 0.0001) {
                printf("Завдання 54: трикутник прямокутний\n");
            } else {
                /* вважаємо, що кут C проти сторони c */
                res = acos((a * a + b * b - c * c) / (2 * a * b)) * 180.0 / pi;
                printf("Завдання 54: трикутник не прямокутний, кут C = %.2lf градусiв\n", res);
            }
            break;

        case 58:
            /* Завдання 58: точки A, B, C на однiй прямiй, якщо нi — кут B */
            printf("Введiть координати A (x1 y1): ");
            scanf("%lf %lf", &x1, &y1);
            printf("Введiть координати B (x2 y2): ");
            scanf("%lf %lf", &x2, &y2);
            printf("Введiть координати C (x3 y3): ");
            scanf("%lf %lf", &x3, &y3);

            /* спрощена перевiрка: перевiримо площу через векторний добуток */
            res = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
            if (fabs(res) < 0.0001) {
                printf("Завдання 58: точки лежать на однiй прямiй\n");
            } else {
                /* обчислюємо кут B мiж BA i BC */
                double v1x = x1 - x2;
                double v1y = y1 - y2;
                double v2x = x3 - x2;
                double v2y = y3 - y2;
                double dot = v1x * v2x + v1y * v2y;
                double len1 = sqrt(v1x * v1x + v1y * v1y);
                double len2 = sqrt(v2x * v2x + v2y * v2y);
                double cosb = dot / (len1 * len2);
                res = acos(cosb) * 180.0 / pi;
                printf("Завдання 58: точки не на однiй прямiй, кут B = %.2lf градусiв\n", res);
            }
            break;

        case 62:
            /* Завдання 62: a^3 + b*x = 0 */
            printf("Введiть a i b: ");
            scanf("%lf %lf", &a, &b);
            if (b != 0) {
                res = -(a * a * a) / b;
                printf("Завдання 62: x = %.2lf\n", res);
            } else {
                /* спецвипадки не розбираємо, як простий варiант */
                printf("Завдання 62: немає розв'язкiв або їх безлiч\n");
            }
            break;

        case 77:
            /* Дуже спрощено: тільки повідомлення (без геометрії) */
            printf("Завдання 77 ще не реалiзовано (потрiбна геометрiя)\n");
            break;

        case 101:
            /* Дуже спрощено: тільки повідомлення */
            printf("Завдання 101 ще не реалiзовано (потрiбна геометрiя)\n");
            break;

        case 110:
            /* Завдання 110: максимум та мiнiмум трьох чисел */
            printf("Введiть три дiйсних числа a, b, c: ");
            scanf("%lf %lf %lf", &a, &b, &c);

            double max, min;
            max = a;
            min = a;
            if (b > max) max = b;
            if (c > max) max = c;
            if (b < min) min = b;
            if (c < min) min = c;

            printf("Завдання 110: максимум = %.2lf, мiнiмум = %.2lf\n", max, min);
            break;

        case 0:
            printf("Вихiд з програми\n");
            break;

        default:
            printf("Невiрний номер завдання\n");
        }
    }

    return 0;
}

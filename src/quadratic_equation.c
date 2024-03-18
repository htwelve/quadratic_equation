#include "quadratic_equation.h"

int solve_equation(double a, double b, double c, double *x1,
                   double *x2) {  // получить действительные ax^2 + bx + c = 0
  int flag = 0;
  if (!isnan(a) && !isnan(b) && !isnan(c) && x1 != NULL &&
      x2 != NULL) {  //предварительная проверка аргументов функции
    double discriminant = pow(b, 2) - (4 * a * c);
    double sqr_disk =
        sqrt(discriminant);  //заранее вычисляем корень из дискриминанта, чтобы
                             //сократить дублирование кода
    if ((a == 0 && b == 0) ||
        (b == 0 && ((c > 0 && a > 0) || (c < 0 && a < 0))) ||
        discriminant < 0) {  //случаи при которых решения не существуют, либо
                             //решения не определены
      flag = QUAD_NO_SOLUTIONS;
    } else if ((b == 0 && c == 0) ||
               (a == 0 && c == 0)) {  //случаи неполного уравнения
      *x1 = 0;
      *x2 = 0;
      flag = QUAD_ONE_SOLUTION;
    } else if (b == 0 && c < 0) {
      *x1 = sqrt(-c / a);
      *x2 = -sqrt(-c / a);
      flag = QUAD_TWO_SOLUTIONS;
    } else if (a == 0 && c != 0) {
      *x1 = (-c / b);
      *x2 = *x1;
      flag = QUAD_ONE_SOLUTION;
    } else if (discriminant >
               0) {  // решение через формулу корней для полного уравнения
      *x1 = (-b - sqr_disk) / (2 * a);
      *x2 = (-b + sqr_disk) / (2 * a);
      flag = QUAD_TWO_SOLUTIONS;
    } else if (discriminant == 0) {
      *x1 = (-b - sqr_disk) / (2 * a);
      *x2 = *x1;
      flag = QUAD_ONE_SOLUTION;
    }
  } else {
    flag = QUAD_ERROR;
  }
  return flag;
}
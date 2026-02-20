#include <iostream>
#include <cmath>
using namespace std;

// Метод Симпсона для численного интегрирования
double simpson_method(double (*f)(double), double a, double b, int n) {
 
    if (n % 2 == 1) {
        n += 1; 
    }

    // Вычисляем шаг
    double delta_x = (b - a) / n;

    // Вычисление значений функции в узловых точках
    double integral = f(a) + f(b);

  
    for (int i = 1; i < n; i += 2) {
        integral += 4 * f(a + i * delta_x);
    }
    for (int i = 2; i < n - 1; i += 2) {
        integral += 2 * f(a + i * delta_x);
    }

    integral *= delta_x / 3;
    return integral;
}


double func1(double x) {
    return (3 * x * x - 2 * x);
}

double func2(double x) {
    return (-x * x + 6 * x);
}

int main() {
    setlocale(LC_ALL, "rus");
    double a = 5;
    double b = 7;
    int n = 100000;   

    double result1 = simpson_method(func1, a, b, n);
    cout << "Численное значение интеграла: " << result1 << endl;


    double result2 = simpson_method(func2, a, b, n);
    cout << "Численное значение интеграла: " << result2 << endl;

    double result = result1 - result2;
    cout << result;

    return 0;
}
#include <iostream>
#include <string>
#include <Windows.h>

class Figure {
protected:
    int sides_count = 0;
    std::string name = "Фигура";

public:
    Figure() = default;
    virtual ~Figure() = default;

    virtual std::string get_name() const { return name; }
    virtual int get_sides_count() const { return sides_count; }
    virtual bool check() const { return sides_count == 0; }
    virtual void print_info() const {
        std::cout << get_name() << ":\n";
        std::cout << (check() ? "Правильная" : "Неправильная") << "\n";
        std::cout << "Количество сторон: " << get_sides_count() << "\n";
    }
};

class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(int a, int b, int c, int A, int B, int C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {
        name = "Треугольник";
        sides_count = 3;
    }

    std::string get_name() const override { return name; }

    bool check() const override {
        return (A + B + C) == 180;
    }

    void print_info() const override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90) {
        name = "Прямоугольный треугольник";
    }

    bool check() const override {
        return Triangle::check() && (C == 90);
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int ab, int c, int AB, int C)
        : Triangle(ab, ab, c, AB, AB, C) {
        name = "Равнобедренный треугольник";
    }

    bool check() const override {
        return Triangle::check() && (a == c) && (A == C);
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a)
        : Triangle(a, a, a, 60, 60, 60) {
        name = "Равносторонний треугольник";
    }

    bool check() const override {
        return Triangle::check() && (a == b && b == c) && (A == 60 && B == 60 && C == 60);
    }
};

class Quadrangle : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
        name = "Четырёхугольник";
        sides_count = 4;
    }

    std::string get_name() const override { return name; }

    bool check() const override {
        return (A + B + C + D) == 360;
    }

    void print_info() const override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};
class rectangle : public Quadrangle {
public:

    rectangle(int width, int height)
        : Quadrangle(width, height, width, height, 90, 90, 90, 90) {
        name = "Прямоугольник";
    }

    bool check() const override {

        return Quadrangle::check() &&
            (a == c && b == d) &&
            (A == 90 && B == 90 && C == 90 && D == 90);
    }
};

class Square : public rectangle {
public:
    Square(int a) : rectangle(a, a) {
        name = "Квадрат";
    }

    bool check() const override {
        return rectangle::check() && (a == b && b == c && c == d);
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrangle(a, b, a, b, A, B, A, B) {
        name = "Параллелограмм";
    }

    bool check() const override {
        return Quadrangle::check() &&
            (a == c && b == d) &&
            (A == C && B == D);
    }
};

class Rhomb : public Parallelogram {
public:
    Rhomb(int a, int A, int B)
        : Parallelogram(a, a, A, B) {
        name = "Ромб";
    }

    bool check() const override {
        return Parallelogram::check() && (a == b && b == c && c == d);
    }
};

int main() {
    SetConsoleOutputCP(1251);

    Figure figure;
    figure.print_info();

    Triangle triangle(10, 20, 30, 50, 60, 70);
    triangle.print_info();

    RightTriangle rightTriangle(10, 20, 30, 50, 40);
    rightTriangle.print_info();

    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    isoscelesTriangle.print_info();

    EquilateralTriangle equilateralTriangle(30);
    equilateralTriangle.print_info();

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    quadrangle.print_info();

    rectangle rec(10, 20);
    rec.print_info();

    Square square(20);
    square.print_info();

    Parallelogram parallelogram(20, 30, 30, 40);
    parallelogram.print_info();

    Rhomb rhomb(30, 30, 40);
    rhomb.print_info();

    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;
class IShape
{
public:
    virtual double CalculateArea() = 0;
    virtual double CalculatePerimeter() = 0;
};

class Circle : public IShape
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }

    double CalculateArea() override
    {
        return 3.14 * radius * radius;
    }

    double CalculatePerimeter() override
    {
        return 2 * 3.14 * radius;
    }
};

class Rectangle : public IShape
{
private:
    double width;
    double height;

public:
    Rectangle(double w, double h)
    {
        width = w;
        height = h;
    }

    double CalculateArea() override
    {
        return width * height;
    }

    double CalculatePerimeter() override
    {
        return 2 * (width + height);
    }
};

class Triangle : public IShape
{
private:
    double a;
    double b;
    double c;

public:
    Triangle(double sideA, double sideB, double sideC)
    {
        a = sideA;
        b = sideB;
        c = sideC;
    }

    double CalculateArea() override
    {
        double p = (a + b + c) / 2;

        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    double CalculatePerimeter() override
    {
        return a + b + c;
    }
};
int main()
{
    system("chcp 65001");
    Circle circle(5);
    Rectangle rectangle(4, 6);
    Triangle triangle(3, 4, 5);
    cout << "Коло" << endl;
    cout << "Площа: " << circle.CalculateArea() << endl;
    cout << "Периметр: " << circle.CalculatePerimeter() << endl;
    cout << endl;
    cout << "Прямокутник" << endl;
    cout << "Площа: " << rectangle.CalculateArea() << endl;
    cout << "Периметр: " << rectangle.CalculatePerimeter() << endl;
    cout << endl;
    cout << "Трикутник" << endl;
    cout << "Площа: " << triangle.CalculateArea() << endl;
    cout << "Периметр: " << triangle.CalculatePerimeter() << endl;
}
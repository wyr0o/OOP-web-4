#include <iostream>
#include <Windows.h>

class Shape
{
protected:
	int sides{};
	std::string name{};
public:
	int getSides(){return sides;}

	std::string getName() { return name; }

	Shape(int SetSides, std::string SetName) : sides{SetSides}, name {SetName}
	{}
};
class triangle : public Shape
{
public:
	triangle() : Shape{ 3, "Треугольник" }
	{}
};
class quadrangle : public Shape
{
public:
	quadrangle() : Shape{4, "Четырёхугольник"}
	{}
};

int main()
{
	SetConsoleOutputCP(1251);

	Shape shape(0, "фигура: ");
	triangle tri;
	quadrangle quad;

	std::cout << "Количество сторон" << std::endl;
	std::cout << shape.getName() << ": " << shape.getSides() << std::endl;
	std::cout << tri.getName() << ": " << tri.getSides() << std::endl;
	std::cout << quad.getName() << ": " << quad.getSides() << std::endl;



}
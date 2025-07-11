#include <iostream>
#include <Windows.h>


class triangle
{
protected:
	int TriLengthA{}, TriLengthB{}, TriLengthC{}, TriAngleA{}, TriAngleB{}, TriAngleC{};
	std::string name{};
public:

	virtual int getLengthA() const { return TriLengthA; }
	virtual int getLengthB()const { return TriLengthB; }
	virtual int getLengthC() const { return TriLengthC; }

	virtual int getTriAngleA()const { return TriAngleA; }
	virtual int getTriAngleB()const { return TriAngleB; }
	virtual int getTriAngleC()const { return TriAngleC; }

	virtual std::string getName() const { return "Треугольник"; }

	triangle(int aSet, int bSet, int cSet, int ASet, int BSet, int CSet) :
		TriLengthA{ aSet }, TriLengthB{ bSet }, TriLengthC{ cSet }, TriAngleA{ ASet }, TriAngleB{ BSet }, TriAngleC{ CSet }
	{
	}
	virtual ~triangle() = default;
};

class rightTriangle : public triangle
{
public:
	rightTriangle(int aSet, int bSet, int cSet, int ASet, int BSet) : triangle(aSet, bSet, cSet, ASet, BSet, 90)
	{
	}
	std::string getName() const override { return "Прямоугольный треугольник"; }
};

class isoscelesTriangle : public triangle
{
public:
	std::string getName() const override { return "Равнобедренный треугольник"; }
	isoscelesTriangle(int abSet, int cSet, int ABSet, int CSet) : triangle(abSet, abSet, cSet, ABSet, ABSet, CSet)
	{
	}
};
class equilateralTriangle : public triangle
{
public:
	std::string getName() const override { return "Равносторонний треугольник"; }
	equilateralTriangle(int abcSet) : triangle(abcSet, abcSet, abcSet, 60, 60, 60)
	{}
};

class quadrangle
{
protected:
	int QuadLengthA{}, QuadLengthB{}, QuadLengthC{}, QuadLengthD{}, QuadAngleA{}, QuadAngleB{}, QuadAngleC{}, QuadAngleD{};
	std::string name{};
public:
	virtual std::string getName() const { return "Четырёхугольник"; }
	quadrangle(int aSet, int bSet, int cSet, int dSet, int ASet, int BSet, int CSet, int DSet) :
		QuadLengthA{ aSet }, QuadLengthB{ bSet }, QuadLengthC{ cSet }, QuadLengthD{ dSet }, QuadAngleA{ ASet }, QuadAngleB{ BSet }, QuadAngleC{ CSet }, QuadAngleD{ DSet }
	{ }

	virtual int GetQuadSideLengthA()const { return QuadLengthA; }
	virtual int GetQuadSideLengthB() const { return QuadLengthB; }
	virtual int GetQuadSideLengthC() const { return QuadLengthC; }
	virtual int GetQuadSideLengthD()const { return QuadLengthD; }

	virtual int GetQuadAngleA()const { return QuadAngleA; }
	virtual int GetQuadAngleB()const { return QuadAngleB; }
	virtual int GetQuadAngleC()const { return QuadAngleC; }
	virtual int GetQuadAngleD() const { return QuadAngleD; }

	virtual ~quadrangle() = default;
};

class rectangle : public quadrangle
{
public:
	std::string getName() const override { return "Прямоугольник"; }
	rectangle(int aSet, int bSet, int cSet, int dSet, int ASet, int BSet, int CSet, int DSet) : quadrangle(aSet, bSet, cSet, dSet, 90, 90, 90, 90)
	{}

};


class square : public rectangle
{
public:
	std::string getName() const override { return "Квадрат"; }
	square(int abcdSet) : rectangle(abcdSet, abcdSet, abcdSet, abcdSet, 90, 90, 90, 90)
	{}
};

class parallelogram : public quadrangle {
public:
	std::string getName() const override { return "Параллелограмм"; }
	parallelogram(int a, int b, int angleA, int angleB)
		: quadrangle(a, b, a, b, angleA, angleB, angleA, angleB) {}
};


class rhomb : public quadrangle {
public:
	std::string getName() const override { return "Ромб"; }
	rhomb(int side, int angleA, int angleB) :
		quadrangle(side, side, side, side, angleA, angleB, angleA, angleB) {
	}
};


void print_info(const triangle* t)
{
	std::cout << t->getName() << std::endl;
	std::cout << "Стороны: a = " << t->getLengthA() << ", b = " << t->getLengthB() << ", c = " << t->getLengthC() << std::endl;
	std::cout << "Углы: A = " << t->getTriAngleA() << ", B = " << t->getTriAngleB() << ", C = " << t->getTriAngleC() << std::endl << std::endl;



}
void print_info(const quadrangle* q)
{
	std::cout << q->getName() << std::endl;
	std::cout << "Стороны: a = " << q->GetQuadSideLengthA() << ", b = " << q->GetQuadSideLengthB() << ", c = " << q->GetQuadSideLengthC() << ", d = " << q->GetQuadSideLengthD() << std::endl;
	std::cout << "Углы: a = " << q->GetQuadAngleA() << ", b = " << q->GetQuadAngleB() << ", c = " << q->GetQuadAngleC() << ", d = " << q->GetQuadAngleD() << std::endl << std::endl;
}

int main()
{
	SetConsoleOutputCP(1251);
	triangle t(10, 20, 30, 50, 60, 70);
	rightTriangle rt(10, 20, 30, 50, 60);
	isoscelesTriangle it(10, 20, 50, 60);
	equilateralTriangle et(30);

	quadrangle q(10, 20, 30, 40, 50, 60, 70, 80);
	rectangle r(10, 20, 10, 20, 90, 90, 90, 90);
	square s(20);
	parallelogram p(20, 30, 30, 40);
	rhomb rh(30, 30, 40);

	print_info(&t);
	print_info(&rt);
	print_info(&it);
	print_info(&et);

	print_info(&q);
	print_info(&r);
	print_info(&s);
	print_info(&p);
	print_info(&rh);
}

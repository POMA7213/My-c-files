#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a, b, c, p, S;
	cout << "введи стороны треугольника" << endl;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "c=";
	cin >> c;
	if ((c >= a + b) || (b >= a + c) || (a >= b + c))
		cout << "не треугольник";
	else
	{
		if ((a == b) && (a == c))
			cout << "равносторонний" << endl;
		else
		{
			if ((a == b) || (a == c) || (b == c))
				cout << "равнлбедренный" << endl;
			else
				cout << "разносторонний" << endl;
		}
		cout<<endl;
		p = (a + b + c) / 2;
		cout << "периметр: " << 2 * p << endl;
		S = sqrt(p * (p - a) * (p - b) * (p - c));
		cout << "площадь: " << S << endl;
		cout << endl;
		cout << "сторона a:" << endl;
		cout << "высота: " << 2 * S / a << endl;
		cout << "медиана: " << sqrt(2 * b * b + 2 * c * c - a * a) / 2 << endl;
		cout << "биссектриса: " << sqrt(c * b - (a * a * b * c / ((b + c) * (b + c)))) << endl;
		cout << endl;
		cout << "сторона b:" << endl;
		cout << "высота: " << 2 * S / b << endl;
		cout << "медиана: " << sqrt(2 * a * a + 2 * c * c - b * b) / 2 << endl;
		cout << "биссектриса: " << sqrt(c * a - (b * a * b * c / ((a + c) * (a + c)))) << endl;
		cout << endl;
		cout << "сторона c:" << endl;
		cout << "высота: " << 2 * S / c << endl;
		cout << "медиана: " << sqrt(2 * b * b + 2 * a * a - c * c) / 2 << endl;
		cout << "биссектриса: " << sqrt(a * b - (c * a * b * c / ((b + a) * (b + a)))) << endl;
		cout << endl;
		if ((a * a > b * b + c * c) || (b * b > a * a + c * c) || (c * c > a * a + b * b))
			cout << "тупоугольный" << endl;
		else
		{
			if ((a * a == b * b + c * c) || (b * b == a * a + c * c) || (c * c == a * a + b * b))
				cout << "прямоугольный" << endl;
			else
				cout << "остроугольный" << endl;
		}
		cout << endl;
		cout << "радиус вписанной окружности: " << S / p << endl;
		cout << "радиус описанной окружности: " << a * b * c / (4 * S) << endl;
		return 0;
	}
}
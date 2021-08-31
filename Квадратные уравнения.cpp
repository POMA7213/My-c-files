#include <iostream>
#include <cmath>
#include <string>
//a!=0
using namespace std;
int main()
{
	double a, b, c, x1, x2;
	string st, y;
	cout << "введи квадратное уравнение вида ax^2+bx+c=0" << endl;
	cin >> st;
	if (st[0] == '-' && st[1] == 'x')
		a = -1;
	else
	{
		if (st[0] == 'x')
			a = 1;
		else
			a = stof(st.substr(0, st.find('x')));
	}
	st.erase(0, st.find('x') + 3);
	cout << "a=" << a << endl;
	if (st[0] == '=')
	{
		b = 0;
		c = 0;
		cout << "b=0\nc=0\nединственный корень:x=0";
		return 0;
	}
	else
	{
		if (st.find('x') == string::npos)
		{
			b = 0;
			cout << "b=0" << endl;
			if (st[0] == '+')
				st.erase(0, 1);
			c = stof(st.substr(0, st.find('=')));
			cout << "c=" << c << endl;
		}
		else
		{
			if (st[0] == '+')
				st.erase(0, 1);
			if (st[0] == '-' && st[1] == 'x')
				b = -1;
			else
			{
				if (st[0] == 'x')
					b = 1;
				else
					b = stof(st.substr(0, st.find('x')));
			}
			st.erase(0, st.find('x') + 1);
			cout << "b=" << b << endl;
			if (st[0] == '=')
			{
				c = 0;
				cout << "c=0" << endl;
			}
			else
			{
				if (st[0] == '+')
					st.erase(0, 1);
				c = stof(st.substr(0, st.find('=')));
				cout << "c=" << c << endl;
			}
		}
	}
	if (b * b - 4 * a * c < 0)
	{
		if (b == 0)
		{
			if (a == c)
				cout << "корни:\nx1=i\nx2=-i";
			else
			{
				cout << "корни:" << endl;
				cout << "x1=" << sqrt(a * c) / a << "i" << endl;
				cout << "x2=" << (-1) * sqrt(a * c) / a << "i";
			}
		}
		else
		{
			cout << "корни:" << endl;
			if (4 * a * c - b * b == 4 * a * a)
				cout << "x1=" << ((-1) * b) / (2 * a) << "+i\nx2=" << ((-1) * b) / (2 * a) << "-i";
			else
			{
				cout << "x1=" << ((-1) * b) / (2 * a) << "+" << sqrt(4 * a * c - b * b) / (2 * a) << "i" << endl;
				cout << "x2=" << ((-1) * b) / (2 * a) << "-" << sqrt(4 * a * c - b * b) / (2 * a) << "i" << endl;
			}
		}
	}
	else
	{
		if (b * b - 4 * a * c == 0)
		{
			cout << "единственный корень:";
			cout << "x=" << b * (-1) / (2 * a);
		}
		else
		{
			cout << "корни:" << endl;
			cout << "x1=" << (b * (-1) + sqrt(b * b - 4 * a * c)) / (2 * a) << endl;
			cout << "x2=" << (b * (-1) - sqrt(b * b - 4 * a * c)) / (2 * a);
		}
	}
	return 0;
}
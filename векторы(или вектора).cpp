#include <iostream>
using namespace std;
int main()
{
	double x1, x2, y1, y2, z1, z2;
	cout<<"x1=";
	cin >> x1;
	cout<<"x2=";
	cin >> x2;
	cout<<"y1=";
	cin >> y1;
	cout<<"y2=";
	cin >> y2;
	cout<<"z1=";
	cin >> z1;
	cout<<"z2=";
	cin >> z2;
	cout << "Первый вектор:" << endl;
	cout << " x=" << x1 << " y=" << y1 << " z=" << z1 << endl;
	cout << "Второй вектор:" << endl;
	cout << " x=" << x2 << " y=" << y2 << " z=" << z2 << endl;
	cout << "Сумма векторов:" << endl;
	cout << " x=" << x1 + x2 << " y=" << y1 + y2 << " z=" << z1 + z2 << endl;
	cout << "Разность векторов:" << endl;
	cout << " x=" << x1 - x2 << " y=" << y1 - y2 << " z=" << z1 - z2<<endl;
	cout << "Скалярное произведение:" << endl;
	cout << x1 * x2 + y1 * y2 + z1 * z2 << endl;
	cout << "Векторное произведение:" << endl;
	cout << " x=" << y1 * z2 - y2 * z1 << " y=" << x2 * z1 - x1 * z2 << " z=" << x1 * y2 - x2 * y1 << endl;
	return 0;
}
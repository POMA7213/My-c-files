#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main()
{
	string st;
	double s = 0, Sr, p = 1, Sr2, s2 = 0, Sr3, s3 = 0, Sr4, i = 1, a;
	cout << "введи числа" << endl;
	getline(cin, st);
	while (st.find(' ') != string::npos)
	{
		a = stof(st.substr(0, st.find(' ')));
		s += a;
		s2 = s2 + a * a;
		s3 = s3 + 1 / a;
		p *= a;
		st.erase(0, st.find(' ') + 1);
		i++;
	}
	s += stof(st);
	p *= stof(st);
	s2 = s2 + stof(st) * stof(st);
	s3 = s3 + 1 / stof(st);
	Sr = s / i;
	Sr2 = pow(p, 1 / i);
	Sr3 = sqrt(s2 / i);
	Sr4 = i / s3;
	cout << "среднее квадратическое:" << Sr3 << endl;
	cout << "среднее арифметическое:" << Sr << endl;
	cout << "среднее геометрическое:" << Sr2 << endl;
	cout << "среднее гармоническое:" << Sr4 << endl;
	return 0;
}
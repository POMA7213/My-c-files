#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string st, z;
	double p, k, t;
	int n, n2, i;
	cout << "введи многочлен через x" << endl;
	cin >> st;
	st = st + "+";
	cout << "введи необходимое число" << endl;
	cin >> t;
	cout << "результат разложения данного многочлена " << endl;
	if (st[0] == '-')
	{
		st.erase(0, 1);
		n = stoll(st.substr(st.find('^') + 1, st.find_first_of("+-")));
		st = "-" + st;
	}
	else
		n = stoll(st.substr(st.find('^') + 1, st.find_first_of("+-")));
	vector<double> v(n + 1);
	vector<double> v2(n + 1);
	while (st.find('^') != string::npos)
	{
		if (st[0] == '+')
			st.erase(0, 1);
		if (st[0] == 'x')
			p = 1;
		else if (st[0] == '-' && st[1] == 'x')
			p = -1;
		else
			p = stof(st.substr(0, st.find('x')));
		st.erase(0, st.find('^') + 1);
		n2 = stoll(st.substr(0, st.find_first_of("+-")));
		st.erase(0, st.find_first_of("+-"));
		v[n2] = p;
	}
	if (st.find('x') != string::npos)
	{
		if (st[0] == '+')
			st.erase(0, 1);
		if (st[0] == 'x')
			p = 1;
		else if (st[0] == '-' && st[1] == 'x')
			p = -1;
		else
			p = stof(st.substr(0, st.find('x')));
		v[1] = p;
		st.erase(0, 1);
		st.erase(0, st.find_first_of("+-"));
	}
	if (st != "+")
	{
		if (st[0] == '+')
			st.erase(0, 1);
		p = stof(st.substr(0, st.find('+')));
		v[0] = p;
	}
	reverse(v.begin(), v.end());
	v2[0] = v[0];
	k = v2[0];
	for (i = 1; i <= n; i++)
	{
		k *= t;
		k += v[i];
		v2[i] = k;
	}
	if (t > 0)
		cout << "(x-" << t << ")(";
	else if (t == 0)
		cout << "x(";
	else
		cout << "(x+" << t * (-1) << ")(";
	for (int i = 0; i < n - 2; i++)
	{
		if (v2[i] == 0)
			continue;
		if (v2[i] > 0 && i == 0)
		{
			if (v[i] == 1)
				cout << "x^" << n - 1;
			else
				cout << v2[i] << "x^" << n - 1;
		}
		else if (v2[i] == 1)
			cout << "+x^" << n - 1 - i;
		else if (v2[i] == -1)
			cout << "-x^" << n - 1 - i;
		else if (v2[i] < 0)
			cout << v2[i] << "x^" << n - 1 - i;
		else
			cout << "+" << v2[i] << "x^" << n - 1 - i;
	}
	if (v2[n - 2] != 0)
	{
		if (n == 2 && v2[n - 2] > 0)
		{
			if (v2[n - 2] == 1)
				cout << "x";
			else
				cout << v2[n - 2] << "x";
		}
		else if (v2[n - 2] == 1)
			cout << "+x";
		else if (v2[n - 2] == -1)
			cout << "-x";
		else if (v2[n - 2] > 0)
			cout << "+" << v2[n - 2] << "x";
		else
			cout << v2[n - 2] << "x";
	}
	if (v2[n - 1] != 0)
	{
		if (v2[n - 1] > 0)
			cout << "+" << v2[n - 1];
		else
			cout << v2[n - 1];
	}
	cout << ")";
	if (v2[n] != 0)
	{
		if (v2[n] > 0)
			cout << "+" << v2[n];
		else
			cout << v2[n];
	}
	return 0;
}
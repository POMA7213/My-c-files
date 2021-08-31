#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string clear(string St)
{
	while (St.find("0x") != string::npos)
		St.erase(St.find("0x"), 1);
	while (St.find(".x") != string::npos)
		St.erase(St.find(".x"), 1);
	while (St[St.length() - 1] == '0' || St[St.length() - 1] == '.')
		St.erase(St.length() - 1, 1);
	return St;
}
vector<double> mnoch(string st)
{
	int n, n2;
	double p;
	st = st + "+";
	if (st.find('^') == string::npos)
	{
		if (st.find('x') == string::npos)
		{
			vector<double> v(1);
			v[0] = stoll(st);
			return v;
		}
		else
		{
			vector<double> v(2);
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
			if (st != "+")
			{
				if (st[0] == '+')
					st.erase(0, 1);
				p = stof(st.substr(0, st.find('+')));
				v[0] = p;
			}
			return v;
		}
	}
	if (st[0] == '-')
	{
		st.erase(0, 1);
		n = stoll(st.substr(st.find('^') + 1, st.find_first_of("+-")));
		st = "-" + st;
	}
	else
		n = stoll(st.substr(st.find('^') + 1, st.find_first_of("+-")));
	vector<double> v(n + 1);
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
	return v;
}
string mnosh(vector<double> v2)
{
	string s = "";
	while (v2.size()>0 && v2[0] == 0)
		v2.erase(v2.begin());
	if (v2.size() == 0)
		return s;
	if (v2.size() == 2)
	{
		if (v2[0] == 1)
			s += "x";
		else if (v2[0] == -1)
			s += "-x";
		else
			s += to_string(v2[0]) + "x";
		if (v2[1] != 0)
		{
			if (v2[1] > 0)
				s += "+" + to_string(v2[1]);
			else
				s += to_string(v2[1]);
		}
		return clear(s);
	}
	if (v2.size() == 1)
	{
		s = to_string(v2[0]);
		return clear(s);
	}
	for (int i = 0; i < v2.size() - 2; i++)
	{
		if (v2[i] == 0)
			continue;
		if (v2[i] > 0 && i == 0)
		{
			if (v2[i] == 1)
				s = s + "x^" + to_string(v2.size() - 1);
			else
				s = s + to_string(v2[i]) + "x^" + to_string(v2.size() - 1);
		}
		else if (v2[i] == 1)
			s = s + "+x^" + to_string(v2.size() - 1 - i);
		else if (v2[i] == -1)
			s = s + "-x^" + to_string(v2.size() - 1 - i);
		else if (v2[i] < 0)
			s = s + to_string(v2[i]) + "x^" + to_string(v2.size() - 1 - i);
		else
			s = s + "+" + to_string(v2[i]) + "x^" + to_string(v2.size() - 1 - i);
	}
	if (v2[v2.size() - 2] != 0)
	{
		if (v2[v2.size() - 2] == 1)
			s = s + "+x";
		else if (v2[v2.size() - 2] == -1)
			s = s + "-x";
		else if (v2[v2.size() - 2] > 0)
			s = s + "+" + to_string(v2[v2.size() - 2]) + "x";
		else
			s = s + to_string(v2[v2.size() - 2]) + "x";
	}
	if (v2[v2.size() - 1] != 0)
	{
		if (v2[v2.size() - 1] > 0)
			s = s + "+" + to_string(v2[v2.size() - 1]);
		else
			s = s + to_string(v2[v2.size() - 1]);
	}
	return clear(s);
}
int main()
{
	cout << "Введите две строки и операцию:\n1- сложение\n2- вычитание\n3- умножение\n4- деление \n(деление может выполняться не в порядке следования многочленов)\n";
	string s1, s2;
	int k, m, M, i;
	double ch = 0;
	cout << "Введите многочлены для действий\n";
	cin >> s1;
	cin >> s2;
	cout << "Введите операцию:";
	cin >> k;
	vector<double> v1 = mnoch(s1);
	vector<double> v2 = mnoch(s2);
	vector<double> v3;
	switch (k)
	{
	case 1:
	{
		if (v2.size() > v1.size())
			v1.swap(v2);
		for (i = 0; i < v2.size(); i++)
			v3.push_back(v1[i] + v2[i]);
		for (; i < v1.size(); i++)
			v3.push_back(v1[i]);
		reverse(v3.begin(), v3.end());
		cout << mnosh(v3);
		break;
	}
	case 2:
	{
		if (v1.size() >= v2.size())
		{
			M = v1.size();
			m = v2.size();
		}
		else
		{
			M = v2.size();
			m = v1.size();
		}
		for (i = 0; i < m; i++)
			v3.push_back(v1[i] - v2[i]);
		for (; i < M; i++)
			if (v1.size() > v2.size())
				v3.push_back(v1[i]);
			else
				v3.push_back(v2[i] * (-1));
		reverse(v3.begin(), v3.end());
		cout << mnosh(v3);
		break;
	}
	case 3:
	{
		for (i = 0; i < v1.size() + v2.size() - 1; i++)
		{
			for (int j = 0; j <= i && j < v1.size(); j++)
				if (i - j <= v2.size() - 1)
					ch += v1[j] * v2[i - j];
			v3.push_back(ch);
			ch = 0;
		}
		reverse(v3.begin(), v3.end());
		cout << mnosh(v3);
		break;
	}
	case 4:
	{
		double ko;
		if (v2.size() > v1.size())
			v1.swap(v2);
		reverse(v1.begin(), v1.end());
		reverse(v2.begin(), v2.end());
		while (v1.size() >= v2.size())
		{
			ko = v1[0] / v2[0];
			v3.push_back(ko);
			for (i = 0; i < v2.size(); i++)
				v1[i] -= v2[i] * ko;
			v1.erase(v1.begin());
		}
		cout << mnosh(v3) << endl;
		if (mnosh(v1) != "")
			cout << "Остаток: " << mnosh(v1);
		break;
	}
	}
	return 0;
}
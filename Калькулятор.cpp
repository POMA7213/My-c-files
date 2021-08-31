#include <iostream>
#include <string>
#include <cmath>
// +, -, *, /, (), ^.
using namespace std;
string stepen(string a)
{
	double b, c;
	if (a.find('^') != string::npos)
	{
		b = stof(a.substr(0, a.find('^')));
		a.erase(0, a.find('^') + 1);
		while (a.find('^') != string::npos)
		{
			b = pow(b, stof(a.substr(0, a.find('^'))));
			a.erase(0, a.find('^') + 1);
		}
		a = to_string(pow(b, stof(a)));
		return a;
	}
	else
		return a;
}
string proizvedenie(string ch)
{
	int j;
	double m = 1;
	string mn;
	if ((ch.find('*') != string::npos) || (ch.find('/') != string::npos))
	{
		ch = "*" + ch;
		for (j = 1; j < ch.length(); j++)
		{
			if ((ch[j] == '*') || (ch[j] == '/'))
			{
				mn = ch.substr(1, j - 1);
				if (ch[0] == '*')
					m *= stof(stepen(mn));
				if (ch[0] == '/')
					m /= stof(stepen(mn));
				ch.erase(0, j);
				j = 0;
			}
		}
		if (ch[0] == '*')
		{
			ch.erase(0, 1);
			m *= stof(stepen(ch));
		}
		if (ch[0] == '/')
		{
			ch.erase(0, 1);
			m /= stof(stepen(ch));
		}
		ch = to_string(m);
		return ch;
	}
	else
		return stepen(ch);
}
string chislo(string st)
{
	int i;
	double sum = 0;
	string Ch, z;
	if (st[st.length() - 1] == '-' || st[st.length() - 1] == '+')
		st.erase(st.length() - 1, 1);
	if ((st[0] != '+') && (st[0] != '-'))
		st = "+" + st;
	for (i = 2; i < st.length(); i++)
	{
		if ((st[i] == '+') || (st[i] == '-'))
		{
			if ((st[i] == '-') && (st[i - 1] == '*' || st[i - 1] == '/' || st[i - 1] == '^'))
				continue;
			Ch = st.substr(1, i - 1);
			if (st[0] == '-')
				sum -= stof(proizvedenie(Ch));
			if (st[0] == '+')
				sum += stof(proizvedenie(Ch));
			st.erase(0, i);
			i = 1;
		}
	}
	z = st.substr(0, 1);
	st.erase(0, 1);
	st = proizvedenie(st);
	st = z + st;
	if (st[0] == '-')
	{
		st.erase(0, 1);
		sum -= stof(st);
	}
	if (st[0] == '+')
	{
		st.erase(0, 1);
		sum += stof(st);
	}
	st = to_string(sum);
	return st;
}
int main()
{
	string St, St2;
	int x, i;
	cout << "введи пример" << endl;
	cin >> St;
	for (i = 1; i < St.length() - 1; i++)
	{
		if ((St[i] == '(') && (St[i - 1] != '+') && (St[i - 1] != '-') && (St[i - 1] != '*') && (St[i - 1] != '/') && (St[i - 1] != '(') && (St[i - 1] != '^'))
			St.insert(i, "*");
		if ((St[i] == ')') && (St[i + 1] != '+') && (St[i + 1] != '-') && (St[i + 1] != '*') && (St[i + 1] != '/') && (St[i + 1] != ')') && (St[i + 1] != '^'))
			St.insert(i + 1, "*");
	}
	if (St[St.length() - 1] == '-' || St[St.length() - 1] == '+')
		St.erase(St.length() - 1, 1);
	if ((St[0] != '+') && (St[0] != '-'))
		St = "+" + St;
	while (St.find('(') != string::npos)
	{
		St2 = St.substr(0, St.find(')'));
		x = St2.find_last_of("(");
		St2.erase(0, x + 1);
		St2 = chislo(St2);
		St.replace(x, St.find(')') - x + 1, St2);
	}
	St = chislo(St);
	while (St[St.length() - 1] == '.' || St[St.length() - 1] == '0')
		St.erase(St.length() - 1, 1);
	cout << "результат (возможно округленный):" << St;
	return 0;
}
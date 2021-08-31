#include <iostream>
#include <string>
using namespace std;
int main()
{
	string st;
	int k, l, z = 0, k2, l2, lx = 0, kx = 0, i, p = 1, m = 1,q;
	cout << "введи периодическую дробь вида челая часть.число(периодическая часть)" << endl;
	getline(cin, st);
	q=stoi(st.substr(0,st.find(".")));
	st.erase(0, st.find(".")+1);
	if (st.find('(') != string::npos)
	{
		while (st[0] == '0')
		{
			st.erase(0, 1);
			z++;
		}
		if (st[0] == '(')
		{
			st.erase(0, 1);
			k = st.length() - 1;
			while (st[0] == '0')
				st.erase(0, 1);
			l = stoll(st.substr(0, st.find(')')));
			for (i = 0; i < k; i++)
				p *= 10;
			p--;
			for (i = 0; i < z; i++)
				p *= 10;
		}
		else
		{
			k = stoll(st.substr(0, st.find('(')));
			k2 = k;
			st.erase(0, st.find('(') + 1);
			while (st[0] == '0')
			{
				lx++;
				st.erase(0, 1);
			}
			l = stoll(st.substr(0, st.find(')')));
			l2 = l;
			while (k != 0)
			{
				k /= 10;
				kx++;
			}
			while (l != 0)
			{
				l /= 10;
				lx++;
			}
			k = k2;
			for (i = 0; i < lx; i++)
				k2 *= 10;
			l = k2 + l2 - k;
			for (i = 0; i < lx + kx + z; i++)
				p *= 10;
			for (i = 0; i < kx + z; i++)
				m *= 10;
			p -= m;
		}
	}
	else
	{
		l = stoll(st);
		for (i = 0; i < st.length(); i++)
			p *= 10;
	}
	for (i = 2; i <= l; i++)
	{
		if ((l % i == 0) && (p % i == 0))
		{
			p /= i;
			l /= i;
			i--;
		}
	}
	cout << l+q*p<< "/" << p;
	return 0;
}
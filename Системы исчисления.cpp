#include <iostream>
#include <string>
//до 36-ичного кода
using namespace std;
int main()
{
	string a, b;
	int i, j = 1, s = 0, t, x, f;
	cout << "..ичность кода" << endl;
	cin >> t;
	cout << "введи код" << endl;
	cin >> a;
	cout << "введи новую ..ичность кода" << endl;
	cin >> x;
	while (a != "")
	{
		b = a.substr(a.length() - 1, 1);
		if (b.find_first_of("0123456789") == string::npos)
		{
			for (i = 65; i < 91; i++)
			{
				if (a[a.length() - 1] == char(i))
				{
					i -= 55;
					break;
				}
			}
		}
		else
			i = stoll(b);
		i *= j;
		j *= t;
		s += i;
		a.erase(a.length() - 1, 1);
	}
	cout << "Ответ:";
	while (s >= x)
	{
		f = s % x;
		if (f > 9)
			a = char(55 + f) + a;
		else
			a = to_string(f) + a;
		s /= x;
	}
	if (s > 9)
		a = char(55 + s) + a;
	else
		a = to_string(s) + a;
	cout << a;
	return 0;
}
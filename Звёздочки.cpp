#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a = "", a2 = "**";
	int n, i;
	cout << "высота башни:";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		a += "*";
		a2.insert(1, " ");
	}
	a2.erase(1, 2);
	for (i = 0; i < n; i++)
	{
		if (i == 0 || i == n - 1)
			cout << a << endl;
		else
		{
			if (i == n / 2 - 1 && n % 2 == 0)
			{
				if (n % 4 == 0)
					cout << endl
						 << endl;
				else
					cout << a2 << endl
						 << a2 << endl;
				n--;
			}
			else
			{
				if (i % 2 == 1)
					cout << endl;
				else
					cout << a2 << endl;
			}
		}
	}
	return 0;
}
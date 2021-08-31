#include <iostream>
//до миллиарда
using namespace std;
int main()
{
	int i, ch, ch2;
	cout << "введи число" << endl;
	cin >> ch;
	ch2 = ch;
	cout << "множители: ";
	for (i = 2; i <= ch; i++)
	{
		if (ch % i == 0)
		{
			cout << i << " ";
			ch /= i;
			i--;
		}
	}
	cout << endl;
	cout << "делится на:";
	for (i = 1; i <= ch2; i++)
		if (ch2 % i == 0)
			cout << i << " ";
	return 0;
}
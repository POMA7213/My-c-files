#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int i, j, k = 0;
	cout << "2 ";
	for (i = 2; i < 1000000; i++)
	{
		for (j = 2; j < (int)sqrt(i)+1; j++)
		{
			if (i % j == 0)
				break;
			if (j ==(int)sqrt(i))
			{
				cout << i << " ";
				k++;
			}
			if (k == 8)
			{
				cout << endl;
				k = 0;
			}
		}
	}
	return 0;
}
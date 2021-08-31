#include <iostream>
using namespace std;
int main()
{
	int s = 0, i, i2, k, j, p = 1;
	for (i = 1; i < 3000000; i++)
	{
		i2 = i;
		while (i2 != 0)
		{
			k = i2 % 10;
			if (k == 0)
				s++;
			else
			{
				for (j = 1; j <= k; j++)
					p *= j;
				s += p;
				p = 1;
			}
			i2 /= 10;
		}
		if (i == s)
			cout << s << endl;
		s = 0;
	}
	return 0;
}
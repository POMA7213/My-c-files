#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double k, x, y;
	cin >> k;
	for (x = 2; x <= 1000000; x += 2)
	{
		y = sqrt(2 * x + k * k) * k;
		if (int(y) == y && ((x / k) != int(x / k) || k == 1)&&(int(k)%2==1))
			cout << y << " " << x << " " << sqrt(x * x + y * y) << endl;
	}
	return 0;
}
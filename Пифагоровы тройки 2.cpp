#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double k, x, y;
	cin >> k;
	for (x = 1; x <= 1000000; x += 2)
	{
		y = sqrt(x + k * k) * 2 * k;
		if (int(y) == y && ((x / k) != int(x / k) || k == 1))
			cout << y << " " << x << " " << sqrt(x * x + y * y) << endl;
	}
	return 0;
}
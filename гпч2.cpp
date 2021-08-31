#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
	vector<int> v;
	int i, j, k = 0;
	v.push_back(2);
	v.push_back(3);
	for (i = 4; i < 10000000; i++)
	{
		for (j = 0; v[j] < (int)sqrt(i) + 1; j++)
		{
			if (i % v[j] == 0)
				break;
			if (v[j + 1] >= (int)sqrt(i) + 1)
				v.push_back(i);
		}
	}
	for (j = 0; j < v.size(); j++)
	{
		cout << v[j] << " ";
		k++;
		if (k == 7)
		{
			cout << endl;
			k = 0;
		}
	}
	return 0;
}
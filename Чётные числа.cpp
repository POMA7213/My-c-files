#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

bool prov(int x)
{
	return (x % 2 == 0);
}

int main()
{
	srand(time(NULL));
	vector<int> v(10);
	int i, k = 0;
	for (i = 0; i < 10; i++)
	{
		v[i] = rand() % 101 - 50;
		cout << v[i] << " ";
	}
	cout << endl;

	while (k < v.size())
	{
		k = find_if(v.begin() + k, v.end(), prov) - v.begin();
		if (k != v.size())
			v.erase(v.begin() + k);
	}
	for (i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;
int main()
{
	int k, p, n;
	vector<int> v;
	cout << "Введи степень корня"<<endl;
	cin>>p;
	cout<<"Введи число"<<endl;
	cin >> n;
	for (int i = 1; i < n + 1; i++)
		if (n % i == 0)
			v.push_back(i);
	for (int i = 0; i < v.size() / 2 + 1; i++)
		swap(v[i], v[v.size() - i - 1]);
	for (int i = 0; i < v.size(); i++)
		if (int(pow(v[i], 1./p)) == pow(v[i], 1./p))
		{
			k = v[i];
			break;
		}
	cout<<"Ответ:";
	if (k == n)
		cout << pow(k, 1./p);
	else if (k == 1)
		cout << "(" << n<<")^(1/"<<p<<")";
	else
		cout << pow(k, 1./p) << "*(" << n / k<<")^(1/"<<p<<")";
	return 0;
}
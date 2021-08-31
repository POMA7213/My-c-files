#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int n, k, ch;
	srand(time(NULL));
	cout << "От:";
	cin >> n;
	cout << "До:";
	cin >> k;
	ch = random()%(k - n + 1) + n;
	cout << "Ответ:" << ch;
	return 0;
}

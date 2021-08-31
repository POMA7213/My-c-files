#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	srand(time(NULL));
	int x, b;
	cout << "угадай число от 1 до 99" << endl;
	cin >> x;
	b = random() % 99 + 1;
	if (x == b)
		cout << "В точку!";
	else
		cout << "Неправильно:" << b;
	return 0;
}
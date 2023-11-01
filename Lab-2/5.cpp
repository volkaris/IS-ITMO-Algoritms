#include <iostream>
#include <vector>
using namespace std;

int main()
{
	 int x[1001]; int y[1001];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >>x[i] >>y[i]; //x-id y-баллы
	}
	for (int j = 0; j < n-1; j++)
		for (int i = 0; i < n-1; i++)
			if (y[i]<y[i + 1] or (y[i] == y[i + 1] and x[i]>x[i + 1]))
			{
				swap(x[i], x[i + 1]);
				swap(y[i], y[i + 1]);
			}
	for (int i = 0; i < n; i++)
		cout << x[i] << ' ' << y[i] << endl;
}
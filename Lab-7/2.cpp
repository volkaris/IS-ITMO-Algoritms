#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>

using namespace std;



int main()
{
	int s, n;

	int dynamic_weight[10001] = {};
	cin >> s >> n;
	vector<shared_ptr<int>> weight;
	weight.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int g;
		cin >> g;
		weight[i] = make_shared<int>(g);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = s; j >= *(weight[i]); j--)
		{
			dynamic_weight[j] = max(dynamic_weight[j], dynamic_weight[j - *(weight[i])] + *(weight[i]));
		}
	}

	cout << dynamic_weight[s] << endl;
}

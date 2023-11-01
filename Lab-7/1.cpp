#include <iostream>
#include <vector>

using namespace std;

int main()
{
	const int N = 2e3 + 1;

	int n;
	cin >> n;
	int a[N];
	int len_of_all_sequences[N]; 
	vector<int> sequence[N]; 
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		len_of_all_sequences[i] = 1;
		sequence[i].emplace_back(a[i]);

		for (int j = 1; j < i; j++)
		{
			if (a[j] < a[i] and len_of_all_sequences[i] < len_of_all_sequences[j] + 1) //удов. условиям возрастания 
			//и динамика не такая же как была
			{
				len_of_all_sequences[i] = len_of_all_sequences[j] + 1;
				sequence[i] = sequence[j];
				sequence[i].emplace_back(a[i]);
			}
		}
	}

	int actuall_len = 0, index = 0;
	for (int i = 1; i <= n; i++)
	{
		if (actuall_len < len_of_all_sequences[i])
		{
			actuall_len = len_of_all_sequences[i];	//получаем длину,и запоминаем индекс,где последовательность заканчивается
			index = i;
		}
	}

	cout << actuall_len<<"\n";

	for (int i = 0; i < sequence[index].size(); i++)
	{
		cout << sequence[index][i] << " ";
	}
}

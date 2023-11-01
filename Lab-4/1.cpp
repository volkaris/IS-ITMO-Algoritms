
#include <iostream>
using namespace std;


int main()
{
	uint64_t countno = 0;
	uint64_t n;
	cin >> n;
	n++;
	auto arr = new int[n];

	for (uint64_t i = 1; i <n; i++)
	{
		cin >> arr[i];

	}
	for (uint64_t i = 1; i <n; i++)
	{
		if (2 * i <= n-1) {

			if (arr[i] > arr[2 * i])
			{
				countno++;
				break;
			}
		}
		if(2*i+1<=n-1){
			if(arr[i]>arr[2*i+1])
			{
				countno++;
				break;
			}
		}
	}
	if (countno==0)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	delete[]arr;
}




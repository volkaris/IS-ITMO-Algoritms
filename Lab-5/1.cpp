#include <iostream>


using namespace std;


int binary_tree[200000][3];
int height = 0;

int tree_search(int current_level, int height_on_current_level)
{
	height = max(height_on_current_level, height);
	if (binary_tree[current_level][1] > 0)
	{
		tree_search(binary_tree[current_level][1], height_on_current_level + 1);
	}
	if (binary_tree[current_level][2] > 0)
	{
		tree_search(binary_tree[current_level][2], height_on_current_level + 1);
	}
	return height;
}

int main()
{
	int n;

	cin >> n;

	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	if (n == 1)
	{
		cout << 1;
		return 0;
		
	}
	for (int i = 0; i < n; i++)
	{
		cin >> binary_tree[i + 1][0] >> binary_tree[i + 1][1] >> binary_tree[i + 1][2];
	}
	cout << tree_search(1, 1);
}
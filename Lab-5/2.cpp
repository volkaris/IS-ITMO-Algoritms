#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
	int data=0;
	int left_child = 0;
	int right_child = 0;
};

bool is_it_tree(vector<Node>& nodes, int LevelOfTree, int min, int max)
{
	if (nodes[LevelOfTree].left_child != -1 and nodes[LevelOfTree].data <= nodes[nodes[LevelOfTree].left_child].data)
	{
		return false;
	}
	if (nodes[LevelOfTree].right_child != -1 and nodes[LevelOfTree].data >= nodes[nodes[LevelOfTree].right_child].data)
	{
		return false;
	}
	if (nodes[LevelOfTree].data <= min or nodes[LevelOfTree].data >= max)
	{
		return false;
	}
	if (nodes[LevelOfTree].left_child != -1)
	{
		return is_it_tree(nodes, nodes[LevelOfTree].left_child, min, nodes[LevelOfTree].data);
	}
	if (nodes[LevelOfTree].right_child != -1)
	{
		return is_it_tree(nodes, nodes[LevelOfTree].right_child, nodes[LevelOfTree].data, max);
	}
	return true;
}

int main()
{
	int n = 0;
	cin >> n;
	vector<Node> nodes;
	for (int i = 0; i < n; i++)
	{
		int data = 0, left_child = 0, right_child = 0;
		cin >> data >> left_child >> right_child;
		Node* node = new Node;
		node->data = data;
		node->left_child = left_child - 1; //можно ли как то изменить,чтобы не было -1 и в проверке было не -1,а 0?
		node->right_child = right_child - 1;
		nodes.push_back(*node);
		delete node;
	}

	if (n == 0 or n == 1)
	{
		cout << "YES";
		return 0;
	}
	bool answer = is_it_tree(nodes, 0, INT_MIN, INT_MAX);

	if (answer == false)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}
}

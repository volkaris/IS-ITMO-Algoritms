#include <vector>
#include <iostream>
//#include <queue>
using namespace std;

template <typename NodeType>
class node {
public:
	NodeType pair;
	node* next;

};

template <typename NodeType>
class MyQueue {

	node<NodeType>* head;
	node<NodeType>* tail;
public:
	MyQueue() : head(nullptr), tail(nullptr) {
	}
	void push(NodeType pair) {
		node<NodeType>* n = new node<NodeType>;
		n->pair = pair;
		n->next = nullptr;
		if (this->head == nullptr) {
			this->head = n;
			this->tail = n;
		} else {
			this->tail->next = n;
			this->tail = n;
		}
	}
	bool empty() const {
		return this->head == nullptr;
	}

	void pop() {
		node<NodeType>* n = this->head;
		this->head = this->head->next;
	}
	NodeType& front() {
		return this->head->pair;
	}

};


void bfs(vector<vector<char>>& graph, vector<vector<bool>>& visited, int x, int y) {
	visited[x][y] = true;
	MyQueue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		auto new_x = q.front().first;
		auto new_y = q.front().second;
		q.pop();

		if (!visited[new_x - 1][new_y] and graph[new_x - 1][new_y] == '.') {
			visited[new_x - 1][new_y] = true;
			q.push(make_pair(new_x - 1, new_y));
		}

		if (!visited[new_x][new_y - 1] and graph[new_x][new_y - 1] == '.') {
			visited[new_x][new_y - 1] = true;
			q.push(make_pair(new_x, new_y - 1));
		}

		if (!visited[new_x + 1][new_y] and graph[new_x + 1][new_y] == '.') {
			visited[new_x + 1][new_y] = true;
			q.push(make_pair(new_x + 1, new_y));
		}

		if (!visited[new_x][new_y + 1] and graph[new_x][new_y + 1] == '.') {
			visited[new_x][new_y + 1] = true;
			q.push(make_pair(new_x, new_y + 1));
		}
	}
}


using namespace std;
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	size_t amount_of_rooms = 0;
	size_t n, m;
	cin >> n >> m;

	vector<vector<char>> graph(n, vector<char>(m));
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			char ch;
			cin >> ch;
			graph[i][j] = ch;
		}
	}

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			if (graph[i][j] == '.' and !(visited[i][j])) {
				bfs(graph, visited, i, j);
				amount_of_rooms++;
			}
		}
	}

	cout << amount_of_rooms;
}

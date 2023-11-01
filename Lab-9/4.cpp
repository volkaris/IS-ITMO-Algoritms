#include <vector>
#include <iostream>
#include <limits>
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


int shortest_path(std::vector<std::vector<int>>& graph, int start, int end) {
	std::vector<int> path(graph.size(), std::numeric_limits<int>::min());
	MyQueue<int> q;
	q.push(start);
	path[start] = 0;
	while (!q.empty()) {
		auto curr = q.front();
		q.pop();
		for (int j : graph[curr]) {
			if (path[j] == std::numeric_limits<int>::min()) {
				path[j] = path[curr] + 1;
				q.push(j);
			}
		}
	}
	if (path[end] == std::numeric_limits<int>::min()) {
		return -1;
	}


	return path[end];
}



int main() {
	std::vector<std::vector<int>> graph;
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	size_t n, m;
	std::cin >> n >> m;

	graph.resize(n + 1);

	for (size_t i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	size_t start, end;
	std::cin >> start >> end;
	std::cout << shortest_path(graph, start, end);
}

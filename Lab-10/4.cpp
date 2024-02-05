#include <iostream>
#include <vector>


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
        }
        else {
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



void topologicalSort(vector<vector<size_t>>& graph, vector<size_t>& input_degree, vector<size_t>& result_) {
	const size_t n = graph.size();
    MyQueue<size_t> queue;
    vector<size_t> result;
    size_t idx = 1;

    for (size_t i = 1; i < n; i++) {
        if (input_degree[i] == 0) {
            queue.push(i);
        }
    }


    while (!queue.empty()) {
        size_t curr = queue.front();
        result_[curr] = idx;
        ++idx;
        queue.pop();
        result.push_back(curr);

        for (size_t neighbor : graph[curr]) {
            input_degree[neighbor]--;
            if (input_degree[neighbor] == 0) {
                queue.push(neighbor);
            }
        }
    }


}

int main() {
    size_t n, m;
    cin >> n >> m;


    vector<vector<size_t>> graph(n + 1);
    vector<size_t> input_degree(n + 1, 0);
    vector<size_t> result(n+1, 0);

    for (size_t i = 0; i < m; ++i) {
        size_t n, m;
        cin >> n >> m;
        graph[n].push_back(m);
        input_degree[m]++;
    }
    topologicalSort(graph, input_degree, result);

   for (size_t i=1;i<result.size();++i) {
       cout << result[i] << " ";
   }

}

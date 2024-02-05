#include <string>
#include <iostream>

using namespace std;
class node {
public:
	std::pair<char, int> pair;
	node* next;

};

class MyQueue {

	node* head;
	node* tail;
public:
	MyQueue(): head(nullptr),tail(nullptr) {}
	void add(pair<char, int> pair) {
		node* n = new node;
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
	bool Empty() const {
		return this->head == nullptr;
	}

	void Pop() {
		node* n = this->head;
		this->head = this->head->next;
	}
	pair<char, int>& front() {
		return this->head->pair;
	}

};


void Parce(string str, MyQueue* q) {
	char current_char = '\0';
	int current_num = 0;
	for (char c : str) {
		if (isalpha(c)) {
			if (current_char != '\0' && current_num != 0) {
				q->add({current_char, current_num});
			}
			current_char = c;
			current_num = 0;
		} else if (isdigit(c)) {
			current_num = current_num * 10 + (c - '0');
		}
	}

	if (current_char != '\0' && current_num != 0) {
		q->add({current_char, current_num});
	}
}


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	MyQueue* q1 = new MyQueue();

	MyQueue* q2 = new MyQueue();

	size_t n;
	cin >> n;

	size_t m;
	cin >> m;

	size_t k;
	cin >> k;

	string str1;
	cin >> str1;

	string str2;
	cin >> str2;

	int difference = 0;
	Parce(str1, q1);
	Parce(str2, q2);

	while (!q1->Empty() and !q2->Empty()) {
		const auto& first_char = q1->front().first;
		const auto& second_char = q2->front().first;
		if (first_char != second_char) {
			auto& first = q1->front().second;
			auto& second = q2->front().second;
			if (first > second) {
				difference += second;
				first -= second;
				q2->Pop();
			} else if (first < second) {
				difference += first;
				second -= first;
				q1->Pop();
			} else if (first == second) {
				difference += first;
				q1->Pop();
				q2->Pop();
			}
		} else {
			auto& first = q1->front().second;
			auto& second = q2->front().second;
			if (first > second) {
				first -= second;
				q2->Pop();
			} else if (first < second) {
				second -= first;
				q1->Pop();
			} else if (first == second) {
				q1->Pop();
				q2->Pop();
			}
		}
	}
	if (difference >= k) {
		cout << "No";
	} else {
		cout << "Yes";
	}
	delete q1;
	delete q2;
}

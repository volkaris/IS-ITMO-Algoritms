#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_set>
using namespace std;

struct TupleComparator {
	bool operator()(const std::tuple<size_t, size_t, size_t>& a, const std::tuple<size_t, size_t, size_t>& b) const {
		return std::get<2>(a) > std::get<2>(b);
	}
};


struct TupleHash {
	std::size_t operator()(const std::tuple<std::size_t, std::size_t, std::size_t>& t) const {
		auto [x, y, z] = t;
		return std::hash<std::size_t>()(x) ^ std::hash<std::size_t>()(y) ^ std::hash<std::size_t>()(z);
	}
};

class UnionFind {
public:
	UnionFind(size_t n) : parent(n), rank(n, 0) {
		for (size_t i = 0; i < n; ++i) {
			parent[i] = i;
		}
	}

	size_t find(size_t x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	bool unite(size_t x, size_t y) {
		size_t px = find(x);
		size_t py = find(y);
		if (px == py) {
			return false; // x and y are already in the same set
		}
		if (rank[px] < rank[py]) {
			parent[px] = py;
		}
		else if (rank[px] > rank[py]) {
			parent[py] = px;
		}
		else {
			parent[py] = px;
			++rank[px];
		}
		return true;
	}

private:
	vector<size_t> parent;
	vector<size_t> rank;
};

size_t Kruskal(tuple<size_t, size_t, size_t>& start_edge, size_t V, priority_queue<tuple<size_t, size_t, size_t>,
	vector<tuple<size_t, size_t, size_t>>, TupleComparator> edges) {




	//	vector<tuple<size_t, size_t, size_t>> MST;

	//	MST.reserve(V - 1);
	UnionFind uf(V + 1);

	size_t cost_Of_mst = 0;
	//	MST.emplace_back(start_edge);

	size_t idx = 0;

	const size_t start1 = get<0>(start_edge);
	const size_t end1 = get<1>(start_edge);
	const size_t weight1 = get<2>(start_edge);

	uf.unite(start1, end1);

	cost_Of_mst += weight1;
	++idx;


	while (idx != V - 1) {

		const size_t start = get<0>(edges.top());
		const size_t end = get<1>(edges.top());
		const size_t weight = get<2>(edges.top());

		if (uf.unite(start, end)) {
			//		MST.emplace_back(edges.top());
			cost_Of_mst += weight;
			++idx;

		}

		edges.pop();
	}

	return cost_Of_mst;
}

auto normal_Kruskal(size_t V, priority_queue<tuple<size_t, size_t, size_t>,
	vector<tuple<size_t, size_t, size_t>>, TupleComparator> edges, std::unordered_set<std::tuple<std::size_t, std::size_t, std::size_t>, TupleHash>& MST) {


	UnionFind uf(V + 1);

	size_t cost_Of_mst = 0;


	size_t idx = 0;




	while (idx != V - 1) {

		const size_t start = get<0>(edges.top());
		const size_t end = get<1>(edges.top());
		const size_t weight = get<2>(edges.top());

		if (uf.unite(start, end)) {
			MST.emplace(edges.top());
			cost_Of_mst += weight;
			++idx;

		}

		edges.pop();
	}

	return cost_Of_mst;
}



int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	size_t V, E;
	cin >> V >> E;

	priority_queue<tuple<size_t, size_t, size_t>, vector<tuple<size_t, size_t, size_t>>, TupleComparator> edges;
	vector<tuple<size_t, size_t, size_t>> order(E);

	std::unordered_set<std::tuple<std::size_t, std::size_t, std::size_t>, TupleHash> MST;
	MST.reserve(V - 1);

	for (size_t i = 0; i < E; i++) {
		size_t u, v, w;
		cin >> u >> v >> w;
		edges.push(make_tuple(u, v, w));
		order[i] = { u,v,w };

	}

	auto first_answer = normal_Kruskal(V, edges, MST);
	size_t second_answer = numeric_limits<size_t>::max();
	for (size_t i = 0; i < E; ++i) {

		if (!MST.contains(order[i])) {
			{
				second_answer = min(Kruskal(order[i], V, edges), second_answer);
			}
		}
	}
	cout << first_answer << " " << second_answer;
}

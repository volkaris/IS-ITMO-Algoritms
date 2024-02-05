#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

struct TupleComparator {
	bool operator()(const std::tuple<size_t, size_t, size_t>& a, const std::tuple<size_t, size_t, size_t>& b) const {
		return std::get<2>(a) > std::get<2>(b); 
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

size_t Kruskal() {
	size_t V, E;
	cin >> V >> E;
	size_t cost_Of_mst = 0;
	priority_queue<tuple<size_t, size_t, size_t>, vector<tuple<size_t, size_t, size_t>>, TupleComparator> edges;
	vector<tuple<size_t, size_t, size_t>> MST;
	MST.reserve(V - 1);
	UnionFind uf(V + 1);

	for (size_t i = 0; i < E; i++) {
		size_t u, v, w;
		cin >> u >> v >> w;
		edges.push(make_tuple(u, v, w));
	}

	size_t idx = 0;
	while (!edges.empty()) {
		const size_t start = get<0>(edges.top());
		const size_t end = get<1>(edges.top());
		const size_t weight = get<2>(edges.top());

		if (uf.unite(start, end)) {
			MST.emplace_back(edges.top());
			cost_Of_mst += weight;
			++idx;
			if (idx == V - 1) {
				break;
			}
		}

		edges.pop();
	}

	return cost_Of_mst;
}

int main() {
	cout << Kruskal();
}

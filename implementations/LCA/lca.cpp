// Least Common Ancestor implementation using sparse table
// Made by @AksLolCoding

#include <bits/stdc++.h>
using namespace std;

struct LCA {
	using Tree = const vector<vector<int>>;
	int n, k, root;
	vector<int> first, depth, parent, tour;
	vector<vector<int>> st;

	void dfs(Tree& adj, int node, int par) {
		parent[node] = par;
		if (par != -1) depth[node] = depth[par] + 1;
		first[node] = tour.size();
		tour.push_back(node);
		for (int i: adj[node]) {
			if (i != par) {
				dfs(adj, i, node);
				tour.push_back(node);
			}
		}
	}

	int min_depth(int x, int y) {
		return depth[x] < depth[y] ? x : y;
	}

	LCA(Tree& adj, int root = 0): n(adj.size()), k(__bit_width(2*n-1)), root(root), first(n), depth(n), parent(n), st(k) {
		tour.reserve(2*n-1);
		dfs(adj, root, -1);

		st[0] = tour;
		int pow = 2;
		for (int i = 1; i < k; i++) {
			st[i].resize(2*n - pow);
			for (int j = 0; j < 2*n - pow; j++) {
				st[i][j] = min_depth(st[i-1][j], st[i-1][j + pow/2]);
			}
			pow <<= 1;
		}
	}

	int lca(int a, int b) {
		int l = first[a], r = first[b];
		if (l > r) swap(l, r);
		int i = __bit_width(r - l + 1) - 1;
		return min_depth(st[i][l], st[i][r - (1 << i) + 1]);
	}

	bool is_ancestor(int a, int b) {
		return lca(a, b) == a;
	}

	int dist(int a, int b) {
		return depth[a] + depth[b] - 2*depth[lca(a, b)];
	}
};

int main() {
}
#include <bits/stdc++.h>
using namespace std;

/*
Flexible sparse tree implementation by @AksLolCoding
T: type of data
F: operator on T
def: default value (identity of F)

Complexity:
Space: O(N log N)
Construction: O(N log N) time
query: O(log N) time
idempotent_query: O(1) time
*/
template<class T, class F = plus<T>, T def = T{}> struct SparseTree{
	int n, k;
	F f;
	vector<vector<T>> tree;

	SparseTree(const vector<T> &v): n(v.size()), k(__bit_width(n)), tree(k) {
		if (n == 0) return;
		tree[0] = v;
		int pow = 2;
		for (int i = 1; i < k; i++){
			tree[i].reserve(n - pow);
			for (int j = 0; j + pow < n; j++){
				tree[i].push_back(f(tree[i - 1][j], tree[i - 1][j + (pow >> 1)]));
			}
		}
	}

	T query(int l, int r){
		T res = def;
		for (int i = k; i >= 0; i--) {
			if ((1 << i) <= r - l + 1) {
				res = f(res, tree[i][l]);
				l += 1 << i;
			}
		}
		return res;
	}

	T idempotent_query(int l, int r){
		int i = __bit_width(r - l + 1) - 1;
		int res = f(tree[i][l], tree[i][r - (1 << i) + 1]);
		return res;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
}
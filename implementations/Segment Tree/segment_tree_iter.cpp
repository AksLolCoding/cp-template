#include <bits/stdc++.h>
using namespace std;

// Iterative Segment Tree implementation
// Made by @AksLolCoding
template <class T> struct SegmentTree {
	static const T DEF = 0;
	int len;
	vector<T> t;
	SegmentTree(int len, T val = DEF): len(len), t(len * 2, val) {
		for (int idx = len - 1; idx >= 0; idx--) update(idx);
	}
	SegmentTree(vector<T> const& v): SegmentTree(v.size()) {
		for (int idx = t.size() - 1; idx > 0; idx--) {
			if (idx >= len) t[idx] = v[idx - len];
			else update(idx);
		}
	}
	SegmentTree() {}
	T join(T a, T b) {
		return a + b;
	}
	void update(int idx) {
		t[idx] = join(t[idx << 1], t[idx << 1 | 1]);
	}
	void set(int idx, T val) { 
		for (t[idx += len] = val; idx >>= 1; ) update(idx);
	}
	void update(int idx, T val) { 
		for (t[idx += len] = join(t[idx + len], val); idx >>= 1; ) update(idx);
	}
	T query(int l, int r) { // queries [l, r]
		T resl = DEF, resr = DEF;
		for (l += len, r += len + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) resl = join(resl, t[l++]);
			if (r & 1) resr = join(t[--r], resr);
		}
		return join(resl, resr);
	}
	T get(int idx) {
		return t[idx + len];
	}
};
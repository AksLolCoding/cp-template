#include <bits/stdc++.h>
using namespace std;

/*
Binary Indexed Tree / Fenwick Tree by @AksLolCoding
*/
template <class T> struct BIT {
    const T def{};
    vector<T> bit;
    int n;
    F f;

    // Customize this if you need a different operator
    T join(const T& a, const T& b) {
        return a + b;
    }

    // Customize this if you need a different operator
    T sub(const T& a, const T& b) {
        return a - b;
    }

    BIT(int n): n(n), bit(n, def) {}
    BIT(vector<T> const &a) : n(a.size()), bit(n) {
        for (int i = 0; i < a.size(); i++) {
            int j = i | (i + 1);
            bit[i] = join(bit[i], a[i]);
            if (j < n) bit[j] = join(bit[j], bit[i]);
        }
    }

    T query(int r) {
        T ret = def;
        for (; r >= 0; r = (r & (r + 1)) - 1) { ret = join(ret, bit[r]); }
        return ret;
	}

	T query(int l, int r) { return sub(sum(r), sum(l - 1)); }

    void update(int idx, const T& delta) {
        for (; idx < n; idx = idx | (idx + 1)) { bit[idx] = join(bit[idx], delta); }
    }
};

int main() {}
//An implementation of the Segment Tree
//Made by @AksLolCoding

#include <bits/stdc++.h>
using namespace std;

/*
    Segment tree with O(log n) queries and updates
    Template arguments:
    T: type of value to be stored
    F: functor with overload F(T, T)

    Usage:
    ```
    SegmentTree<int> tree;
    SegmentTree<int, 1, multiplies<int>> tree;
    SegmentTree<unsigned int, 0, bit_xor<unsigned int>> tree;
    ```
*/
template<class T, class F = plus<T>>
class SegmentTree {
    private:
        const T DEF {};
        vector<T> t;
        int n;
        F f;

        void build(const vector<T>& a, int v, int tl, int tr) {
            if (tl > tr) return;
            if (tl == tr) t[v] = a[tl];
            else {
                int tm = (tl + tr)/2;
                build(a, 2*v, tl, tm);
                build(a, 2*v+1, tm + 1, tr);
                t[v] = join(t[2*v], t[2*v+1]);
            }
        }
        void build(int v, int tl, int tr) {
            if (tl >= tr) return;
            else {
                int tm = (tl + tr)/2;
                build(2*v, tl, tm);
                build(2*v+1, tm + 1, tr);
                t[v] = join(t[2*v], t[2*v+1]);
            }
        }
        T query(int v, int tl, int tr, int l, int r) {
            if (l > r) return DEF;
            if (tl == l && tr == r) return t[v];
            int tm = (tl + tr)/2;
            T resl = query(v*2, tl, tm, l, min(r, tm));
            T resr = query(v*2+1, tm+1, tr, max(l, tm+1), r);
            return join(resl, resr);
        }
        void update(int v, int tl, int tr, int pos, const T& val, bool set) {
            if (tl > tr) return;
            if (tl == tr) {
                if (set) t[v] = val;
                else t[v] = join(t[v], val);
            }
            else {
                int tm = (tl + tr) / 2;
                if (pos <= tm) update(v*2, tl, tm, pos, val);
                else update(v*2+1, tm+1, tr, pos, val);
                t[v] = join(t[v*2], t[v*2+1]);
            }
        }
        T join(const T& a, const T& b) {
            return f(a, b);
        }
    public:
        SegmentTree(int n): n(n), t(2*n, DEF) { build(1, 0, n - 1); }
        SegmentTree(const vector<T>& a): SegmentTree(a.size()) { build(a, 1, 0, n - 1); }
        int size() { return n; }
        void build(const vector<T>& a) { build(a, 1, 0, n - 1); }
        void build() { build(1, 0, n - 1); }
        T query(int l, int r) { return query(1, 0, n - 1, l, r); }
        T query(int r) { return query(1, 0, n - 1, 0, r); }
        T get(int idx) {
            return t[n - 1 + idx];
        }
        void update(int pos, const T& val) { update(1, 0, n - 1, pos, val, false); }
        void set(int pos, const T& val) { update(1, 0, n - 1, pos, val, true); }
};

int main() {}
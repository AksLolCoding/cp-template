//An implementation of a Segment Tree
//Made by @AksLolCoding

#include <vector>
#include <functional>
#include <bits/stdc++.h>

/*
    Segment tree with O(log n) queries and updates
    Template arguments:
    T: type of value to be stored
    def: default value (should be identity of F)
    F: functor with overload F(T, T)

    Usage:
    ```
    SegmentTree<int> tree;
    SegmentTree<int, 1, std::multiplies<int>> tree;
    SegmentTree<unsigned long long, 0, bit_and<unsigned long long>> tree;
    ```
*/
template<class T, T def, class F = std::plus<T>> class SegmentTree{
    private:
        std::vector<T> t;
        int n;
        F f;

        void build(const std::vector<T>& a, int v, int tl, int tr){
            if (tl > tr) return;
            if (tl == tr) t[v] = a[tl];
            else{
                int tm = (tl + tr)/2;
                build(a, 2*v, tl, tm);
                build(a, 2*v+1, tm + 1, tr);
                t[v] = merge(t[2*v], t[2*v+1]);
            }
        }
        void build(int v, int tl, int tr){
            if (tl > tr) return;
            if (tl == tr) t[v] = def;
            else{
                int tm = (tl + tr)/2;
                build(2*v, tl, tm);
                build(2*v+1, tm + 1, tr);
                t[v] = merge(t[2*v], t[2*v+1]);
            }
        }
        T query(int v, int tl, int tr, int l, int r){
            if (l > r) return def;
            if (tl == l && tr == r) return t[v];
            int tm = (tl + tr)/2;
            return merge(query(v*2, tl, tm, l, std::min(r, tm)), query(v*2+1, tm+1, tr, std::max(l, tm+1), r));
        }
        void update(int v, int tl, int tr, int pos, T val) {
            if (tl > tr) return;
            if (tl == tr) t[v] = val;
            else{
                int tm = (tl + tr) / 2;
                if (pos <= tm) update(v*2, tl, tm, pos, val);
                else update(v*2+1, tm+1, tr, pos, val);
                t[v] = merge(t[v*2], t[v*2+1]);
            }
        }
        T merge(const T& a, const T& b){
            return f(a, b);
        }
    public:
        SegmentTree(int n): n(n), t(4*n + 1) { build(1, 0, n - 1); }
        SegmentTree(const std::vector<T>& a): SegmentTree(a.size()) { build(a, 1, 0, n - 1); }
        void build(const std::vector<T>& a){ build(a, 1, 0, n - 1); }
        void build(){ build(1, 0, n - 1); }
        T query(int l, int r){ return query(1, 0, n - 1, l, r); }
        T query(int r){ return query(1, 0, n - 1, 0, r); }
        void update(int pos, T val){ update(1, 0, n - 1, pos, val); }
};
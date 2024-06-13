//An implementation of the Disjoint-Set-Union/Union-Find class
//Made by @AksLolCoding

#include <bits/stdc++.h>
using namespace std;

template<int n>
class DSU {
    private:
        int e[n]; int c;
    public:
        DSU(): c(n) { memset(e, -1, sizeof(e)); }
        int parent(int x) { return (e[x] < 0 ? x : e[x] = parent(e[x])); }
        bool connected(int x, int y) { return parent(x) == parent(y); }
        bool connected() { return c == 1; }
        int size(int x) { return -e[parent(x)]; }
        int size() { return n; }
        int components() { return c; }
        bool link(int x, int y) {
            x = parent(x), y = parent(y);
            if (x == y) return false;
            if (e[x] > e[y]) swap(x, y);
            e[x] += e[y];
            e[y] = x;
            c--;
            return true;
        }
};

int main() {
}
#include <bits/stdc++.h>
using namespace std;

inline int lastbit(int x) {
    return x & (-x);
}

template <class T, int... ArgsT>
struct BIT {
    T val = 0;
    void update(T val) {
        this->val += val;
    }
    T query() {
        return val;
    }
};

/*
Binary Indexed Tree / Fenwick Tree by @AksLolCoding
Usage:
```
BIT<type, dimensions>
BIT<int, 1, 2, 3> bit;
BIT<char, 17, 4> bit;

bit.update(coords, value)
bit.update(0, 1, 1, 17)
bit.update(16, 3, 'c')

bit.query(l1, r1, l2, r2 ...)
bit.query(0, 0, 0, 1, 0, 2)
bit.query(0, 16, 0, 2)
```
*/
template <class T, int N, int... Ns>
struct BIT<T, N, Ns...> {
    BIT<Ns...> bit[N + 1];

    template<typename... Args>
    void update(int pos, Args... args) {
        for (; pos <= N; bit[pos].update(args...), pos += lastbit(pos));
    }

    template<typename... Args>
    int query(int l, int r, Args... args) {
        T ans = 0;
        for (; r >= 1; ans += bit[r].query(args...), r -= lastbit(r));
        for (--l; l >= 1; ans -= bit[l].query(args...), l -= lastbit(l));
        return ans;
    }
};

int main(){
}
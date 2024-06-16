// Some OVER-ENGINEERED overloaded generic binary search code
// Made by @AksLolCoding
#include <bits/stdc++.h>
using namespace std;

enum searchType_t: bool {
    firstTrue = 0,
    lastTrue = 1
};

template<class T, class F>
typename enable_if<is_integral<T>::value>::type
binSearch(T l, T r, F fn, bool searchType = firstTrue) {
    while (l < r) {
        T m = (l + r + searchType) / 2;
        if (fn(m) ^ searchType) r = m - searchType;
        else l = m + !searchType;
    }
    return l;
}

template<class T, class F>
typename enable_if<is_floating_point<T>::value>::type
binSearch(T l, T r, F fn, bool searchType = firstTrue) {
    const T delta = 1e-5;
    while (abs(r - l) > delta) {
        T m = (l + r) / 2;
        if (fn(m) ^ searchType) r = m;
        else l = m;
    }
    return l;
}

int main() {
}
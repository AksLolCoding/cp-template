#include <bits/stdc++.h>
using namespace std;

// Trie implementation using vector by @AksLolCoding
template<int S>
struct VecTrie {
    vector<array<int, S>> vec;
    vector<bool> leaf;
    vector<int> count;

    VecTrie() { addNode() }

    // implement this function to convert a letter to an index in [0, S)
    static int key(const T& t) {
    }

    int addNode() {
        vec.emplace_back();
        leaf.push_back(false);
        count.push_back(0);
        vec.back().fill(-1);
        return vec.size() - 1;
    }

    template<class T>
    void insert(T* word, int wlen) {
        int v = 0;
        for (int i = 0; i < wlen; i++) {
            int idx = key(*t);
            count[v]++;
            if (vec[v][idx] == -1) vec[v][idx] = addNode();
            v = vec[v][idx];
            word++;
        }
        leaf[v] = true;
        count[v]++;
    }

    int getNode(T* word, int wlen) {
        int v = 0;
        for (int i = 0; i < wlen; i++) {
            int idx = key(*t);
            if (vec[v][idx] == -1) return -1;
            v = vec[v][idx];
            word++;
        }
        return v;
    }

    bool contains(T* word, int wlen) {
        int idx = contains(word, wlen);
        return (idx != -1 && leaf[idx]);
    }

    int maxPrefix(T* word, int wlen) {
        int v = 0, i = 0;
        for (; i < wlen; i++) {
            int idx = key(*t);
            if (vec[v][idx] == -1) break;
            v = vec[v][idx];
            word++;
        }
        return i;
    }
};

int main() {
}
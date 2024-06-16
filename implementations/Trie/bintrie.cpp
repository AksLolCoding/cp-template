#include <bits/stdc++.h>
using namespace std;

// Binary trie implementation by @AksLolCoding
struct BinTrie {
    static const int sz = 2;
    bool leaf = 0;
    int childcnt = 0;
    BinTrie* children[sz] = { nullptr };
    
    BinTrie() {
        for (int i = 0; i < sz; i++) this->children[i] = nullptr;
        this->leaf = 0;
        this->childcnt = 0;
    }

    ~BinTrie() {
        for (int i = 0; i < sz; i++) {
            if (this->children[i] != nullptr) delete this->children[i];
        }
    }
    
    template<size_t T>
    void insert(const bitset<T> &item) {
        BinTrie *temp = this;
        int isize = item.size();

        for (int i = 0; i < isize; i++) {
            bool idx = item[i];
            if (temp->children[idx] == nullptr) {
                temp->children[idx] = new BinTrie();
                temp->childcnt++;
            }
            temp = temp->children[idx];
        }
        temp->leaf = 1;
    }

    template<size_t T>
    BinTrie *getNode(const bitset<T> &item, int prefix = T) {
        BinTrie *temp = this;
        
        for (int i = 0; i < prefix; i++) {
            bool idx = item[i];
            if (temp->children[idx] == nullptr) return nullptr;
            temp = temp->children[idx];
        }
        return temp;
    }
    
    template<size_t T>
    bool contains(const bitset<T> &item) {
        BinTrie *temp = getNode(item);
        return (temp != nullptr && temp->leaf == 1);
    }

    template<size_t T>
    int longestPrefix(const bitset<T> &item) {
        BinTrie *temp = this;
        int isize = item.size();
        int prefix = 0;

        for (int i = 0; i < isize; i++) {
            bool idx = item[i];
            if (temp->children[idx] == nullptr) return -1;
            if (temp->childcnt > 1) prefix = i;
            temp = temp->children[idx];
        }
        return prefix;
    }

    template<size_t T>
    bool remove(const bitset<T> &item) {
        int prefix = longestPrefix(item);
        if (prefix == -1) return 0;

        BinTrie *temp = getNode(item, prefix);
        bool idx = item[prefix];
        delete temp->children[idx];
        temp->children[idx] = nullptr;
        temp->childcnt--;
        return 1;
    }
};

int main() {
}
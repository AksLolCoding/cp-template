#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct chash {
	const uint64_t C = uint64_t(2e18 * 3.1415927) + 71;
	const uint32_t R = chrono::steady_clock::now().time_since_epoch().count();
	size_t operator()(uint64_t x) const {
		return __builtin_bswap64((x ^ R) * C);
	}
};
class HashedString {
    private:
        static const ll M = 1e9 + 9;
        static const ll B = 9973;
        static vector<ll> pow;
        vector<ll> p_hash;
    public:
        HashedString(const string &s) : p_hash(size(s) + 1) {
            while (size(pow) < size(s)) { 
                pow.push_back((pow.back() * B) % M); 
            }
            p_hash[0] = 0;
            for (int i = 0; i < size(s); i++) {
                p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
            }
        }
        ll get_hash(int start, int end) {
            ll raw = (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
            return (raw % M + M) % M;
        }
};
auto HashedString::pow = {1};
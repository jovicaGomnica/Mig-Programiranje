#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll B = 31;

struct Hash {
    int n;
    string s;
    ll pw[10000];
    ll H[10000];

    Hash(string _s) {
        s = _s;
        n = s.size();
        pw[0] = 1;
        H[0] = (s[0] - 'a' + 1);
        for (int i = 1; i < n; i++) {
            pw[i] = (pw[i - 1] * B) % mod;
            H[i] = (H[i - 1] * B + (s[i] - 'a' + 1)) % mod;
        }
    }

    ll get(int l, int r) {
        if (l == 0) return H[r];
        return (H[r] - H[l - 1] * pw[r - l + 1] % mod + mod) % mod;
    }
};

int main() {
    string s1, s2;
    cout << "s: ";
    cin >> s1;
    cout << "s1: ";
    cin >> s2;

    int n1 = s1.size();
    int n2 = s2.size();

    if (n2 > n1) {
        cout << "ednoto e podolgo luud\n";
        return 0;
    }

    Hash hash_s1(s1);
    Hash hash_s2(s2);

    ll hash_s2_value = hash_s2.get(0, n2 - 1);

    vector<int> pozicii;
    for (int i = 0; i <= n1 - n2; i++) {
        if (hash_s1.get(i, i + n2 - 1) == hash_s2_value) {
            pozicii.push_back(i + 1);
        }
    }
     
   for (int pos : pozicii) {
        cout << pos << " ";
    }

    return 0;
}

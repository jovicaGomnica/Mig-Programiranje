#include <bits/stdc++.h>
using namespace std;

struct Node {
    string s = "";
    char c;
    vector<Node*> v;
};

class Trie {
    Node n;
    vector<string> found;

public:
    Trie() {
        n.s = "";
        n.c = '=';
    }

    void rec(string& s, int p, Node* k) {
        if (p == s.size()) {
            k->s = s;
            return;
        }
        for (int i=0;i<k->v.size();i++) {
            Node *sosed = k->v[i];
            if (s[p] == sosed->c)
            {
                rec(s, p+1, sosed);
                return;
            }
        }
        Node* nov = new Node;
        nov->c = s[p];
        k->v.push_back(nov);
        rec(s,p+1,nov);
    }

    void add(string& s) {
        rec(s,0,&n);
    }

    bool find(string& s,int p = 0, Node* k = nullptr) {
        if (k == nullptr) k = &n;
        if (p == s.size()) return k->s == s;

        for (int i=0;i<k->v.size();i++)
        {
            Node *sosed = k->v[i];
            if (s[p] == sosed->c) {
                return find(s,p+1, sosed);
            }
        }
        return false;
    }

    void f(string& s, int p, Node* k) {
        if (k == nullptr) k = &n;
        if (found.size() > 10) return;

        if (k->s!="" && p >= s.size()) {
            found.push_back(k->s.substr(1));
            if (found.size() > 10) return;
        }

        for (int i=0;i<k->v.size();i++)
        {
            Node *sosed = k->v[i];
            if (p < s.size() && s[p] == sosed->c) {
                f(s, p + 1, sosed);
            }
            else if (p >= s.size()) {
                f(s, p, sosed);
            }
        }
    }

    void pre(string& s) {
        found = {};
        f(s, 0, nullptr);
        for (string i : found) {
            cout<<i<<endl;
        }
        cout<<endl;
    }
};

int main()
{
    Trie t;
    while (true) {
        string s;
        cin >> s;
        if (s == "-1") break;
        s = "=" + s;
        t.pre(s);
        if (t.find(s) == false) t.add(s); 
    }
    return 0;
}

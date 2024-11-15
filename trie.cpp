#include <bits/stdc++.h>
using namespace std;

struct Node {
    string s;
    char c;
    vector<Node*> v;
};

class Trie {
    Node n;
    vector<string> found;
public:
    Trie() {
        n.s = "";
    }

    void rec(string s,int p,Node *k) {
        if (p==s.size()) {
            k->s = s;
            return;
        }
        for (int i=0;i<k->v.size();i++) {
            Node *sosed = k->v[i];
            if (s[p]==sosed->c) {
                rec(s,p+1,sosed);
            }
        }
        Node *nov = new Node;
        nov->c = s[p];
        k->v.push_back(nov);
        rec(s,p+1,nov);
    }
    void add(string s) {
        rec(s,0,&n);
    }


    bool find(string s="",int p=0,Node *k=nullptr) {
        if (k==nullptr) k = &n;
        if (k->s == s) return  true;

        for (int i=0;i<k->v.size();i++) {
            Node *sosed = k->v[i];
            if (sosed->c == s[p]) return find(s,p+1,sosed);
        }
        return false;
    }

    void f(string s,int p,Node *k) {

    }
    void pre(string s){
        found = {};
        f(s,0,nullptr);
    }

    void ispecati() {
        for (int i=0;i<found.size();i++)
            cout<<found[i]<<endl;
    }

};

int main() {
    Trie t;
    while(true) {
        string s;
        cin>>s;
        if (s=="-1") break;
        cout<<t.find(s)<<endl;
        t.pre(s);
        if (t.find(s)==false) t.add(s);

        t.ispecati();
    }

    return 0;
}

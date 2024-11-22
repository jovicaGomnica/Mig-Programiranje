#include <iostream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;


struct Node {
    vector<Node *> children(27,nullptr);

    Node() {
    }
};

class Trie {
    Node* root;
public:
    void add(string s) {
        Node* p =root;
        for (auto c: s) {
            c = tolower(c);
            if (p->children[c-'a'+1]!=nullptr) {
                p = p->children[c-'a'+1];
                continue;
            }
            else {
                p->children[c-'a'+1] = new Node();
                p = p->children[c-'a'+1];
            }

        }
        if (p->children[0] == nullptr)
            p->children[0] = new Node();
    }

    bool search(string s){
        Node *p = root;
        for (auto c: s){
            c = tolower(c);
            if (p->children[c-'a'+1]!=nullptr)
                p = p->children[c-'a'+1];
            else return false;
        }
        return true;
    }

    Trie(){ root = new Node('$'); }
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

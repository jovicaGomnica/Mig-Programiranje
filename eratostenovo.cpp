#include <bits/stdc++.h>

using namespace std;
bool sito[1000000];

int main()
{
    vector<int> prosti;
    for(int i=2;i<=1000000;i++){
        if (sito[i] == false) prosti.push_back(i);
        for (int j=i+i;j<=1e6;j+=i)
            sito[j] = true;
    }

    for (auto p: prosti){
        cout<<p<<endl;
        if (p>3000) break;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const maxn  =1e7+1;
bool erastostenovo[maxn];

int main()
{
    for (int i=2;i<=maxn;i++){
        for (int j=i+i;j<=maxn;j+=i) erastostenovo[j] = true;
    }
    
    ll n;
    cin>>n;
    vector<array<ll, 2> > v;
    for (ll i=2;i<=n;i++){
        if (erastostenovo[i]) continue;
        ll k = 0;
        while (n%i==0){
            n/=i;
            k++;
        }
        if (k>0) v.push_back({i,k});
    }

    cout<<0;
    for (auto a: v){
        cout<<" + "<<a[0]<<"^"<<a[1]<<" ";
    }

    return 0;
}

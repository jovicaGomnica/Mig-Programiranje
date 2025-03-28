#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using arr = array<ll,2>;

ll cross(arr A, arr B, arr C) {
    return (B[0] - A[0]) * (C[1] - A[1]) - (B[1] - A[1]) * (C[0] - A[0]);
}

vector<arr> convexHull(vector<arr> v) {
    sort(v.begin(), v.end());

    vector<arr> dole, gore;

    for (auto p: v) {
        while (dole.size() >= 2 && cross(dole[dole.size()-2], dole.back(), p) <= 0) {
            dole.pop_back();
        }
        dole.push_back(p);
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        arr p = v[i];
        while (gore.size() >= 2 && cross(gore[gore.size()-2], gore.back(), p) <= 0) {
            gore.pop_back();
        }
        gore.push_back(p);
    }

    dole.pop_back();
    gore.pop_back();

    for (auto a: gore) dole.push_back(a);
    return dole;
}

int main()
{
    while (true)
    {
        int n;
        cin>>n;

        if (n==0) break;

        vector<arr> v;
        for (int i = 0; i < n; i++) {
            int a,b;
            cin>>a>>b;
            v.push_back({a,b});
        }

        vector<arr> hull = convexHull(v);

        cout << hull.size() << "\n";
        for (auto p: hull) {
            cout << p[0] << " " << p[1] << "\n";
        }
        cout<<endl;
    }

    return 0;
}

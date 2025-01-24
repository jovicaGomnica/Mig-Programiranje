#include <bits/stdc++.h>

using namespace std;

struct LONG_INT{
    vector<int> data;

    LONG_INT(string s="")
    {
        for (int i=0;i<s.size();i++){
            data.push_back(s[i]-'0');
        }
    }

    LONG_INT operator+(LONG_INT const a)
    {
        vector<int> odg;
        int ost = 0;
        int p1 = a.data.size()-1,p2 = data.size()-1;
        while (p1>=0 || p2>=0)
        {
            if (p1==-1)
            {
                int c = data[p2] + ost;
                ost = c/10;
                c = c%10;
                odg.push_back(c);
                p2--;
            }
            else if (p2==-1)
            {
                int c = a.data[p1] + ost;
                ost = c/10;
                c = c%10;
                odg.push_back(c);
                p1--;
            }
            else{
                int c = a.data[p1] + data[p2] + ost;
                ost = c/10;
                c = c%10;
                odg.push_back(c);
                p1--;p2--;
            }
        }
        if (ost>0) odg.push_back(ost);
        reverse(odg.begin(),odg.end());

        LONG_INT ans("");
        ans.data = odg;
        return ans;
    }
    LONG_INT operator-(LONG_INT const a)
    {
        int p1 = a.data.size()-1,p2 = data.size()-1,c=0;
        LONG_INT ans("");
        while (p1>=0 || p2>=0)
        {
            int x = 0,y = 0;
            if (p1>=0) x = a.data[p1];
            if (p2>=0) y = data[p2];
            p1--;p2--;
            c += y-x;
            if (c<0){
                ans.data.push_back(10+c);
                c = -1;
            }
            else{
                ans.data.push_back(c);
                c = 0;
            }

        }

        if (c<0) ans.data.push_back(-(10-c));

        reverse(ans.data.begin(),ans.data.end());
        return ans;
    }

};

ostream &operator<<(ostream &o,LONG_INT const &l)
{
    for (int i=0;i<l.data.size();i++)
        o<<l.data[i];
    return o;
}
int main()
{
    LONG_INT a("999999999999999999999999999999999999999"),b("9");
    LONG_INT odg = a+b;

    cout<<odg<<endl;
    cout<<987+65<<endl;

    LONG_INT x("18"),y("9");

    cout<<endl<<y-x<<endl;
    return 0;
}

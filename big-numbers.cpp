#include <bits/stdc++.h>

using namespace std;

struct LONG_INT {
    vector<int> data;
    bool negative = false;

    LONG_INT(string s = "") {
        int i = 0;
        if (s.size()>0 && s[0] == '-') {
            negative = true;
            i++;
        }
        for (i;i<s.size();i++) {
            data.push_back(s[i]-'0');
        }
    }

    void trgni_nuli() {
        while (data.size() > 1 && data[0] == 0) {
            data.erase(data.begin());
        }
        if (data.size() == 1 && data[0] == 0) {
            negative = false;
        }
    }

    bool abs_less(const LONG_INT a) const {
        if (data.size() != a.data.size()) {
            return data.size() < a.data.size();
        }
        return data < a.data;
    }

    LONG_INT operator+(LONG_INT const &a) const {
        if (negative == a.negative) {
            LONG_INT res;
            int c = 0, p1 = data.size() - 1, p2 = a.data.size() - 1;
            while (p1 >= 0 || p2 >= 0 || c)
            {
                int sum = c;
                if (p1 >= 0) {
                    sum += data[p1];p1--;
                }
                if (p2 >= 0) {
                    sum += a.data[p2];p2--;
                }
                c = sum / 10;
                res.data.push_back(sum % 10);
            }
            reverse(res.data.begin(), res.data.end());
            res.negative = negative;
            return res;
        } else {
            if (negative) return a - (-(*this));
            else return (*this - (-a));
        }
    }

    LONG_INT operator-() const {
        LONG_INT neg = *this;
        neg.negative = !neg.negative;
        return neg;
    }

    LONG_INT operator-(LONG_INT const &a) const {
        if (negative != a.negative) {
            return *this + (-a);
        }
        if (abs_less(a)) {
            return -(a - *this);
        }
        LONG_INT ans;
        int pozemi = 0, p1 = data.size() - 1, p2 = a.data.size() - 1;
        while (p1 >= 0 || p2 >= 0) {
            int raz = 0;
            raz = data[p1] - pozemi;
            if (p2>=0) raz -= a.data[p2];

            if (raz < 0) {
                raz+= 10;
                pozemi = 1;
            } else {
                pozemi = 0;
            }
            ans.data.push_back(raz);
            p1--, p2--;
        }
        reverse(ans.data.begin(), ans.data.end());
        ans.negative = negative;
        ans.trgni_nuli();
        return ans;
    }

    friend ostream &operator<<(ostream &o, LONG_INT const &l) {
        if (l.negative && !(l.data.size() == 1 && l.data[0] == 0)) o << "-";
        for (int i : l.data) o << i;
        return o;
    }
};

int main() {
    LONG_INT a("-999999999999999999999999999999999999999"), b("9");
    cout << a + b << endl;

    LONG_INT x("18"), y("-9");
    cout << y + x <<" "<<y-x<< endl;

    LONG_INT c("1000"), d("999");
    cout << c - d << endl;

    LONG_INT e("-1000"), f("999");
    cout << e - f << endl;

    return 0;
}

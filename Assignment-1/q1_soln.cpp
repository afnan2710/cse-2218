#include <bits/stdc++.h>
using namespace std;

string solve(string s, int l, int r) {
    if(r-l<2)
        return "";
    for(int i=l; i<r; i++) {
        bool small = false;
        bool capital = false;
        for(int j=l; j<r; j++) {
            if(s[j] == tolower(s[i]))
                small = true;
            if(s[j] == toupper(s[i]))
                capital = true;
        }
        if (!small || !capital) {
            string left = solve(s, l, i);
            string right = solve(s, i+1, r);
            if (left.size() >= right.size())
                return left;
            else
                return right;
        }
    }
    return s.substr(l, r-l);
}

int main() {
    string s;
    cin>>s;
    cout<<solve(s, 0, s.size());
    return 0;
}

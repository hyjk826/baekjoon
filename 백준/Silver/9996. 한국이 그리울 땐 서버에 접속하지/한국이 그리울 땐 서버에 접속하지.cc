// 2022-09-01
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int t;
    cin >> t;
    string p;
    cin >> p;
    string a, b;
    for(int i{0}; i < (int)p.size(); ++i){
        if(p[i] == '*'){
            a = p.substr(0, i);
            b = p.substr(i + 1);
            break;
        }
    }
    while(t--){
        bool flag = true;
        string str;
        cin >> str;
        if(str.size() < max(a.size(), b.size()) + 2){
            cout << "NE\n";
        }
        else{
            string x = str.substr(0, (int)a.size());
            string y = str.substr((int)str.size() - (int)b.size());
            if(x == a && y == b){
                cout << "DA\n";
            }
            else cout << "NE\n";
        }
    }
}


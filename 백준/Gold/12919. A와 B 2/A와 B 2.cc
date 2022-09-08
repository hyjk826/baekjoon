// 2022-09-08
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
    string s, t;
    cin >> s >> t;
    queue<string> Q;
    Q.push(t);
    while(!Q.empty()){
        string str = Q.front();
        Q.pop();
        if(str == s){
            cout << 1;
            return 0;
        }
        if(str[0] == 'B'){
            string c = str;
            reverse(c.begin(), c.end());
            c.pop_back();
            if(c.size()) Q.push(c);   
        }
        if(str.back() == 'A'){
            string c = str;
            c.pop_back();
            if(c.size()) Q.push(c);
        }
    }
    cout << 0;
}
	


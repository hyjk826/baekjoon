// 2023-01-08
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
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

string f(string s, string t){
    int n = max((int)s.size(), (int)t.size());
    if((int)s.size() > (int)t.size()){
        t = string((int)s.size() - (int)t.size(), '0') + t;
    }
    else{
        s = string((int)t.size() - (int)s.size(), '0') + s;
    }
    vi vec(n + 1);
    for(int i{n}; i >= 1; --i){
        vec[i] += s[i - 1] - '0' + t[i - 1] - '0';
        if(vec[i] >= 10){
            vec[i] -= 10;
            vec[i - 1]++;
        }
    }
    string r;
    if(vec.front() != 0){
        r += vec.front() + '0';
    }
    for(int i{1}; i <= n; ++i){
        r += vec[i] + '0';
    }
    return r;
}

int main(){
	fastio;
    string s, t;
    cin >> s >> t;
    cout << f(s, t);

}

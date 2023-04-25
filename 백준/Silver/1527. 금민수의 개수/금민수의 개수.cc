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

int main(){
	fastio;
    vi A;
    function<void(string)> f = [&](string str){
        if(!str.empty()) A.push_back(stoi(str));
        if(str.size() >= 9) return;
        str += '4';
        f(str);
        str.pop_back();
        str += '7';
        f(str);
        str.pop_back();
    };
    f("");
    sort(A.begin(), A.end());
    int l, r;
    cin >> l >> r;
    cout << upper_bound(A.begin(), A.end(), r) - lower_bound(A.begin(), A.end(), l);
}

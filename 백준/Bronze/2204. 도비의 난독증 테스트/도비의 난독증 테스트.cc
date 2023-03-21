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
    int n;
    while(cin >> n){
        if(n == 0) break;
        vs vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end(), [&](string a, string b){
            string x = a;
            string y = b;
            for(auto& c : x) c = tolower(c);
            for(auto& c : y) c = tolower(c);
            return x < y;
        });
        cout << vec[0] << "\n";
    }
}

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
    cin >> n;
    vs vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi ch(n);
    int ans{0};
    for(int i{0}; i < n; ++i){
        if(ch[i]) continue;
        string a = vec[i]+ vec[i];
        for(int j{i + 1}; j < n; ++j){
            if(vec[i].size() != vec[j].size()) continue;
            if(a.find(vec[j]) != string::npos){
                ch[j] = 1;
            }
        }
        ans++;
    }
    cout << ans;
}

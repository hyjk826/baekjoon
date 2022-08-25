// 2022-08-25
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
    int n, k;
    cin >> n >> k;
    vector<vi> vec(7);
    int ans{0};
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        if(vec[a].empty()){
            ans++;
            vec[a].push_back(b);
        }
        else{
            while(!vec[a].empty() && vec[a].back() > b){
                vec[a].pop_back();
                ans++;
            }
            if(vec[a].empty() || vec[a].back() < b){
                vec[a].push_back(b);
                ans++;
            }
        }
    }
    cout << ans;
}


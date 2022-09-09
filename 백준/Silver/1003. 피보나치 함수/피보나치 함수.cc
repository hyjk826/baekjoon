// 2022-09-10
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    vp vec(41);
    vec[0] = {1, 0};
    vec[1] = {0, 1};
    for(int i{2}; i <= 40; ++i){
        vec[i] = {vec[i- 1].first + vec[i -2].first, vec[i - 1].second + vec[i - 2].second};
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << vec[n].first << " " << vec[n].second << "\n";
    }
}
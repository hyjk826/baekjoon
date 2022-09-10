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
    int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].second >> vec[i].first;
    }
    sort(vec.begin(), vec.end());
    int e = vec[0].first;
    int ans{1};
    for(int i{1}; i < (int)vec.size(); ++i){
        if(vec[i].second >= e){
            e = vec[i].first;
            ans++;
        }
    }
    cout << ans;
}
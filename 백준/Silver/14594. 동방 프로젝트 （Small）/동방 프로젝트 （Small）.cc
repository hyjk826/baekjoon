// 2022-05-28
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
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
    int m;
    cin >> m;
    vp vec(m);
    for(int i{0}; i < m; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());
    int l{-1}, r{-1};
    int k{0};
    vec.push_back({MAX, MAX});
    for(int i{0}; i < m + 1; ++i){
        if(l == -1 && r == -1){
            l = vec[i].first;
            r = vec[i].second;
        }
        else{
            if(r < vec[i].first){
                k += r - l;
                l = vec[i].first;
                r = vec[i].second;
            }
            else{
                r = max(r, vec[i].second);
            }
        }
    }
    cout << n - k;
}
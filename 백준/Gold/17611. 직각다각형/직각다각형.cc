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
    vp vec(n);    
    vector<vi> g1((int)1e6 + 1);
    vector<vi> g2((int)1e6 + 1);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
        vec[i].first += (int)5e5;
        vec[i].second += (int)5e5;
        g1[vec[i].first].push_back(vec[i].second);
        g2[vec[i].second].push_back(vec[i].first);
    }
    vi ch1((int)1e6 + 1);
    vi ch2((int)1e6 + 1);
    for(int i{0}; i <= (int)1e6; ++i){
        sort(g1[i].begin(), g1[i].end());
        sort(g2[i].begin(), g2[i].end());
        for(int j{0}; j < (int)g1[i].size(); j += 2){
            ch1[g1[i][j]]++;
            ch1[g1[i][j + 1]]--;
        }
        for(int j{0}; j < (int)g2[i].size(); j += 2){
            ch2[g2[i][j]]++;
            ch2[g2[i][j + 1]]--;
        }
    }
    for(int i{1}; i <= (int)1e6; ++i){
        ch1[i] += ch1[i - 1];
        ch2[i] += ch2[i - 1];
    }
    cout << max(*max_element(ch1.begin(), ch1.end()), *max_element(ch2.begin(), ch2.end()));
}

// 2022-07-04
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
	int k;
    cin >> k;
    vp vec(6);
    for(int i{0}; i < 6; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    vp co(6);
    co[0].first = co[0].second = 0;
    for(int i{0}; i < 6; ++i){
        int nx = (i + 1) % 6;
        if(vec[i].first == 1){            
            co[nx].first = co[i].first + vec[i].second;
            co[nx].second += co[i].second;
        }
        else if(vec[i].first == 2){
            co[nx].first = co[i].first - vec[i].second;
            co[nx].second += co[i].second;
        }
        else if(vec[i].first == 3){
            co[nx].second = co[i].second - vec[i].second;
            co[nx].first += co[i].first;
        }
        else{
            co[nx].second = co[i].second + vec[i].second;
            co[nx].first += co[i].first;
        }
    }
    int s{0};
    for(int i{0}; i < 6; ++i){
        int a = i;
        int b = (i + 1) % 6;
        s += co[a].first * co[b].second;
        s -= co[a].second * co[b].first;
    }
    cout << int(abs(s) / 2.0 * k);
}
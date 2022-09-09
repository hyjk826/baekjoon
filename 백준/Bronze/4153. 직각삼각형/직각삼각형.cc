// 2022-09-09
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
    while(1){
        vi vec(3);
        for(int i{0}; i < 3; ++i){
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        if(vec[2] == 0) break;
        if(vec[0] + vec[1] > vec[2] && vec[0] * vec[0] + vec[1] * vec[1] == vec[2] * vec[2]) cout << "right\n";
        else cout << "wrong\n";
    }
}
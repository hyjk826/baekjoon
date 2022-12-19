// 2022-12-18
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

struct st{
    int x1, y1, x2, y2;
};


int main(){
	fastio;
    vector<st> vec(2);
    for(int i{0}; i < 2; ++i){
        cin >> vec[i].x1 >> vec[i].y1 >> vec[i].x2 >> vec[i].y2;
    }
    int a = max(vec[0].x1, vec[1].x1);
    int b = min(vec[0].x2, vec[1].x2);
    int c = max(vec[0].y1, vec[1].y1);
    int d = min(vec[0].y2, vec[1].y2);
    if(a > b || c > d) cout << "NULL";
    else{
        if(a == b && c == d) cout << "POINT";
        else if(a == b || c == d) cout << "LINE";
        else cout << "FACE";
    }
}
	

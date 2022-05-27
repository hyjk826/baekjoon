// 2022-05-27
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

struct st{
    int x, y, v, num;
};

int main(){
    fastio;
    int n;
    cin >> n;
    vector<st> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].x >> vec[i].y >> vec[i].v;
        vec[i].num = i + 1;
    }
    sort(vec.begin(), vec.end(), [&](st& a, st& b){
        double d1 = sqrt(a.x * a.x + a.y * a.y) / a.v;
        double d2 = sqrt(b.x * b.x + b.y * b.y) / b.v;
        if(d1 == d2){
            return a.num < b.num;
        }
        else return d1 < d2;
    });
    for(auto& i : vec) cout << i.num << "\n";
}
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

int uni[1001];

struct st{
    int x, y, k;
};

int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}

bool Uni(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        uni[a] = b;
        return true;
    }
    return false;
}

int main(){
    fastio;
	int n, m;
    cin >> n >> m;
    vector<st> vec(m + 1);
    int a, b, c;
    cin >> a >> b >> c;
    int mn{0}, mx{0};
    if(c == 0){
        mn++;
        mx++;
    }
    for(int i{0}; i < m; ++i){
        cin >> vec[i].x >> vec[i].y >> vec[i].k;
    }
    for(int i{0}; i <= n; ++i){
        uni[i] = i;
    }
    Uni(0, 1);
    sort(vec.begin(), vec.end(), [&](st a, st b){
        return a.k < b.k;
    });
    for(int i{0}; i < m; ++i){
        if(Uni(vec[i].x, vec[i].y)){
            if(vec[i].k == 0) mn++;     
        }
    }
    for(int i{0}; i <= n; ++i){
        uni[i] = i;
    }
    Uni(0, 1);
    sort(vec.begin(), vec.end(), [&](st a, st b){
        return a.k > b.k;
    });
    for(int i{0}; i < m; ++i){
        if(Uni(vec[i].x, vec[i].y)){
            if(vec[i].k == 0) mx++;     
        }
    }
    cout << (ll)mn * mn - (ll)mx * mx;
}
// 2022-11-14
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
    int a, b, c;
    bool operator< (const st& x) const{
        if(a == x.a){
            if(b == x.b){
                return c < x.c;
            }
            else return b < x.b;
        }
        else return a < x.a;
    }
};

int main() {
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    if(n == 1){
        cout << (vec[0] + 8) / 9;
    }
    else if(n == 2){
        map<pi, int> mp;
        mp[{vec[0], vec[1]}] = 0;
        queue<pi> Q;
        Q.push({vec[0], vec[1]});
        while(!Q.empty()){
            int x{Q.front().first};
            int y{Q.front().second};
            Q.pop();
            for(int i{0}; i < 2; ++i){
                int nx = x;
                int ny = y;
                if(i == 0){
                    nx -= 3;
                    ny -= 9;
                }
                else{
                    nx -= 9;
                    ny -= 3;
                }
                if(nx <= 0 && ny <= 0){
                    cout << mp[{x, y}] + 1;
                    return 0;
                }
                else{
                    if(!mp.count({nx, ny})){
                        mp[{nx, ny}] = mp[{x, y}] + 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
    }
    else{
        map<st, int> mp;
        mp[{vec[0], vec[1], vec[2]}] = 0;
        queue<st> Q;
        Q.push({vec[0], vec[1], vec[2]});
        while(!Q.empty()){
            int a{Q.front().a};
            int b{Q.front().b};
            int c{Q.front().c};
            Q.pop();
            vi A;
            A = {1, 3, 9};
            do{
                int na = a - A[0];
                int nb = b - A[1];
                int nc = c - A[2];
                if(na <= 0 && nb <= 0 && nc <= 0){
                    cout << mp[{a, b, c}] + 1;
                    return 0;
                }
                if(!mp.count({na, nb, nc})){
                    mp[{na, nb, nc}] = mp[{a, b, c}] + 1;
                    Q.push({na, nb, nc});
                }
            }while(next_permutation(A.begin(), A.end()));
        }        
    }
}
	


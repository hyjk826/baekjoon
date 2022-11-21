// 2022-11-20
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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}



int main() {
	fastio;	
	vector<vi> ch(3, vi(3));
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        vec[i]--;
    }
    ch[vec[0] / 3][vec[0] % 3]++;
    int px = vec[0] / 3;
    int py = vec[0] % 3;
    for(int i{1}; i < n; ++i){
        int x = vec[i] / 3;
        int y = vec[i] % 3;
        int g = gcd(abs(x - px), abs(y - py));
        bool flag = true;
        for(int j{1}; j <= g - 1;++j){
            int nx = px + j * ((x - px)/ g);
            int ny = py + j * ((y - py)/ g); 
            if(ch[nx][ny] == 0){
                flag = false;
                break;
            }
        }
        if(ch[x][y] || !flag){
            cout << "NO";
            return 0;
        }
        ch[x][y] = 1;
        px = x;
        py = y;
    }
    cout << "YES";
}
	


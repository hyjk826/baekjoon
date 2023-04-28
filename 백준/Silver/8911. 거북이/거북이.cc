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
	int t;
    cin >> t;
    int xx[]{0, -1, 0, 1};
    int yy[]{1, 0, -1, 0};
    while(t--){
        string str;
        cin >> str;
        int x1{0}, x2{0}, y1{0}, y2{0};
        int x = 0;
        int y = 0;
        int dir = 0;
        for(int i{0}; i < (int)str.size(); ++i){
            if(str[i] == 'F') {
                x += xx[dir];
                y += yy[dir];
            }
            else if(str[i] == 'B'){
                x -= xx[dir];
                y -= yy[dir];
            }
            else if(str[i] == 'L'){
                dir = (dir + 1) % 4;
            }
            else if(str[i] == 'R'){
                dir = (dir - 1 + 4) % 4;
            }
            x1 = min(x1, x);
            x2 = max(x2, x);
            y1 = min(y1, y);
            y2 = max(y2, y);
        }        
        cout << (x2 - x1) * (y2 - y1) << "\n";
    }
}

// 2022-09-07
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int dis(pi a, pi b){
    int x = a.first - b.first;
    int y = a.second - b.second;
    return x * x + y * y;
}

struct st{
    int x, y, r, num;
};

vi uni(3000);

int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        uni[a] = b;
        return true;
    }
    return false;
}

int main() {
	fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i{0}; i < n; ++i){
            uni[i] = i;
        }
        vector<st> vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i].x >> vec[i].y >> vec[i].r;
            vec[i].num = i;
        }
        int cnt{n};
        for(int i{0}; i < n; ++i){
            for(int j{i + 1}; j < n; ++j){
                int k = vec[i].r + vec[j].r;
                if(dis({vec[i].x, vec[i].y}, {vec[j].x, vec[j].y}) <= k * k){
                    if(Union(vec[i].num, vec[j].num)){
                        cnt--;
                    }
                }
            }
        }
        cout << cnt << "\n";
    }    
}
	


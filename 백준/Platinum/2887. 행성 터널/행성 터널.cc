// 2022-09-14
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

vi uni(100000);

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



struct st{
    int x, y, z, num;
};

struct edge{
    int a, b, dis;
};

int main() {
	fastio;
    int n;
    cin >> n;
    vector<st> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].x >> vec[i].y >> vec[i].z;
        vec[i].num = i;
    }
    for(int i{0}; i < n; ++i){
        uni[i] = i;
    }
    vector<edge> e;
    sort(vec.begin(), vec.end(), [&](st a, st b){
        return a.x < b.x;
    });
    for(int i{0}; i < n; ++i){
        if(i == 0){
            e.push_back({vec[i].num, vec[i + 1].num, abs(vec[i].x - vec[i + 1].x)});
        }
        else if(i == n - 1){
            e.push_back({vec[i].num, vec[i - 1].num, abs(vec[i].x - vec[i - 1].x)});
        }
        else{
            e.push_back({vec[i].num, vec[i + 1].num, abs(vec[i].x - vec[i + 1].x)});
            e.push_back({vec[i].num, vec[i - 1].num, abs(vec[i].x - vec[i - 1].x)});
        }
    }
    sort(vec.begin(), vec.end(), [&](st a, st b){
        return a.y < b.y;
    });
    for(int i{0}; i < n; ++i){
        if(i == 0){
            e.push_back({vec[i].num, vec[i + 1].num, abs(vec[i].y - vec[i + 1].y)});
        }
        else if(i == n - 1){
            e.push_back({vec[i].num, vec[i - 1].num, abs(vec[i].y - vec[i - 1].y)});
        }
        else{
            e.push_back({vec[i].num, vec[i + 1].num, abs(vec[i].y - vec[i + 1].y)});
            e.push_back({vec[i].num, vec[i - 1].num, abs(vec[i].y - vec[i - 1].y)});
        }
    }
    sort(vec.begin(), vec.end(), [&](st a, st b){
        return a.z < b.z;
    });
    for(int i{0}; i < n; ++i){
        if(i == 0){
            e.push_back({vec[i].num, vec[i + 1].num, abs(vec[i].z - vec[i + 1].z)});
        }
        else if(i == n - 1){
            e.push_back({vec[i].num, vec[i - 1].num, abs(vec[i].z - vec[i - 1].z)});
        }
        else{
            e.push_back({vec[i].num, vec[i + 1].num, abs(vec[i].z - vec[i + 1].z)});
            e.push_back({vec[i].num, vec[i - 1].num, abs(vec[i].z - vec[i - 1].z)});
        }
    }
    sort(e.begin(), e.end(), [&](edge x, edge y){
        return x.dis < y.dis;
    });
    ll ans{0};
    for(int i{0}; i < (int)e.size(); ++i){
        if(Union(e[i].a, e[i].b)){
            ans += e[i].dis;
        }
    }
    cout << ans;
}
	


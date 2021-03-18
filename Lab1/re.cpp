//#include <bits/stdc++.h>
//
//using namespace std;
//
//const int INF = 1000000000, maxn = 1000100;
//
//typedef long long ll;
//
//ll x[maxn], y[maxn];
//char str[maxn];
//
//ll dist(ll x1, ll y1, ll x2, ll y2) {
//    return abs(x1 - x2) + abs(y1 - y2);
//}
//
//int main() {
//    ll x1, y1, x2, y2; scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
//    assert(0 <= x1 && x1 <= INF && 0 <= x2 && x2 <= INF && 0 <= y1 && y1 <= INF && 0 <= y2 && y2 <= INF);
//    int n; scanf("%d", &n); assert(1 <= n && n <= 1000000);
//    scanf("%s", str + 1); assert(n == strlen(str + 1));
//    x[0] = y[0] = 0;
//    for(int i = 1; i <= n; i++) {
//        assert(str[i] == 'U' || str[i] == 'D' || str[i] == 'L' || str[i] == 'R');
//        x[i] = x[i - 1]; y[i] = y[i - 1];
//        if(str[i] == 'U') y[i]--;
//        if(str[i] == 'D') y[i]++;
//        if(str[i] == 'L') x[i]++;
//        if(str[i] == 'R') x[i]--;
//    }
//    ll l = 0, r = ll(2e14);
//    while(l < r) {
//        ll mid = (l + r) >> 1, xx = (mid / n) * x[n] + x[mid % n], yy = (mid / n) * y[n] + y[mid % n];
//        if(dist(x1 + xx, y1 + yy, x2, y2) <= mid) r = mid;
//        else l = mid + 1;
//    }
//    ll xx = (l / n) * x[n] + x[l % n], yy = (l / n) * y[n] + y[l % n];
//    if(dist(x1 + xx, y1 + yy, x2, y2) <= l) printf("%lld\n", l); else puts("-1");
//    return 0;
//}

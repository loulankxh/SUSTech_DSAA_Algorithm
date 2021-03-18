//#include <bits/stdc++.h>
//
//#define clr(x) memset(x, 0, sizeof(x))
//#define reg(i, u, v) for(int i = head[u], v = e[i].to; i; i = e[i].next, v = e[i].to)
//
//using namespace std;
//
//const int maxn = 5050;
//
//struct edge {
//    int to, next, w;
//}e[maxn << 1];
//
//short dp[maxn][101][101]; int head[maxn], cnt = 1, n;
//
//void insert(int u, int v, int w) {
//    e[++cnt].to = v; e[cnt].next = head[u]; e[cnt].w = w; head[u] = cnt;
//    e[++cnt].to = u; e[cnt].next = head[v]; e[cnt].w = w; head[v] = cnt;
//}
//
//void dfs1(int u, int f, int k) {
//    reg(i, u, v) if(v != f) {
//            dfs1(v, u, k);
//            for(int x = 0; x < k; x++) if(dp[v][k][x] > 0) dp[u][k][(x + e[i].w) % k] = (dp[u][k][(x + e[i].w) % k] == 1) ? 2 : 1;
//        }
//}
//
//void dfs2(int u, int f, int k) {
//    reg(i, u, v) if(v != f) {
//            for(int x = 0; x < k; x++) if(dp[u][k][x] > 0) {
//                    if(dp[u][k][x] != 1 || dp[v][k][(x + k - e[i].w % k) % k] == 0 || dp[v][k][(x + k - e[i].w % k) % k] == 3) {
//                        if(dp[v][k][(x + e[i].w) % k] == 0 || dp[v][k][(x + e[i].w) % k] == 3 || (x + k - e[i].w % k) % k) dp[v][k][(x + e[i].w) % k] = 3;
//                        else dp[v][k][(x + e[i].w) % k] = 4;
//                    }
//                }
//            dfs2(v, u, k);
//        }
//}
//
//void init() {
//    clr(dp);
//    for(int i = 1; i <= n; i++)
//        for(int j = 1; j <= 100; j++) dp[i][j][0] = 1;
////    for(int i = 1; i <= 100; i++) dfs1(1, 0, i);
////    for(int i = 1; i <= 100; i++) dfs2(1, 0, i);
//dfs1(1,0,5); dfs2(1,0,5);
//}
//
//int main() {
//    scanf("%d", &n);
//    for(int i = 1; i < n; i++) {
//        int u, v, w; scanf("%d%d%d", &u, &v, &w);
//        insert(u, v, w);
//    }
//    init();
//    int q; scanf("%d", &q);
//    while(q--) {
//        int u, k, ans = 0; scanf("%d%d", &u, &k);
//        for(int i = k - 1; i >= 0; i--) if(dp[u][k][i] > 0) {ans = i; break;}
//        printf("%d\n", ans);
//    }
//    return 0;
//}


//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//const int mod = 2147483231;
//
//int s[4], t[4], dep[4], ed;
//
//int main() {
//    int T; scanf("%d", &T);
//    while(T--) {
//        int n = 3, m;
//        for(int i = 0; i < n; i++) scanf("%d", &s[i]);
//        scanf("%d", &ed);
//        for(int i = 0; i < n; i++) t[i] = s[i], dep[i] = 0;
//        for(int i = 0; i < n; i++) {
//            while(t[i] != ed) {
//                t[i] = 1ll * t[i] * t[i] % mod;
//                dep[i]++;
//            }
//        }
//        int mn = 8e6;
//        for(int i = 0; i < n; i++) mn = min(mn, dep[i]);
//        for(int i = 0; i < n; i++) {
//            for(int j = 0; j < dep[i] - mn; j++) s[i] = 1ll * s[i] * s[i] % mod;
//        }
//        while(1) {
//            bool ok = 1;
//            for(int i = 1; i < n; i++) {
//                if(s[i] != s[i - 1]) ok = 0;
//            }
//            if(ok) break;
//            for(int i = 0; i < n; i++) s[i] = 1ll * s[i] * s[i] % mod;
//        }
//        printf("%d\n", s[0]);
//    }
//    return 0;
//}
////#include <bits/stdc++.h>
////
////#define clr(x) memset(x, 0, sizeof(x))
////#define reg(i, u, v) for(int i = head[u], v = e[i].to; i; i = e[i].next, v = e[i].to)
////
////using namespace std;
////
////const int maxn = 5050;
////
////struct edge {
////    int to, next, w;
////}e[maxn << 1];
////
////short dp[maxn][101][101]; int head[maxn], cnt = 1, n;
////
////void insert(int u, int v, int w) {
////    e[++cnt].to = v; e[cnt].next = head[u]; e[cnt].w = w; head[u] = cnt;
////    e[++cnt].to = u; e[cnt].next = head[v]; e[cnt].w = w; head[v] = cnt;
////}
////
////void dfs1(int u, int f, int k) {
////    reg(i, u, v) if(v != f) {
////            dfs1(v, u, k);
////            for(int x = 0; x < k; x++) if(dp[v][k][x] > 0) dp[u][k][(x + e[i].w) % k] = (dp[u][k][(x + e[i].w) % k] == 1) ? 2 : 1;
////        }
////}
////
////void dfs2(int u, int f, int k) {
////    reg(i, u, v) if(v != f) {
////            for(int x = 0; x < k; x++) if(dp[u][k][x] > 0) {
////                    if(dp[u][k][x] != 1 || dp[v][k][(x + k - e[i].w % k) % k] == 0) {
////                        dp[v][k][(x + e[i].w) % k] = 3;
////                    }
////                }
////            dfs2(v, u, k);
////        }
////}
////
////void init() {
////    clr(dp);
////    for(int i = 1; i <= n; i++)
////        for(int j = 1; j <= 100; j++) dp[i][j][0] = 1;
////        dfs1(1,0,20);
////        dfs2(1,0,20);
//////    for(int i = 1; i <= 100; i++) dfs1(1, 0, i);
//////    for(int i = 1; i <= 100; i++) dfs2(1, 0, i);
////}
////
////int main() {
////    scanf("%d", &n);
////    for(int i = 1; i < n; i++) {
////        int u, v, w; scanf("%d%d%d", &u, &v, &w);
////        insert(u, v, w);
////    }
////    init();
////    int q; scanf("%d", &q);
////    while(q--) {
////        int u, k, ans = 0; scanf("%d%d", &u, &k);
////        for(int i = k - 1; i >= 0; i--) if(dp[u][k][i] > 0) {ans = i; break;}
////        printf("%d\n", ans);
////    }
////    return 0;
////}
//

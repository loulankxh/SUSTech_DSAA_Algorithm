//#include <iostream>
//#include <cmath>
//
//int prim[200005]; int top = 0;
//int isPrim(int p){
//    if(p <= 2) return 1; // 1, 2
//    int sqr = sqrt(p);
//    for(int i = 2; i <= sqr; i++){
//        if(p % i == 0) return 0;
//    }
//    return 1;
//}
//void calPrim(int p){ // p-1   >= 1
//    top = 0;
//    for(int i = 2; i < p; i++){
//        if(p % i == 0){
//            prim[++top] = i;
//            while(p % i == 0) p /= i;
//            if(isPrim(p)){
//                if(p != 1) prim[++top] = p;
//                break;
//            }
//        }
//    }
//}
//int cal(long long a, long long b, long long mod){ // 快速幂
//    int ans = 1;
//    while(b > 0){
//        if(b % 2 == 1) ans = ans * a % mod;
//        a = a * a % mod;
//        b >>= 1;
//    }
//    return ans;
//}
//int primm = 2;
//void primitive(int p){
//    calPrim(p-1);
//    int flag = 1;
//    for(int i = 2; i < p; i++){
//        flag = 1;
//        for(int j = 1; j <= top; j++){
//            if(cal(i, (p-1) / prim[j], p) == 1) {
//                flag = 0;
//                break;
//            }
//        }
//        if(flag){
//            primm = i;
//            break;
//        }
//    }
//}
//
//const int maxn = 262145;
//int fac[maxn], ans[maxn], cnt = 0;
//int pow(int a, int n, int mod) {
//    int ret = 1;
//    for(; n; n >>= 1, a = 1ll * a * a % mod) if(n & 1) ret = 1ll * ret * a % mod;
//    return ret;
//}
//
//int calc_root(int p) {
//    // euler theorem: x^{p-1}=1(mod p), then check p-1 is the least number
//    if(p == 2) return 1;
//    for(int i = 2; i * i < p; i++) if((p - 1) % i == 0) {
//            fac[++cnt] = i;
//            if(i * i != (p - 1)) fac[++cnt] = (p - 1) / i;
//        }
//    for(int x = 2; x < p; x++) {
//        bool ok = 1;
//        for(int i = 1; i <= cnt; i++) if(pow(x, (p - 1) / fac[i], p) == 1) {ok = 0; break;}
//        if(ok) return x;
//    }
//    return 0;
//}
//
//int main(){
//    int t, p;scanf("%d",&t);
//    while(t--){
//        scanf("%d",&p);
//        int a = calc_root(p);
//        primitive(p);
//        printf("%d %d\n",a , primm);
//    }
//    return 0;
//}
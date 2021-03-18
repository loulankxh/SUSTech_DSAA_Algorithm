//#include <iostream>
//#include <cmath>
//int prim[200005]; int top = 0;
//int rel1[200005], rel2[200005];
//long long ans[100005];// index:  余数
//struct node{
//    double real, imag;
//    node(){real=imag=0;}
//};
//node remain[1000005], rem2[1000005]; // index: 指数
//int n, p, tmp0, count0 = 0, siz = 1;
//
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
//void relation(int p){
//    int res = 0;
//    for(int i = 1; i < p; i++){
//        res = cal(primm, i, p); // 1~(p-1)
//        rel1[i] = res; rel2[res] = i;
//    }
//}
//void FFT(node *arr, node *arr2, int l, int r, int mode){ // 包括l，不包括r
//    int size = r-l, mid = l + size / 2, tmp = 0;
//    if(size == 1) {
//        arr2[l] = arr [l];
//        return;
//    }
//    for(int i = l; i < r; i++){
//        tmp = i - l;
//        if(tmp % 2 == 0) arr2[l + tmp/2] = arr[i];
//        else arr2[mid + tmp/2] = arr[i];
//    }
//    FFT(arr2, arr, l, mid, mode); FFT(arr2, arr, mid, r, mode);
//    double real, imag, tt=2 * M_PI/size;
//    for(int i = l; i < mid; i++){
//        tmp = i - l;
//        if(mode != 0) {
//            real = cos(tt * tmp); imag = sin(tt * tmp);
//        }
//        else{
//            real = cos(-1 * tt * tmp); imag = sin(-1 * tt * tmp);
//        }
//        arr[i].real = arr2[i].real + real * arr2[tmp + mid].real - imag * arr2[tmp + mid].imag;
//        arr[i].imag = arr2[i].imag + real * arr2[tmp + mid].imag + imag * arr2[tmp + mid].real;
//        arr[tmp + mid].real = arr2[i].real - real * arr2[tmp + mid].real +imag * arr2[tmp + mid].imag;
//        arr[tmp + mid].imag = arr2[i].imag - real * arr2[tmp + mid].imag - imag * arr2[tmp + mid].real;
//    }
//    return;
//}
//int main(){
//    scanf("%d %d",&n, &p);
//    primitive(p); relation(p);
//    for(int i = 0; i < n; i++){
//        scanf("%d", &tmp0);
//        tmp0 %= p;
//        if(tmp0)
//            remain[rel2[tmp0]].real++;
//        else count0++;
//    }
//    p *= 2;
//    while(siz < p) siz *= 2;
//    p /= 2;
//    FFT(remain, rem2, 0, siz, 1);
//    double x, y;
//    for(int i = 0; i < siz; i++){
//        x = remain[i].real; y =remain[i].imag;
//        remain[i].real = x * x - y * y;
//        remain[i].imag = 2 * x * y;
//    }
//    FFT(remain, rem2, 0, siz, 0);
//    for(int i = 0; i < siz; i++) remain[i].real /= siz;
//    int re = 0;
//    for(int i = 1; i < siz; i++){
//        if(i % (p-1) == 0) re = p - 1;
//        else re = i % (p-1);
//        ans[rel1[re]] += (long long)(remain[i].real + 0.5);
//    }
//    ans[0] = (long long)count0 * count0 + (long long)2 * count0 * (n - count0);
//    for(int i = 0; i < p; i++) printf("%lld\n", ans[i]);
//    return 0;
//}
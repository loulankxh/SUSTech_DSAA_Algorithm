//#include <iostream>
//#include <cmath>
//int prim[100005]; int top = 0;
//int rel1[100005], rel2[100005];
//long long ans[100005];// index:  余数
//struct node{
//    double real, imag;
//    node(){real=imag=0;}
//};
//node remain[500005], rem2[500005]; // index: 指数
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
//void FFT(node *arr, int size, int mode){ // 包括l，不包括r
//    int  mid = size / 2;
//    node arr1[mid], arr2[mid];
//    if(size == 1) return;
//    for(int i = 0; i < size; i++){
//        if(i % 2 == 0) arr1[i / 2] = arr[i];
//        else arr2[i / 2] = arr[i];
//    }
//    FFT(arr1, mid, mode); FFT(arr2, mid, mode);
//    double real,imag; double tt=2*M_PI/size;
//    for(int i = 0; i < mid; i++){
//        if(mode != 0) {
//            real = cos(tt * i); imag = sin(tt * i);
//        }
//        else{
//            real = cos(-1 * tt * i); imag = sin(-1 * tt * i);
//        }
//        arr[i].real = arr1[i].real + real * arr2[i].real - imag * arr2[i].imag;
//        arr[i].imag = arr1[i].imag + real * arr2[i].imag + imag * arr2[i].real;
//        arr[i + mid].real = arr1[i].real - real * arr2[i].real +imag * arr2[i].imag;
//        arr[i + mid].imag = arr1[i].imag - real * arr2[i].imag - imag * arr2[i].real;
////        if(mode == 0){ // inverse
////            arr[i].real /= size;
////            arr[i].imag /= size;
////            arr[i + mid].real /= size;
////            arr[i + mid].imag /= size;
////        }
//    }
//    return;
//}
//
//const int maxn = 262145;
//
//node x[maxn], y[maxn];
//
//int main(){
//    int n, m; scanf("%d%d", &n, &m);
//    for(int i = 0; i <= n; i++) scanf("%lf", &x[i].real);
//    for(int i = 0; i <= m; i++) scanf("%lf", &y[i].real);
//    int siz = 1;
//    while(siz < (n + m + 1)) siz <<= 1;
//    FFT(x, siz, 0); FFT(y, siz, 0);
//    for(int i = 0; i < siz; i++) {
//        double re = x[i].real, im = x[i].imag;
//        x[i].real = re * y[i].real - im * y[i].imag;
//        x[i].imag = re * y[i].imag + im * y[i].real;
//    }
//    FFT(x, siz, 1);
//    for(int i = 0; i <= n + m; i++) printf("%.0f ", x[i].real / siz);
//    puts("");
////
////    int n, p, tmp, count0 = 0, count = 0, size = 1;
////    scanf("%d %d",&n, &p);
////    calPrim(p); primitive(p); relation(p);
////    for(int i=0;i<n;i++){
////        scanf("%d", &tmp);
////        tmp %= p;
////        if(tmp) {
////            count++;
////            remain[rel2[tmp]].real++;
////        }
////        else count0++;
////    }
////    p *= 2;
////    while(size < p) size *= 2;
////    p /= 2;
////    FFT(remain, size, 1);
////    FFT(remain, rem2, 0, size, 1);
////    for(int i = 0; i < size; i++){
////        remain[i].real = remain[i].real * remain[i].real - remain[i].imag * remain[i].imag;
////        remain[i].imag = 2 * remain[i].real * remain[i].imag;
////    }
////    FFT(remain, size, 0);
////    FFT(remain, rem2, 0, size, 0);
////    for(int i = 0; i < size; i++) printf("%lf ", remain[i].real);
////    int re = 0;
////    for(int i = 1; i < size; i++){
////        if(i % (p-1) == 0) re = p -1;
////        else re = i % (p-1);
////        ans[rel1[re]] += (long long)remain[i].real;
////    }
////    ans[0] = count0 * count0 + 2 * count0 * count;
////    for(int i = 0; i < p; i++) printf("%lld\n", ans[i]);
//    return 0;
//}
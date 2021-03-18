//#include <iostream>
//long long count1[3], count2[3], rec[64][3]; // V C N
//long long pow2[64];
//
//void init(){
//    pow2[0] = 1;
//    for(int i = 1;i < 64; i++){
//        pow2[i] = pow2[i-1] * 2;
//    }
//    rec[0][0] = 1;
//    for(int i = 1; i < 64; i++){
//        rec[i][0] = rec[i-1][0] + rec[i-1][2];
//        rec[i][1] = rec[i-1][0] + rec[i-1][1];
//        rec[i][2] = rec[i-1][1] + rec[i-1][2];
//    }
//}
//
//void search(long long n, long long *c1, long long *c2){
//    int p;//放在外面，全局变量会出错
//    for(int i = 0; i < 64; i++){
//        if(pow2[i] > n){
//            n -= pow2[i-1];
//            p = i-1;
//            break;
//        }
//    }
////    for (int i=0; i<3; i++)    //这个顺序会出问题, c1在后面会被用到
////        *(c1+i) = rec[p][i];
//    if(n > 0) search(n, c2, c1);
//    else *(c2 + 2) = *(c2 + 1) = *(c2) = 0;
//    *(c1) = *(c2 + 2); *(c1+1) = *(c2); *(c1+2) = *(c2+1);
//    for (int i=0; i<3; i++)
//        *(c1+i) += rec[p][i];
//    return;
//}
//
//int main(){
//    int t; long long n; scanf("%d",&t);
//    init();
//    while(t--){
//        scanf("%lld", &n);
//        search(n, count1, count2);
//        printf("%lld %lld %lld\n",count1[0],count1[1],count1[2]);
//    }
//    return 0;
//}
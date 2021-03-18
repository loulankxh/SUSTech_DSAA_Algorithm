//#include <iostream>
//struct node{
//    int cost, val;
//    node(){cost = val = 0;}
//};
//node ns[95];
//int dp[35][310];
//int main(){
//    int cost, x, y, z;scanf("%d",&cost);
//    for(int i = 1; i <= 90; i++){
//        scanf("%d%d%d",&x, &y, &z);
//        ns[i].cost = x; ns[i].val = y + z;
//    }
// 根据lab14_2来看是要有初始化问题的（不能满足的情况设置为-1）,只是本题未出错
//    for(int i = 1; i <= 90; i++){
//        for(int j = cost; j >= 0; j--){
//            for(int k = 30; k > 0; k--){
//                if(k <= i && ns[i].cost <= j){
//                    if(dp[k][j] < ns[i].val + dp[k-1][j-ns[i].cost])
//                        dp[k][j] = ns[i].val + dp[k-1][j-ns[i].cost];
//                }
//            }
//        }
//    }
//    printf("%d", dp[30][cost]);
//    return 0;
//}
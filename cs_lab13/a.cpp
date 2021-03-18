//#include <iostream>
//int dp[1005], val[105][105], costt[105][105];
//int main(){
//    int n, k, c, cost, attack, health; scanf("%d%d%d",&n, &k, &c);
//    for(int i = 1; i <= n; i++){
//        for(int j = 0; j < k; j++){
//            scanf("%d %d %d", &cost, &attack, &health);
//            val[i][j] = attack + health; costt[i][j] = cost;
//        }
//    }
//    int tmp = 0;
//    for(int i = 1; i <= n; i++){
//        for(int j = c; j > 0; j--){ // cost
//            for(int m = 0; m < k; m++){
//                if(costt[i][m] <= j){
//                    tmp = val[i][m] + dp[j-costt[i][m]];
//                    if(tmp > dp[j])dp[j] = tmp;  // 所有tmp < dp[j] => 不选
//                }
//            }
//        }
//    }
//    printf("%d",dp[c]);
//    return 0;
//}
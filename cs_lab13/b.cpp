#include <iostream>
long long  dp[2][205][2], val[100005];
long long ans = 0, cur = 0, res = 1;
int main(){
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld",&val[i]);
    if(val[1] == -1){ // initial
        for(int i = 1; i < 201; i++){
            dp[cur][i][0] = 1; dp[cur][i][1] = 0;
        }
    }
    else dp[cur][val[1]][0] = 1;
    for(int i = 2; i <= n; i++){
        //res 要清零重置！
        for(int m = 0; m < 201; m++) dp[res][m][0] = dp[res][m][1] = 0;
        if(val[i] == -1){
            for(int j = 1; j < 201; j++) {
                if(j == 1){  // 1: AI <= AI-1
                    dp[res][1][1] = dp[cur][1][0];
                    for (int k = 1; k < 201; k++) {
                        dp[res][1][1] += dp[cur][k][1];
                        dp[res][1][1] %= 998244353;
                    }
                }
                else{  //减少重复计算
                    dp[res][j][1] = (dp[res][j-1][1] - dp[cur][j-1][1] - dp[cur][j-1][0] + dp[cur][j][0]) + 2 * 998244353; //负数
                    dp[res][j][1] %= 998244353;
                }

//                for (int k = 1; k < j; k++) {  // 0: AI > AI-1
                dp[res][j][0] = dp[res][j-1][0] + dp[cur][j-1][0] + dp[cur][j-1][1];  //减少重复计算
                dp[res][j][0] %= 998244353;
//                }
            }
        }
        else{
            dp[res][val[i]][1] = dp[cur][val[i]][0];
            for(int k = val[i]; k < 201; k++) {
                dp[res][val[i]][1] += dp[cur][k][1];
                dp[res][val[i]][1] %= 998244353;
            }

            for(int k = 1; k < val[i]; k++){
                dp[res][val[i]][0] += dp[cur][k][0] + dp[cur][k][1];
                dp[res][val[i]][0] %= 998244353;
            }
        }
        cur ^= 1; res ^= 1;
    }
    for(int i = 1; i < 201; i++){
        ans += dp[cur][i][1];
        ans %= 998244353;
    }
    printf("%lld", ans);
    return 0;
}
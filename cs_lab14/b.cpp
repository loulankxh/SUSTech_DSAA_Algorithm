#include <iostream>
#include <algorithm>
int as[105], bs[105], cs[105], dp[105][10200];
//int com(int a, int b){ // max -> min
//    return a > b;  // 加了一个等号，sort就出错了？？？ cs前面几个都是0
//}
int main(){
    int n, num = 0, m = 0, c = 100;scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &as[i], &bs[i]);
        num += as[i];
        cs[i] = bs[i];
    }
    int x = num;
    std::sort(cs+1,cs+n+1, std::greater<int>());
    for(int i = 1; i <= n; i++){
        if(x > 0){
            x -= cs[i];
            m++;
        }
        bs[i] = c - bs[i];
    }
    for(int i = 1; i < 105; i++){
        for(int j = 0; j < 10200; j++)
            dp[i][j] = -1;
    }
    x = m * c - num; int tmp = 0;
    for(int i = 1; i <= n; i++){
        // initial: dp[k][j] = 0 => k的限定： 假设补上对应件价值为0的物品  前提：实际上至少有一种恰好为k件的方案
        // 不能这样想，不存在就是不存在
        for(int j = x; j >= 0; j--){ // cost
            for(int k = m; k > 0; k--){ // box number
                if(bs[i] <= j){
                    tmp = dp[k - 1][j-bs[i]] + as[i];  // dp[0][x] = 0
                    if(dp[k - 1][j-bs[i]] == -1 && k != 1) tmp = -1;
                    if(tmp > dp[k][j]) dp[k][j] = tmp;
                }
            }
        }
    }
    x= num - dp[m][x];
    printf("%d",x);
    return  0;
}
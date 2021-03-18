#include <iostream>
#include <cmath>

int count[1000005], dp[1000005][3][3]; // dp[i][x][y]: 最大tile数，其中每个tile至少包含一个小于等于i的数
//且（i-1, i, i+1）、(i, i + 1, i + 2)的个数为x、y
int main(){
    int n, m, x, max = 0; scanf("%d%d",&n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d",&x);
        count[x]++;
        if(max < x) max = x;
    }
    int val = 0;
    for(int i = 1; i <= max; i++){ // 遍历到第i个数
        for(int b = 0; b <=2; b++){ // dp[i-1][a][b]
            for(int c = 0; c <= 2; c++){ // dp[i][b][c]
                for(int a = 0; a <= 2; a++){ // 对于确定的b、c,遍历a
                    if(a + b + c <= count[i])val = dp[i-1][a][b] + c + floor((count[i] - a - b - c)/3);
                    if(val > dp[i][b][c]) dp[i][b][c] = val;
                }
            }
        }
    }
    printf("%d",dp[max][0][0]);
    return 0;
}
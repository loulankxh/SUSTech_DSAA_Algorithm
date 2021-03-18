#include <cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include <iostream>
using namespace std;
int main(){
    int t[10]={5,3,7,5,3,2,9,7,8,9};
    sort(t+1,t+6);
    for(int i=0;i<10;i++){
        printf("%d",t[i]);
    }
}
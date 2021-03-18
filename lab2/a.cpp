//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//void test(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        int n;
//        scanf("%d",&n);
//        int num[n];
//        for(int i=0;i<n;i++){
//            scanf("%d",&num[i]);//没有初始化！不要把num当成全局变量
//        }
//        sort(num,num+n);
//        if(num[n-3]!=num[n-2]&&((n>3&&num[n-3]!=num[n-4])||n==3))printf("%d\n",num[n-3]);//运算优先级？
//            //数组初始化会不会是0？or int上界？
//            //考虑数组越界---n>3(为了逻辑正确n==3不能舍去)
//        else printf("%s\n","wa");
//    }
//}
//int main() {
//    test();
//    return 0;
//}
//

//#include <iostream>
//using namespace std;
//int m=0,n=0;
//char s[200009],t[200009];
//int main(){
//    int T;
//    scanf("%d",&T);
//    while(T--){
//        scanf("%d%d%s%s",&n,&m,s,t);
//        if(n>m+1)printf("%s\n","NO");
//        else{
//            int flag1=1,flag2=0;
//            for(int i=0;i<n;i++){
//                if(s[i]=='*'){
//                    flag2=1;
//                    break;
//                }
//                else if(i==m||s[i]!=t[i]){
//                    flag1=0;
//                    break;
//                }
//            }
//            if(!flag2&&n<m)flag1=0;
//            if(flag2&&flag1){
//                for(int i=1;i<=n&&s[n-i]!='*';i++){
//                    if(s[n-i]!=t[m-i]){
//                        flag1=0;
//                        break;
//                    }
//                }
//            }
//            if(flag1)printf("%s\n","YES");
//            else printf("%s\n","NO");
//        }
//    }
//    return 0;
//}
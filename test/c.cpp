//#include <iostream>
//int num[2005][256];
//char str[2005];
//int main(){
//    int n,m;
//    scanf("%d%d",&n,&m);
//    int time=n-m+1;
//    for(int i=1;i<=time;i++){
//        scanf("%s",str);
//        for(int j=0;j<n;j++){
//            num[j][(int)str[j]]++;
//        }
//    }
//    char me;
//    for(int i=0;i<n;i++){
//        for(int j=0;j<256;j++){
//            if(num[i][j]>5){
//                me=(char)j;
//                printf("%c",me);
//                break;
//            }
//        }
//    }
//    return 0;
//}
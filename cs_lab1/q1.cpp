//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//int n,limit;
//int cN[1001];//每个men进行到了他的第几个woman
//int pm[1001][1001],pw[1001][1001];//preference list of men and women
//string m[1001],w[1001];//sequence of men and women
//int curM[1001],curW[1001];//current matching of man and woman
//bool flag=true;
//int findNum(string s,int model){
//    if(model==1){
//      return find(m+1,m+n+1,s)-m;
//    }
//    else{
//        return find(w+1,w+n+1,s)-w;
//    }
//}
//void matching(int i){
//    int me,tmp=pm[i][cN[i]];
//    if(curW[tmp]==0||pw[tmp][curW[tmp]]>pw[tmp][i]){
//        me=curW[tmp];
//        curW[tmp]=i;
//        curM[i]=tmp;
//        if(me!=0){
//            cN[me]++;
//            if(cN[me]>n)flag=false;
//            else  matching(me);
//        }
//    }
//    else {
//        cN[i]++;
//        if(cN[i]>n)flag=false;//non existence
//        else matching(i);
//    }
//}
//int main(){
//    scanf("%d",&n);
////    limit=n*n;//one way to judge existence, times no more than n*n
//    string s1,s2;
//    for(int i=1;i<=n;i++){//preference of man
//        cin>>s1;
////        scanf("%s",&s1);
//        m[i]=s1;
//        for(int j=1;j<=n;j++){
//            cin>>s2;
////            scanf("%s",&s2);
//            if(i==1){
//                w[j]=s2;
//                pm[1][j]=j;
//            }
//            else pm[i][j]=findNum(s2,2);
//        }
//    }
//    int ww = 0,mm=0;
//    for(int i=1;i<=n;i++) {//preference of woman, reverse
//        cin>>s2;
////        scanf("%s", &s2);
//        ww=findNum(s2,2);
//        for (int j = 1; j <= n; j++) {
//            cin>>s1;
////            scanf("%s", &s1);
//            mm=findNum(s1,1);
//            pw[ww][mm]=j;
//        }
//    }
//    for(int i=1;i<=n;i++){
//       if(flag){
//           cN[i]++;//待尝试去匹配
//           matching(i);
//       }
//       else{
//           printf("%s","impossible");
//           break;
//       }
//    }
//    if(flag){
//        for(int i=1;i<=n;i++){
//            //string 怎么输出？
////            cout<<m[i]<<" "<<w[curM[i]]<<endl;
//            printf("%s %s\n",m[i].c_str(),w[curM[i]].c_str());
//        }
//    }
//    return 0;
//}
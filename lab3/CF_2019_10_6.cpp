//A:
//#include <cstdio>
//using namespace std;
//int main(){
//    int q;
//    scanf("%d",&q);
//    while(q--){
//        int n;
//        scanf("%d",&n);
//        if(n==2)printf("%d\n",2);
//        else{
//            if(n%2==0)printf("%d\n",0);
//            else printf("%d\n",1);
//        }
//    }
//    return 0;
//}

//B
//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//int location[26];
//int main(){
//    int q;
//    scanf("%d",&q);
//    bool flag;
//    while(q--){
//        flag=false;
//        string s,t;
//        cin>>s>>t;
//        int l=s.length();
//        for(int i=0;i<26;i++){
//            location[i]=0;
//        }
//        for(int i=0;i<l;i++){
//            location[s[i]-'a']++;
//        }
//        for(int i=0;i<l;i++){
//            if(location[t[i]-'a']!=0){
//                flag=true;
//                break;
//            }
//        }
//        if(flag)printf("%s\n","YES");
//        else printf("%s\n","NO");
//    }
//    return 0;
//}


//C
//#include <cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cmath>
//#include<algorithm>
//#include <iostream>
//using namespace std;
//long long price[200009];
//int gcd(int a,int b){
//    int max=a>b?a:b,min=a>b?b:a;
//    while(min!=0){
//        int tmp=min;
//        min=max%min;
//        max=tmp;
//    }
//    return  max;
//}
//int com(int a, int b){
//    return a>b;
//}
//int main(){
//    int q;
//    scanf("%d",&q);
//    while(q--){
//        int n;
//        scanf("%d",&n);
//        for(int i=0;i<n;i++){
//            scanf("%lld",&price[i]);
//        }
//        sort(price,price+n,com);
//        for(int i=1;i<n;i++){
//            price[i]+=price[i-1];
//        }
//        int x,a,y,b;
//        long long k;
//        scanf("%d%d%d%d%lld",&x,&a,&y,&b,&k);
//        int a1=0,b1=0,ab=a*b/gcd(a,b),ab1=0,xy=x+y;
//        long long k1=k;
//        bool flag1=x>y?true:false,flag2=false,flag;
//        int count=0;
//        for(int i=0;i<n;i++){//i=n-1恰好符合时单独判断一下（i=n越界）
//            if(k1<=0){
//                flag2=true;
//                count=i;
//                break;
//            }
//            else{
//                flag= false;
//                if((i+1)%ab==0){
//                    ab1++;
//                    flag=true;
//                }
//                else if((i+1)%a==0){
//                    a1++;
//                    flag=true;
//                }
//                else if((i+1)%b==0){
//                    b1++;
//                    flag=true;
//                }
//                if(flag){
//                    k1=k;
//                    if(flag1)k1-=price[ab1-1]/100*xy+(price[ab1+a1-1]-price[ab1-1])/100*x+(price[ab1+a1+b1-1]-price[ab1+a1-1])/100*y;
//                    else k1-=price[ab1-1]/100*xy+(price[ab1+b1-1]-price[ab1-1])/100*y+(price[ab1+a1+b1-1]-price[ab1+b1-1])/100*x;
//                }
//            }
//        }
//        if(k1<=0&&!flag2){
//            count=n;
//            flag2= true;
//        }
//        if(flag2)printf("%d\n",count);
//        else printf("%d\n",-1);
//    }
//    return 0;
//}
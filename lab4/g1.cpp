//#include <cstdio>
//using namespace std;
//char stack1[102],stack2[102];
//int stack3[102];
//int top1=-1,top2=-1,top3=-1,ans=0;
//int compare(char s1,char s2){
//    int id1=0,id2=0;
//    if(s1=='*')id1=3;
//    else if(s1=='+'||s1=='-')id1=4;
//    else if(s1=='&')id1=5;
//    else if(s1=='^')id1=6;
//    else if(s1=='|')id1=7;
//    if(s2=='*')id2=3;
//    else if(s2=='+'||s2=='-')id2=4;
//    else if(s2=='&')id2=5;
//    else if(s2=='^')id2=6;
//    else if(s2=='|')id2=7;
//    return id1<=id2;
//}
//void push1(char s1){
//    top1++;
//    stack1[top1]=s1;
//}
//void push2(char s1){
//    top2++;
//    stack2[top2]=s1;
//}
//void push3(int s1){
//    top3++;
//    stack3[top3]=s1;
//}
//char pop2(){
//    top2--;
//    return stack2[top2+1];
//}
//int pop3(){
//    top3--;
//    return stack3[top3+1];
//}
//void putIn(char s[]){
//    for(int i=0;s[i]!='\0';i++){
//        if(0<=s[i]-'0'&&s[i]-'0'<=9){
//            push1(s[i]);
//            while(top2!=-1&&(stack2[top2]=='u'||stack2[top2]=='d'||stack2[top2]=='~'))
//                push1(pop2());
//            if(s[i+1]=='\0'){
//                while(top2!=-1){
//                    push1(pop2());
//                }
//            }
//            else {
//                bool flag=false;
//                while(s[i+1]==')'){
//                    flag=true;
//                    while (stack2[top2]!='('){
//                        push1(pop2());
//                    }
//                    pop2(),
//                            i++;
//                }
//                while(top2!=-1&&stack2[top2]!='('&&compare(stack2[top2],s[i+1]))
//                    push1(pop2());
//                if(flag)i--;
//            }
//        }
//        else {
//            if(s[i]=='+'&&s[i-1]!=')'&&(i==0||s[i-1]=='('||s[i-1]-'0'>9||s[i-1]-'0'<0))push2('u');
//            else if(s[i]=='-'&&s[i-1]!=')'&&(i==0||s[i-1]=='('||s[i-1]-'0'>9||s[i-1]-'0'<0))push2('d');
//            else if(s[i]!=')')push2(s[i]);
//        }
//    }
//    while(top2!=-1)push1(pop2());
//}
//void calculate(){
//    int tmp1=0,tmp2=0;
//    for(int i=0;i<=top1;i++){
//        if(stack1[i]-'0'<=9&&stack1[i]-'0'>=0){
//            push3(stack1[i]-'0');
//        }
//        else if(stack1[i]=='u');
//        else if(stack1[i]=='d'){
//            tmp1=pop3();
//            push3(-tmp1);
//        }
//        else if(stack1[i]=='~'){
//            tmp1=pop3();
//            push3(~tmp1);
//        }
//        else if(stack1[i]=='*'){
//            tmp1=pop3();
//            tmp2=pop3();
//            push3(tmp1*tmp2);
//        }
//        else if(stack1[i]=='+'){
//            tmp1=pop3();
//            tmp2=pop3();
//            push3(tmp1+tmp2);
//        }
//        else if(stack1[i]=='-'){
//            tmp1=pop3();
//            tmp2=pop3();
//            push3(tmp2-tmp1);
//        }
//        else if(stack1[i]=='&'){
//            tmp1=pop3();
//            tmp2=pop3();
//            push3(tmp1&tmp2);
//        }
//        else if(stack1[i]=='^'){
//            tmp1=pop3();
//            tmp2=pop3();
//            push3(tmp1^tmp2);
//        }
//        else if(stack1[i]=='|'){
//            tmp1=pop3();
//            tmp2=pop3();
//            push3(tmp1|tmp2);
//        }
//    }
//}
//int main(){
//    int t;
//    scanf("%d",&t);
//    while(t--){
//        top1=top2=top3=-1;
//        ans=0;
//        char s[102];
//        scanf("%s",s);
//        putIn(s);
//        calculate();
//        printf("%d\n",stack3[0]);
//    }
//    return 0;
//}
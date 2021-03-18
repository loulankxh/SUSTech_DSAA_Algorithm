#include <iostream>

int baseExpansion(int baseA,int a,int b){//convert number of base a to number of base b
    int base10,baseB;
    if(a==10)base10=baseA;
    else{
        int time1=1;
        while(baseA!=0){//base a to base 10
            base10+=(baseA%10)*time1;
            time1*=a;
            baseA/=10;
        }
    }
    if(b==10)return base10;
    else{
        int time2=1;
        while(base10/b){//base 10 to base b
            baseB+=(base10%b)*time2;
            time2*=10;
            base10/=b;
        }
        return baseB;
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
//#include <iostream>
//namespace Quick_in {
//    const int LEN=(1<<21)+1; char ibuf[LEN],*iH,*iT;int f,c;
//#define gc()(iH==iT?(iT=(iH=ibuf)+fread(ibuf,1,LEN,stdin),(iH==iT?EOF:*iH++)):*iH++)
//    inline char nc(){
//        while((c=gc())<=32)if(c==-1)return -1;
//        return (char)c;
//    }
//    template<class T> inline void scan(T&x){
//        for (f=1,c=gc();c<'0'||c>'9';c=gc()) if (c=='-') f=-1;
//        for (x=0;c<='9'&&c>='0';c=gc()) x=x*10+(c&15); x*=f;
//    }
//    template<class T> inline bool read(T&x){
//        for (f=1,c=gc();c<'0'||c>'9';c=gc()){ if(c==-1)return 0;if(c=='-') f=-1; }
//        for(x=c-48;;x=x*10+(c&15)){ if(!isdigit(c=gc()))break;}x*=f; return 1;
//    }
//    inline int gline(char*s){
//        int l=-1;
//        for (c=gc();c<=32;c=gc())if(c==-1)return c;
//        for (;c>32||c==' ';c=gc()){
//            s[++l]=c;
//        }
//        s[l+1]=0;
//        return l;
//    }
//    inline int gs(char *s){
//        int l=-1;
//        for (c=gc();c<=32;c=gc())if(c==-1)return c;
//        for (;c>32;c=gc()){
//            s[++l]=c;
//        }
//        s[l+1]=0;
//        return l;
//    }
//    template <typename A, typename B> inline void scan(A&x,B&y){scan(x),scan(y);};
//    template <typename A, typename B> inline bool read(A&x,B&y){return read(x)&&read(y);};
//}
//using Quick_in::scan;
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}
//#include <bits/stdc++.h>
//#define mp make_pair
//#define pub push_back
//#define pob pop_back
//#define pof pop_front
//#define pii pair<int, int>
//#define fi first
//#define se second
//#define MOD 1000000007
//#define MOD2 998244353
//#define LL long long
//#define ULL unsigned long long
//#define ui unsigned int
//#define bas 26
//#define bas2 131
//using namespace std;
//const int N = 200005;
//const int M = 8000005;
//const int INF = 1000000000;
//typedef double db;
//const db eps = 1e-8;
//const db pi = acos(-1);
//const db inf = 1e30;
//inline int sign(db a) { return a < -eps ? -1 : a > eps;}
//inline int cmp(db a, db b) {return sign(a - b);}
//inline int inmid(db a, db b, db c)
//{return sign(a - c) * sign(b - c) <= 0;}//c在[a,b]内
////L line S segment P point
//struct point {
//    db x, y;
//    point() {}
//    point(db _x, db _y): x(_x), y(_y) {}
//    point operator + (const point &p) const {return point(x + p.x, y + p.y);}
//    point operator - (const point &p) const {return point(x - p.x, y - p.y);}
//    point operator * (db k) const {return point(x * k, y * k);}
//    point operator / (db k) const {return point(x / k, y / k);}
//    int operator == (const point &p) const
//    {return cmp(x, p.x) == 0 && cmp(y, p.y) == 0;}
//    point turn(db k) {return point(x * cos(k) - y * sin(k), x * sin(k) + y * cos(k));}
//    point turn90() {return point(-y, x);}
//    bool operator < (const point &p) const {
//        int c = cmp(x, p.x);
//        if(c) return c == -1;
//        return cmp(y, p.y) == -1;
//    }
//    bool operator > (const point &p) const {
//        int c = cmp(x, p.x);
//        if(c) return c == 1;
//        return cmp(y, p.y) == 1;
//    }
//    db abs() {return sqrt(x * x + y * y);}
//    db abs2() {return x * x + y * y;}
//    db disto(point p) {return (*this - p).abs();}
//    db alpha() {return atan2(y, x);}
//    point unit() {db z = abs(); return point(x / z, y / z);}
//    void scan() {db _x, _y; scanf("%lf%lf", &_x, &_y); x = _x, y = _y;}
//    void print() {printf("%.11lf %.11lf\n", x, y);}
//    point getdel()
//    {return (sign(x)==-1||(sign(x)==0&&sign(y)==-1))?(*this)*(-1):(*this);}
//    int getP() const{return sign(y) == 1 || (!sign(y) && sign(x) == -1);}//向量相对方向
//};
//int inmid(point p1, point p2, point p3)
//{return inmid(p1.x, p2.x, p3.x) && inmid(p1.y, p2.y, p3.y);}
//db dot(point p1, point p2) {return p1.x * p2.x + p1.y * p2.y;}
//db cross(point p1, point p2) {return p1.x * p2.y - p1.y * p2.x;}
//db rad(point p1, point p2) {return atan2(cross(p1, p2), dot(p1, p2));}
//int compareangle(point p1, point p2) {
//    return p1.getP() < p2.getP() || (p1.getP() == p2.getP() && sign(cross(p1, p2)) > 0);
//}
//int convex(vector<point> ps) {
//    int n = ps.size(); if(n <= 1) return n;
//    sort(ps.begin(), ps.end());
//    vector<point> qs(n * 2); int k = 0;
//    for(int i = 0; i < n; qs[k++] = ps[i++]) {
//        while(k > 1 && sign(cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 2])) < 0) --k;
//    }
//    for(int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--]) {
//        while(k > t && sign(cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 2])) < 0) --k;
//    }
//    return k - 1;
//}
//
//vector<point> ps;
//int main() {
//    int n; scanf("%d", &n);
//    for(int i = 0; i < n; i++) {
//        double x, y; scanf("%lf%lf", &x, &y);
//        ps.push_back(point(x, y));
//    }
//    printf("%d\n", convex(ps));
//    return 0;
//}
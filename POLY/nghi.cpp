#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
double const eps=1e-10;

int cmp(double a,double b){
	return a + eps > b ? a - eps < b ? 0 : 1 : -1;
}

struct point{
	double x,y;
	point () {x=y=0.0;}
	point (double a,double b): x(a),y(b) {}
	point operator + (point p) {return point(x+p.x,y+p.y);}
	point operator - (point p) {return point(x-p.x,y-p.y);}
	point operator * (double t) {return point(x*t,y*t);}
	point operator / (double t) {return point(x/t,y/t);}
	double operator * (point p) {return x*p.x+y*p.y;} 
	double operator % (point p) {return x*p.y-y*p.x;}
	int cmp(point p) const {if(int t=::cmp(x,p.x)) return t;return ::cmp(y,p.y);}
	#define comp(x) bool operator x (point p) const { return cmp(p) x 0; } 
	comp(>) comp(>=) comp(<=) comp(<) comp(==) comp(!=)
	#undef comp
};

typedef vector<point> polygon;

int ccw(point a,point b,point c){
	return cmp((b-a)%(c-a),0)>0;
}

struct comp_hull{
	point pivot;
	bool operator () (point a,point b){
        point Q = a - pivot, W = b - pivot;
        double R = Q % W;
        if (cmp(R,0)) return R < 0;
        return cmp(Q*Q,W*W) < 0;
	}
};

polygon conhull(polygon p){
	int j = 0, n = p.size();
    polygon r(n);
    if (!n) return r;
    comp_hull comp;
    comp.pivot = *min_element(p.begin(),p.end());
    sort(p.begin(),p.end(),comp);
    for(int i=0;i<n;i++){
        while (j > 1 && ccw(r[j-1],r[j-2],p[i]) <= 0) j--;
        r[j++] = p[i];
    }
    r.resize(j);
    return r;
}

double dist(point a,point b){
	return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}

int main()
{
	freopen("POLY.INP","r",stdin);
	freopen("POLY.OUT","w",stdout);
	int n,tc;
	double x,y;
	polygon a;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);a.clear();
		for(int i=0;i<n;i++){scanf("%lf%lf",&x,&y);a.push_back(point(x,y));}
		polygon r = conhull(a);
		double res=0.0;
		for(int i=1;i<(int)r.size();i++) res+=dist(r[i],r[i-1]);
		res+=dist(r.back(),r[0]);
		long long ares=res;
		printf("%lld %d\n",ares,r.size());
	}
	return 0;
}

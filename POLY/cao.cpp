#include <algorithm>
#include <bitset>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

#define fi first
#define se second
#define pb push_back

#define fo(i, a, b) for(int i=a, _b=b; i<=_b; i++)
#define fod(i, a, b) for(int i=a, _b=b; i>=_b; i--)
/*----------------------------------------------------------------------*/

#define FR(i, n) for(int i=0, _n=(n); i<_n; i++)
#define FOR(i, a, b) for(int i=a, _b=(b); i<_b; i++)

const double eps = 1e-10;
int cmp(double q,double w) {
    return (q < w + eps) ? (q > w - eps) ? 0 : -1 : 1;
}

struct point {
    double x,y;
    point (double x,double y): x(x),y(y) {}
    point () {x=y=0.0; }
    point operator +(point q) { return point(x+q.x,y+q.y); }
    point operator -(point q) { return point(x-q.x,y-q.y); }
    point operator *(double t) { return point(x*t,y*t); }
    point operator /(double t) { return point(x/t,y/t); }
    double operator *(point q){ return q.x * x + q.y * y; }
    double operator %(point q){ return x*q.y - y*q.x; }
    int cmp(point q) const { if(int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }
    #define Comp(x) bool operator x (point q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
    #undef Comp
};

typedef vector<point> polygon;
inline int ccw(point a, point b, point c) {
    return cmp((b-a)%(c-a),0);
}

struct comp_hull {
    point pivot;
    bool operator() (point q,point w) {
        point Q = q - pivot, W = w - pivot;
        double R = Q % W;
        if (cmp(R,0)) return R < 0;
        return cmp(Q*Q,W*W) < 0;
    }
};

polygon convex_hull(polygon p) { // minimum vertices
    int j = 0, n = p.size();
    polygon r(n);
    if (!n) return r;
    comp_hull comp;
    comp.pivot = *min_element(p.begin(),p.end());
    sort(p.begin(),p.end(),comp);
    //fo(i, 0, (int)p.size()-1) cerr<<p[i].x<<" "<<p[i].y<<endl;
    FR(i,n) {
        while (j > 1 && ccw(r[j-1],r[j-2],p[i]) <= 0) j--;
        r[j++] = p[i];
    }
    r.resize(j);
    return r;
}

double dist(point a, point b)
{
	double x=a.x-b.x, y=a.y-b.y;
	return sqrt(x*x+y*y);
}

int main() {
	freopen("POLY.INP", "r", stdin);
	freopen("POLY.OUT","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int n;
		polygon x;
		point s;
		cin>>n;
		fo(i, 1, n) {
			int u, v;
			cin>>u>>v;
			s.x=u;
			s.y=v;
			x.pb(s);
		}
		//fo(i, 0, (int)x.size()-1) cerr<<x[i].x<<" "<<x[i].y<<endl;cerr<<endl;
		x=convex_hull(x);
		//cout<<x.size()<<" ";
		//cerr<<endl;
		//fo(i, 0, (int)x.size()-1) cerr<<x[i].x<<" "<<x[i].y<<endl;
		double sum=0;
		fo(i, 1, (int)x.size()-1) sum+=dist(x[i], x[i-1]);
		sum+=dist(x[0], x[(int)x.size()-1]);
		printf("%lld %d\n", (long long)(sum), x.size());
	}
	return 0;
}

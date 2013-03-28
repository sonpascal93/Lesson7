#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<bitset>
#include<set>
#include<climits>
#include<deque>
#include<utility>
#include<functional>
#include<istream>
#include<ostream>
#include<memory>
#include<locale>
#include<cassert>
#include<iterator>
#define oo 1000000000
#define base 1000000007ll
#define MAX 1005
using namespace std;
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
const double eps=1e-6;
/*                                                          End of template                                                                */

dd root;
double radius;
vector<dd> point,Rotate;
int n,ans=0;
void rotation(double angle)
{
    int i,j,res=0,s=0;
    Rotate.assign(point.begin(),point.end());
    for(i=0; i<Rotate.size(); i++)
    {
        double x=Rotate[i].first,y=Rotate[i].second;
        x=x*cos(angle)-y*sin(angle);
        y=x*sin(angle)+y*cos(angle);
        if(x>=-eps) s++;
        if(y>=-eps) res++;
    }
    ans=max(ans,max(res,s));
}
void execute()
{
    int i,j,n;
    double d,a,b,angle;
    ans=0;
    point.clear();
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%lf %lf",&a,&b);
        a-=root.first;
        b-=root.second;
        d=pow(a,2)+pow(b,2);
        if(d<=radius) point.push_back(dd(a,b));
    }
    for(angle=0; angle<=360.0; angle+=0.18) rotation(angle);
    printf("%d\n",ans);
}

int main()
{
    freopen("LAZER.INP","r",stdin);
    freopen("LAZER.OUT","w",stdout);
    cin>>root.first>>root.second>>radius;
    while(radius>0.0)
    {
        radius*=radius;
        execute();
        cin>>root.first>>root.second>>radius;
    }
    return 0;
}

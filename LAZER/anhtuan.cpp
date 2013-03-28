#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef pair<double, double> dd;
typedef pair<double, dd > d3;

#define fi first
#define se second
#define oo 2000000000
#define Esp 1e-9

int n; 
double sx, sy, r;
vector<dd> point;

double Abs(double k)
{
	if(k < 0) return - k;
	return k;
}

int ccw(int i, int j)
{
	double a1, b1, a2, b2;
	a1 = point[i].fi - sx;
	b1 = point[i].se - sy;
	a2 = point[j].fi - point[i].fi;
	b2 = point[j].se - point[i].se;
	double t = a1 * b2 - a2 * b1;
	if(Abs(t) < Esp) return 0;
	if(t > 0) return -1;
	return 1;
}

void process()
{
	int res = 0;
	for(int i = 0; i < n; i++)
	{
		int l = 1, r = 1;
		for(int j = 0; j < n; j++)
		{
			if(i != j)
			{
				int tmp = ccw(i, j);
				if(tmp == 0)
				{
					l++; r++;
				}
				if(tmp == 1) r++;
				if(tmp == -1) l++;
			}
		}
		res = max(res, max(l, r));
	}
	cout << res << endl;	
}
int main()
{
	freopen("LAZER.INP", "r", stdin);
	freopen("LAZER.OUT", "w", stdout);
	while(cin >> sx >> sy >> r)
	{
		point.clear();
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			double x, y; cin >> x >> y;
			double dist = sqrt(pow(x - sx, 2) + pow(y - sy, 2));
			if(dist <= r)
			point.push_back(dd(x, y));
		}
		n = point.size();	
		process();
	}
	return 0;
}


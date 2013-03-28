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

double x [222], y [222], X, Y, r;
int n;

bool ccw (int i, int j)
{
	double a1 = -x [i];
	double b1 = -y [i];
	double a2 = x [j];
	double b2 = y [j];
	double t = a1 * b2 - a2 * b1;
	
	if (fabs (t) < 1e-8 || t > 0) return 1;
	return 0;
}

int main (int argc, char **argv)
{
	freopen ("LAZER.INP", "r", stdin);
	freopen ("LAZER.OUT", "w", stdout);
	while (cin >> X >> Y >> r, r >= -1e-8)
	{
		cin >> n;
		int j = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> x [i] >> y [i];
			
			if (hypot (x [i] - X, y [i] - Y) < r + 1e-8)
			{
				++j;
				x [j] = x [i] - X;
				y [j] = y [i] - Y;
			}
		}
		
		n = j;
		
		int res = 0;
		for (int i = 1; i <= n; ++i)
		{
			int s = 0;
			for (int j = 1; j <= n; ++j) s += ccw (i, j);
			res = max (res, s);
		}
		
		cout << res << endl;
	}
	return 0;
}

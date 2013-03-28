#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <time.h>

using namespace std;

int main(){
    srand(time(0));
    freopen("4.in","w",stdout);
    cout<<"10\n";
    int i,j,v,x,y,n;
    for (i=1;i<=10;i++){
        n=rand()%100000+1;
        n=100000;
        cout<<"\n";
        cout<<n<<"\n";
        for (j=1;j<=n;j++){
            x=rand()%100000;
            v=rand()%2;
            if (v==1) x=-x;
            y=rand()%100000;
            v=rand()%2;
            if (v==1) y=-y;
            cout<<x<<" "<<y<<"\n";
        }
    }
}

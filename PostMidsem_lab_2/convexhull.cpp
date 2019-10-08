#include <bits/stdc++.h>
using namespace std;
 
struct point 
{ 
    int x;
    int y;
}; 
stack<point> st; 
 point p0;
 void output(stack<point> &S );
 
 point next(stack<point> &S) 
{ 
    point p = S.top(); 
    S.pop(); 
    point res = S.top(); 
    S.push(p); 
    return res; 
}
void swap(point &p1, point &p2) 
{ 
    point temp = p1; 
    p1 = p2; 
    p2 = temp; 
}
int dist(point p1, point p2) 
{ 
    int d = (p1.x - p2.x)*(p1.x - p2.x) + 
          (p1.y - p2.y)*(p1.y - p2.y);
    return d; 
} 
int orientation(point p1, point p2, point p3) 
{ 
    int val = (p2.y - p1.y) * (p3.x - p2.x) - 
              (p2.x - p1.x) * (p3.y - p2.y); 
  
    if (val == 0) return 0;  
    return (val > 0)? 1: 2;  
} 
int compare(const void *vp1, const void *vp2) 
{ 
   point *p1 = (point *)vp1; 
   point *p2 = (point *)vp2; 
  
    
   int a = orientation(p0, *p1, *p2); 
   if (a == 0) 
     return (dist(p0, *p2) >= dist(p0, *p1))? -1 : 1; 
  
   return (a == 2)? -1: 1; 
} 


vector <point> convexHull(point points[], int n)
{
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) ymin = points[i].y, min = i;
    }
    swap(points[0], points[min]);
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(point), compare);
    int m = 1;

    for (int i=1; i<n; i++)
    {
        while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0) i++;
        points[m] = points[i];
        m++;
    }

    if (m < 3) return {};
    stack<point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (int i = 3; i < m; i++)
    {
        while (orientation(next(S), S.top(), points[i]) != 2) S.pop();
        S.push(points[i]);
    }

    vector <point> V;

    while (!S.empty())
    {
        point p = S.top();
        V.push_back(p);
        S.pop();
    }

    return V;
}
  

int main()
{
    point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, 
                      {0, 0}, {1, 2}, {3, 1}, {3, 3}}; 
    int n = sizeof(points)/sizeof(points[0]); 
     vector <point> P;
    P = convexHull(points, n);
	int xmin = P[0].x, min = 0;
	for(int i=0; i<P.size(); i++)
	{
		if(P[i].x < xmin || (P[i].x == xmin && P[i].y < P[min].y)) xmin = P[i].x, min = i;
	}
	cout<<endl<<P.size()<<endl;

	for(int i=min; i<P.size(); i++) cout<<P[i].x<<' '<<P[i].y<<endl;
    for(int i=0; i<min; i++) cout<<P[i].x<<' '<<P[i].y<<endl;
    return 0;
    
    return 0;
}

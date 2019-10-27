#include <bits/stdc++.h>

using namespace std;

int a[1000][1000], vis[1000][1000];
int r, c,col;
int cnt;
void reset_visited(int n, int m) 
{ 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            vis[i][j] = 0; 
} 

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool check(int x, int y)
{
    return (x >= 0 && x < r && y >= 0 &&  y < c);
}

void dfs(int i, int j,int g)
{
    cnt++;
    vis[i][j] = 1;
    for(int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];

        if(check(x, y) && vis[x][y] == 0 && a[x][y] == g)
            dfs(x, y,g);
    }
}

int main()
{
    cin >> r >> c >> col ;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> a[i][j];

    int mx = INT_MIN;
    int colour;
for(int g=0;g<col;g++){
	reset_visited(r,c);
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(vis[i][j] == 0 && a[i][j] == g)
            {
                cnt = 0;
                dfs(i, j,g);

                if(cnt > mx){
                    mx = cnt;
                    colour=g;
                }
            }
        }
    }
}

    cout <<"Largest component of size : "<< mx <<" "<<" , color : "<<colour<<" "<<endl;

    return 0;
}

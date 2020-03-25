#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> mat;
vector<vector<int>> dis;
int R = 0, C = 0;

int DFS(const int r,const int c) 
{
	if (dis[r][c] > 0) return dis[r][c];
	vector<int> dir(4,0);
	//int u = 0, d = 0, l = 0, r = 0;
	if (r > 0 && mat[r-1][c] <mat[r][c]) dir[0] = DFS(r-1,c)+1;
	if (r < R - 1 && mat[r + 1][c] < mat[r][c]) dir[1] = DFS(r+1,c)+1;
	if (c > 0 && mat[r][c - 1] < mat[r][c]) dir[2] = DFS(r, c - 1)+1;
	if (c < C - 1 && mat[r][c + 1] < mat[r][c]) dir[3] = DFS(r,c+1)+1;
	dis[r][c] = *max_element(dir.begin(),dir.end());
	return dis[r][c];
}
int main() 
{
	cin >> R >> C;
	mat = vector<vector<int>>(R,vector<int>(C));
	dis = vector<vector<int>>(R, vector<int>(C));
	for (int r=0;r<R;++r) 
	{
		for (int c=0;c<C;++c) 
		{
			cin >> mat[r][c];
		}
	}
	for (int r = 0; r < R; ++r)
	{
		for (int c = 0; c < C; ++c)
		{
			if (dis[r][c] > 0) continue;
			dis[r][c] = DFS(r,c);
		}
	}
	int maxL = 0;
	for (int r = 0; r < R; ++r)
	{
		for (int c = 0; c < C; ++c)
		{
			maxL = maxL < dis[r][c] + 1 ? dis[r][c] + 1 : maxL;
			//cout << dis[r][c]+1 << ' ';
		}
		//cout << endl;
	}
	cout << maxL << endl;
	system("pause");
	return  0;
}
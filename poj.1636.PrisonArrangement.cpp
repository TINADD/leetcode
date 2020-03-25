#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
关键要对监狱AB中的人员进行冲突分组；
分组后的问题就变成了一个背包问题，采用动态规划的思想
*/
//监狱人员分配
class PriArrange{
private:
	int M=0;
	int asize = 0, bsize = 0;
	vector<vector<bool>>  mapCon; //冲突矩阵
	//dp[i][j]=true:监狱A中的i个人员能和监狱B中的j个人员交换
	vector<vector<bool>>  dp;
	vector<bool> isVisitedA;
	vector<bool> isVisitedB;
	friend int main();
public:
	PriArrange(const int M) :M(M),asize(M), bsize(M)
	{
		mapCon = vector<vector<bool>>(M+1,vector<bool>(M+1,false));
		dp = vector<vector<bool>>(M + 1, vector<bool>(M + 1, false));
		dp[0][0] = true;
		isVisitedA = vector<bool>(M + 1, false);
		isVisitedB = vector<bool>(M + 1, false);
	}
	void DFS(const int i,const bool flag) 
	{
		if (flag) 
		{
			isVisitedA[i] = true;
			++asize;
			for (int p=1;p<=M;++p) 
			{
				if (mapCon[i][p] && !isVisitedB[p]) DFS(p, false);
			}
		}
		else 
		{
			isVisitedB[i] = true;
			++bsize;
			for (int p = 1; p <= M; ++p)
			{
				if (mapCon[p][i] && !isVisitedA[p]) DFS(p, true);
			}
		}
	}
	void kpack() 
	{
		for (int i=M/2;i>=asize;--i) 
		{
			for (int j=M/2;j>=bsize;--j) 
			{
				if (dp[i][j] || dp[i - asize][j - bsize]) dp[i][j] = true;
			}
		}
	}
	void getAns() 
	{
		//如果A、B中都有大于等于M/2个自由成员，就不用考虑冲突成员
		if (asize >= (M / 2) && bsize >= (M / 2)) cout << M / 2 << endl;
		else
		{
			//A中有asize个自由成员，B中有bsize个自由成员
			for (int i = asize; i > 0; --i)
			{
				for (int j = bsize; j > 0; --j)
				{
					dp[i][j] = true;
				}
			}
			/*isVisitedA.resize(M + 1, false);
			isVisitedB.resize(M + 1, false);*/
			isVisitedA = vector<bool>(M + 1, false);
			isVisitedB = vector<bool>(M + 1, false);
			for (int j = 1; j <= M; ++j)
			{
				cout << isVisitedA[j] << ' '<<isVisitedB[j];
				cout << endl;
			}
			cout << endl;
			for (int i = 1; i <= M; ++i)
			{
				if (isVisitedA[i]) continue;
				asize = bsize = 0;
				//先获得A中当前成员i对应的冲突组对儿
				DFS(i,true);
				//通过动态规划获得当前所能交换的人员数
				kpack();
			}
			for (int i=M/2;i>=0;--i) 
			{
				if (dp[i][i]) 
				{
					cout << i << endl;
					break;
				}
			}
		}
	}
};

int main() 
{
	int scenario=0;
	//需要分配的监狱个数
	cin >> scenario;
	while (scenario--) 
	{
		int M = 0, R = 0;
		//M:每个监狱的人数；R：冲突队儿
		cin >> M >> R;
		PriArrange prison(M);
		int x=0, y=0;
		while (R--)
		{
			cin >> x >> y;
			prison.mapCon[x][y] = 1;
			if (!prison.isVisitedA[x]) --prison.asize;
			if (!prison.isVisitedB[y]) --prison.bsize;
			prison.isVisitedA[x] = prison.isVisitedB[y] = true;
		}
		for (int i=1;i<=M;++i) 
		{
			for (int j=1;j<=M;++j) 
			{
				cout << prison.mapCon[i][j] << ' ';
			}
			cout << endl;
		}
		prison.getAns();
	}
	system("pause");
	return  0;
}
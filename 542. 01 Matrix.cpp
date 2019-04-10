class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		vector<vector<int>> ans(matrix);
		int up = 0, left = 0, right = 0, down = 0;
		//先确定当前cell离左上方向上的最近0的距离
		if (ans[0][0] == 1) ans[0][0] = INT_MAX;
		for (int i = 1; i < col; ++i)
		{//row 0  
			if (ans[0][i] == 0) continue;
			ans[0][i] = (ans[0][i - 1] == INT_MAX ? INT_MAX : ans[0][i - 1] + 1);
		}
		for (int j = 1; j < row; ++j)
		{//col 0
			if (ans[j][0] == 0) continue;
			ans[j][0] = (ans[j - 1][0] == INT_MAX ? INT_MAX : ans[j - 1][0] + 1);
		}
		for (int i = 1; i < row; ++i)
		{
			for (int j = 1; j < col; ++j)
			{
				up = (ans[i - 1][j] == INT_MAX ? INT_MAX : ans[i - 1][j] + 1);
				left = (ans[i][j - 1] == INT_MAX ? INT_MAX : ans[i][j - 1] + 1);
				if (ans[i][j] != 0) ans[i][j] = min(up, left);
			}
		}
		//再确定当前cell离右下方的最近0的距离
		for (int i = col - 2; i >= 0; --i)
		{//row 最后一行  
			if (ans[row - 1][i] == 0) continue;
			right = (ans[row - 1][i + 1] == INT_MAX ? INT_MAX : ans[row - 1][i + 1] + 1);
			ans[row - 1][i] = min(ans[row - 1][i], right);
		}
		for (int j = row - 2; j >= 0; --j)
		{//col 最后一列
			if (ans[j][col - 1] == 0) continue;
			down = (ans[j + 1][col - 1] == INT_MAX ? INT_MAX : ans[j + 1][col - 1] + 1);
			ans[j][col - 1] = min(ans[j][col - 1], down);
		}

		for (int i = row - 2; i >= 0; --i)
		{
			for (int j = col - 2; j >= 0; --j)
			{
				right = (ans[i][j + 1] == INT_MAX ? INT_MAX : ans[i][j + 1] + 1);
				down = (ans[i + 1][j] == INT_MAX ? INT_MAX : ans[i + 1][j] + 1);
				if (ans[i][j] != 0) ans[i][j] = min(ans[i][j], min(right, down));
			}
		}
		return ans;
	}
};
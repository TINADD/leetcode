/*
[简单]198.打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
*/
/*
*思路：动态规划
dp[j]表示打劫到房屋j所能获得的最大收益。对于当前房屋j，我们有两个选择：偷/不偷；
在不触发情报的情况下，打劫房屋收益多就打劫房屋j，否则就不打劫
dp[j] = max(dp[j-1],dp[j-2]+nums[j]);
dp[j-1] 表示打劫到房屋j-1所能获得的最大收益，也是不打劫房屋j的时候获得的最大收益；
dp[j-2]+nums[j] 表示打劫房屋j所能获得的最大收益，为了不触发情报，就不能打劫房屋j-1，
所以获得的最大收益就是dp[j-2]+nums[j]
时间复杂度为O(N)
空间复杂度为O(N)，可以进行优化，变为O(1)运行时间会增大
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<1) return 0;
        if(nums.size()==1) return nums[0];
        //dp[j] = max(dp[j-1],dp[j-2]+nums[j]);
       /*vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int j=2;j<nums.size();++j)
        {
            dp[j] = max(dp[j-1],dp[j-2]+nums[j]); 
        }
        return dp[nums.size()-1];*/
		//空间复杂度为O(1),但时间会增多，因为多运行了数值交换部分
        int dp0 = nums[0];
        int dp1 = max(nums[0],nums[1]);
        for(int j=2;j<nums.size();++j)
        {
            int dpj = max(dp1,dp0+nums[j]);
			dp0 = dp1;
			dp1 = dpj;
        }
        return dp1;
    }
};
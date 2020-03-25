/*
给出一个区间的集合，请合并所有重叠的区间。
示例 1:
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
思路1：
遍历区间集合，用一个新的数组存放
思路2：
根据区间的start排序，
*/
bool sort_(vector<int> &v1,vector<int> &v2){
        if(v1[0]==v2[0]) return v1[1]<v2[1]; //return v1[1]<=v2[1] 不通过，会显示引用空指针异常
        return v1[0]<v2[0];  
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return intervals;
        vector<vector<int>> ans;
        //先按区间的start排序
        sort(intervals.begin(),intervals.end(),sort_); 
        //用新的数组存放已经合并好的区间集合
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i){
            //将当前区间和已经合并好的区间进行比较，看能不能和一些区间合并
            //两个不同的区间有2种情况
            int j = ans.size()-1;
            if(intervals[i][0] > ans[j][1]) 
           {
                ans.push_back(intervals[i]);         
            }
            else 
           {
                ans[j][1] = max(intervals[i][1],ans[j][1]);
           }

        }
        return ans;
    }
};
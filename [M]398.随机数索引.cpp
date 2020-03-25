/*
[简单]398.随机数索引
给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。

注意：
数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。

示例:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
solution.pick(3);
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/random-pick-index
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
*思路：
题目要求不能使用太多的额外空间，同时题目给定的数组跟查找函数不是一个，
必须先保存下来，只能使用引用保存，不占用额外的空间。
思路就是遍历数组，因为有重复元素，所以将要查找的目标索引的元素用一个新的数组保存下来，
随机等概率返回新数组中的一个元素（数组里面保存的就是目标值对应的索引下标）。
因为数组可能非常大，所以在用新数组保存对应的下标时不能先开辟一个跟原数组一样大的数组，
而是在遍历的过程中把对应的下标一个一个保存起来（用push_back的方式）。
最后用rand()函数随机一个保存的索引下标
时间复杂度为O(N)
空间复杂度为O(N)
*/
class Solution {
public:
/*
这里的引用要在构造函数的参数后面进行初始化，不能在构造函数体里面进行初始化
引用必须在创建时被初始化，如果换成非引用，vector<int>& temp，可以在函数体内进行初始化，
但是内存，时间都会增多，cpp基础知识需要加强*/
    vector<int>& temp; 
    Solution(vector<int>& nums):temp(nums) {
    }
    
    int pick(int target) {
        vector<int> ans;
        int prei =0;
        for(int i=0;i<temp.size();++i)
        {
            if(temp[i] == target)
            {
                ans.push_back(i);
                ++prei;
            }
        }
        return ans[rand()%prei];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
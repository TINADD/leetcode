int removeElement(vector<int>& nums, int val) {
        if(nums.size()<1) return nums.size();
        int pre_i=0;
        while(pre_i<nums.size() && nums[pre_i] != val )
        {
            ++pre_i;    
        }
        for(int i=pre_i+1;i<nums.size();++i)
        {
            if(nums[i] != val)
            {
                nums[pre_i++] = nums[i];
            }
        }
        return pre_i;
    }
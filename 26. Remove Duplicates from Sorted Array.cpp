int removeDuplicates(vector<int>& nums)
{
	if (nums.size() < 2) return nums.size();
	int pre = nums[0];
	int pre_p = 1;
	for (int i = 1; i < nums.size(); ++i)
	{
		if (pre == nums[i])
		{
			continue;
		}
		else {
			nums[pre_p] = nums[i];
			pre = nums[i];
			++pre_p;
		}
	}
	return pre_p;
}
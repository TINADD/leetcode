class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size() <2) return true;
        bool flag = true;
        int curr=0;
        int pre = curr-1;
        while(curr < bits.size()-1)
        {
            if(bits[curr] == 0)  ++curr;
            else  curr+=2;
        }
        return curr<bits.size()?bits[curr] == 0:0;
    }
};
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
class Solution
{
public:
    int rand10() 
    {
        int col=0,row=0,tot=0;
        do{
            row = rand7();
            col = rand7();
            tot = col+(row-1)*7;
        }while(tot>40);
        return tot%10+1;
    }
};
ps:rand1()服从均匀分布，rand10()也要服从均匀分布
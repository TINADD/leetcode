 int minSteps(int n) {
        if(n <= 1)
            return 0;
        string copy = "A";
        string paste = "A";
        int steps=1;
        while(paste.size()!= n)
        {
            paste+=copy;
            ++steps;
            //判断是否更新copy
            if(paste.size()!= n && (n-paste.size()) % paste.size() == 0) 
            {
                copy = paste;
                ++steps;
            }
        }
        return steps;
    }
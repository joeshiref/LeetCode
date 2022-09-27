class Solution {
public:
    vector<string>operands;
    bool isNum(char c)
    {
        return (c>='0' && c<='9');
    }
    string removeSpaces(string s)
    {
        string res = "";
        for(auto c:s)
        {
            if(c==' ')
                continue;
            res+=c;
        }
        return res;
    }
    bool isOperand(string s)
    {
        return (s=="+" || s=="-" || s=="*" || s=="/");
    }
    vector<string> split(string s)
    {
        vector<string>tmp;
        string collector = "";
        for(auto c:s)
        {
            if(!isNum(c) && collector.size())
            {
                tmp.push_back(collector);
                string op = "";
                op+=c;
                tmp.push_back(op);
                collector = "";
                continue;
            }
            collector+=c;
        }
        if(collector.size())
        {
            tmp.push_back(collector);
            collector = "";
        }
        return tmp;
    }
    int convertToInt(string s)
    {
        return stoi(s);
    }
    string convertToString(int x)
    {
        return to_string(x);
    }
    
    int calculate(string s) {
        
        s = removeSpaces(s);
        operands = split(s);
        
        stack<string>nums,ops;
        
        for(int i=0;i<operands.size(); i++)
        {
            string cur = operands[i];
            if(isOperand(cur))
            {
                if(cur=="*")
                {
                    int first = convertToInt(nums.top());
                    nums.pop();
                    int next = convertToInt(operands[++i]);
                    nums.push(convertToString(first*next));                    
                }
                else if(cur=="/")
                {
                    int first = convertToInt(nums.top());
                    nums.pop();
                    int next = convertToInt(operands[++i]);
                    nums.push(convertToString(first/next));
                }
                else
                    ops.push(cur);
            }
            else
                nums.push(cur);
        }
        // while(!ops.empty())
        // {
        //     string curOp = ops.top();
        //     ops.pop();
        //     if(curOp=="+")
        //     {
        //         int first = convertToInt(nums.top());
        //         nums.pop();
        //         int next = convertToInt(nums.top());
        //         nums.pop();
        //         nums.push(convertToString(next+first));                    
        //     }
        //     else if(curOp=="-")
        //     {
        //         int first = convertToInt(nums.top());
        //         nums.pop();
        //         int next = convertToInt(nums.top());
        //         nums.pop();
        //         nums.push(convertToString(next-first));  
        //     }
        // }
        
        vector<string>remNums,remOps;
        while(!nums.empty())
        {
            remNums.push_back(nums.top());
            nums.pop();
        }
        reverse(remNums.begin(),remNums.end());
        
        while(!ops.empty())
        {
            remOps.push_back(ops.top());
            ops.pop();
        }
        reverse(remOps.begin(),remOps.end());
        
        stack<string>finalInsha2allah;
        finalInsha2allah.push(remNums[0]);
        for(int i=0,j=1;i<remOps.size();i++)
        {
            string curOp = remOps[i];
            if(curOp=="+")
            {
                int first = convertToInt(finalInsha2allah.top());
                int next = convertToInt(remNums[j++]);
                finalInsha2allah.push(convertToString(first+next));                    
            }
            else if(curOp=="-")
            {
                int first = convertToInt(finalInsha2allah.top());
                int next = convertToInt(remNums[j++]);
                finalInsha2allah.push(convertToString(first-next));
            }
        }
        
        
        
        
        return convertToInt(finalInsha2allah.top());
    }
};
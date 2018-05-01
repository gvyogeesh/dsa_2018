/*
https://leetcode.com/problems/ipo/description/

Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given several projects. For each project i, it has a pure profit Pi and a minimum capital of Ci is needed to start the corresponding project. Initially, you have W capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

To sum up, pick a list of at most k distinct projects from given projects to maximize your final capital, and output your final maximized capital.

Example 1:
Input: k=2, W=0, Profits=[1,2,2,3], Capital=[0,0,1,1].

Output: 4

Explanation: Since your initial capital is 0, you can only start the project indexed 0.
             After finishing it you will obtain profit 1 and your capital becomes 1.
             With capital 1, you can either start the project indexed 1 or the project indexed 2.
             Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
             Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.*/


struct profit_compare{
                //(w1,p1)
    bool operator()(pair<int, int>x, pair<int, int>y)
    {
            return x.second < y.second;

    }
};

struct capital_compare {
                //(w1,p1)
    bool operator()(pair<int, int>x, pair<int, int>y)
    {
            return x.first > y.first;

    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue <pair<int, int>, vector<pair<int, int>>,capital_compare > capital_que;
        priority_queue <pair<int, int>, vector<pair<int, int>>,profit_compare > profit_que;
        for(int i=0; i<Profits.size();i++){
            // pair<int, int>temp;
            // temp.first =  Capital[i];
            // temp.second = Profits[i];
            // capital_que.push(temp);
            capital_que.push({Capital[i],Profits[i]});
        }
        // cout << "Initial w is " << W << endl;
        while(k > 0){
            while(capital_que.size() > 0 && W >= capital_que.top().first ){
                // cout << capital_que.top().first << " " << capital_que.top().second << endl;
                profit_que.push(capital_que.top());
                capital_que.pop();
            }
            k--;
            if(profit_que.size() > 0) {
                W = W + profit_que.top().second;
                profit_que.pop();
            }
            // cout << W << endl;
        }

        return W;

    }
};

class Solution {

public:

    int largestRectangleArea(vector<int> &height) {

        stack<int> indexStack;

        int m=0;

        height.push_back(0);

        for (int i=0;i<height.size();i++){

            if (indexStack.empty()||height[i]>height[indexStack.top()]) indexStack.push(i);

            else{
                    int tmp=indexStack.top();indexStack.pop();m=max(m,height[tmp]*(indexStack.empty()?i:i-indexStack.top()-1));
                    i--;
            }

        }

        return m;

    }

};


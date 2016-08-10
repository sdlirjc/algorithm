/*346. Moving Average from Data Stream My Submissions QuestionEditorial Solution
Total Accepted: 4318 Total Submissions: 7537 Difficulty: Easy
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3*/

class MovingAverage {
private:
    int size;
    double sum;
    queue<int>q;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size=size;
        sum=0;
    }
    
    double next(int val) {
        if(q.size()>=size){
            sum-=q.front();
            q.pop();
        }
        q.push(val);
        sum+=val;
        return sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

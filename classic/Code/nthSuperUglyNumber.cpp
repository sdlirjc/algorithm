struct Node{
    int val, index, prime;
    Node(int index, int val, int prime):index(index),val(val),prime(prime){}
    bool operator < (const Node & b) const{
        return val > b.val;
    }
};
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>ugly_nums(n,0);
        ugly_nums[0]=1;
        priority_queue<Node> q;
        for(int i=0;i<primes.size();i++){
            q.push(Node(0,primes[i],primes[i]));
        }
        for(int i=1;i<n;i++){
            Node cur = q.top();
            ugly_nums[i] = cur.val;
            do{
                cur=q.top();
                q.pop();
                cur.val=cur.prime*ugly_nums[++cur.index];
                q.push(cur);
            }while(!q.empty()&&q.top().val == ugly_nums[i]);
        }
        return ugly_nums[n-1];
    }
};



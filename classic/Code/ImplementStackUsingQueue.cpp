class Stack {
private:
    queue<int> * q1=new queue<int>();
    queue<int> * q2=new queue<int>();
    queue<int> * q = q1;
    int _top;
public:
    // Push element x onto stack.
    void push(int x) {
        q->push(x);
        _top=x;
    }

    // Removes the element on top of the stack.
    void pop() {
        if(q->empty()){
            return;
        }else{
            queue<int>*tmp;
            if(q==q1){
                tmp=q2;
            }else{
                tmp=q1;
            }
            int n=q->size();
            for(int i=0;i<n-1;i++){
                tmp->push(q->front());
                _top=q->front();
                q->pop();
            }
            q->pop();
            if(q==q1){
                q=q2;
            }else{
                q=q1;
            }
        }
    }

    // Get the top element.
    int top() {
        return _top;
    }

    // Return whether the stack is empty.
    bool empty() {
        if(q->empty()){
            return true;
        }else{
            return false;
        }
    }
};

class SpecialQueue {

  public:
    queue<int>q;
    multiset<int>st;
    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        st.insert(x);
    }

    void dequeue() {
        // Remove element from the queue
        int f=q.front();
        q.pop();
        auto idx=st.find(f);
        st.erase(idx);
    }

    int getFront() {
        // Get front element
        return q.front();
    }

    int getMin() {
        // Get minimum element
        return *st.begin();
    }

    int getMax() {
        // Get maximum element
        return *prev(st.end());
    }
};
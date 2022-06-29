class MyStack
{
    public:

    queue<int> q1;
    queue<int> q2;
    MyStack() {}

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q1.pop();

        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }

        return ans;
    }

    int top()
    {
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);
        q1.pop();

        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }

        return ans;
    }

    bool empty()
    {

        return q1.empty();
    }
};
#include "iostream"
using namespace std;

class Exception{
    public:
    virtual const char* what() 
    {
        return "Error!!!\n";
    }
};

class StackOverFlowException : public Exception{
    public:
    const char* what() const noexcept
    {
        return "StackOverFlowException - Stack is full";
    }
};

class StackUnderFlowException : public Exception{
    public:
    const char* what() const noexcept
    {
        return "StackUnderFlowException - Stack is Empty";
    }
};
template <typename T>
class Stack{
    private:
    T capacity;
    T count;
    T *arr;
    public:
    Stack(T cap, T count = 0) : capacity(cap) {
        arr = new T[capacity];
    }

    void push()
    {
        if(capacity != count)
        {
            arr[count++];
            cout << "Push Successfully" << endl;
        }
        else
        {
            throw StackOverFlowException();
        }
    }

    void pop()
    {
        if(count == 0)
        {
            throw StackUnderFlowException();
        }
        else
        {
            arr[count--];
            cout << "Pop Successfully" << endl;
        }
    }

    
};

int main()
{
    Stack s1(2);
    try{
        s1.push();
        s1.push();
        s1.push();
    }
    catch (const StackOverFlowException &e)
    {
        cout << e.what() << endl;
    }
    
    try{
        s1.pop();
        s1.pop();
        s1.pop();
    }
    catch(const StackUnderFlowException& e)
    {
        cout << e.what() << endl;
    }
    
}

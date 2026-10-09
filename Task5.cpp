//UsmanSami 545491 CS-D
#include <iostream>
using namespace std;

class ArrayStack
{
    int items[5];
    int top = -1;

public:
    void Push(int value)
    {
        if (IsFull())
        {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }

        items[++top] = value;
        cout << value << " pushed into stack" << endl;
    }

    void Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Removed: " << items[top--] << endl;
    }

    void Peek()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty. Cannot peek" << endl;
            return;
        }

        cout << "Top element: " << items[top] << endl;
    }

    bool IsEmpty()
    {
        if(top == -1){
            return true;
        }
        else{
            return false;
        };
    }

    bool IsFull()
    {
        if(top == 4){
            return true;
        }
        else{
            return false;
        };
    }

    void Display()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack: ";
        for (int i = top; i >= 0; i--)
        {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    ArrayStack s;

    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Push(40);
    s.Push(50);

    s.Display();

    s.Push(60);

    s.Pop();
    s.Peek();
    s.Display();

    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();

    s.Display();
    s.Pop();

    return 0;
}
//Usman Sami 545491 CS-D
#include <iostream>
using namespace std;

class LinkedStack
{
    struct node
    {
        int data;
        node* next;
    };

    node* top = nullptr;

public:
    bool IsEmpty()
    {
        return top == nullptr;
    }

    void Push(int value)
    {
        node* n = new node;
        n->data = value;
        n->next = top;
        top = n;

        cout << value << " pushed into stack" << endl;
    }

    void Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        node* temp = top;
        cout << "Removed: " << temp->data << endl;
        top = top->next;
        delete temp;
    }

    void Peek()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty. Cannot peek" << endl;
            return;
        }

        cout << "Top element: " << top->data << endl;
    }

    void Display()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        node* curr = top;

        cout << "Stack: ";
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    void ClearStack()
    {
        while (!IsEmpty())
        {
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedStack s;
    int choice, value;

    do
    {
        cout << "\n--- Linked Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.Push(value);
                break;

            case 2:
                s.Pop();
                break;

            case 3:
                s.Peek();
                break;

            case 4:
                s.Display();
                break;

            case 5:
                cout << "Thank You!" << endl;
                break;

            default:
                cout << "Invalid choice. Try again!" << endl;
        }

    } while (choice != 5);

    s.ClearStack();

    return 0;
}

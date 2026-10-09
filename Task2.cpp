// UsmanSami 545491 CS-D
#include <iostream>
using namespace std;

// defining class
class DoublyList
{
private:
    typedef struct node
    {
        int data;
        node *next;
        node *prev;

    } *nodeptr;
    nodeptr head = nullptr;
    nodeptr tail = nullptr;
    nodeptr curr;
    nodeptr temp;
    nodeptr temp2;

public:
    // Task1 functions
    void addNode(int newData)
    {
        nodeptr n = new node();
        n->data = newData;
        n->next = nullptr;
        n->prev = tail;

        if (head == nullptr)
        {
            head = n;
        }
        else
        {
            tail->next = n;
        }
        tail = n;
    }

    void printForward()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
        }
        else
        {
            curr = head;
            while (curr != nullptr)
            {
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;
        }
    }

    void printReverse()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
        }
        else
        {
            curr = tail;
            while (curr != nullptr)
            {
                cout << curr->data << " ";
                curr = curr->prev;
            }
            cout << endl;
        }
    }

    void clearList()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
        }
        else
        {
            curr = head;
            while (curr != nullptr)
            {
                temp = curr;
                curr = curr->next;
                temp->next = nullptr;
                temp->prev = nullptr;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;
            cout << "List is cleared!" << endl;
        }
    }

    // Task2 functions
    void insertBefore(int position, int value)
    {

        temp = head;
        for (int i = 1; i < position && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (position < 1 || temp == nullptr)
        {
            cout << "Invalid position" << endl;
        }
        else
        {
            nodeptr n = new node();
            n->data = value;
            temp2 = temp->prev;
            n->prev = temp2;
            n->next = temp;
            temp->prev = n;
            if (temp2 != nullptr)
            {
                temp2->next = n;
            }
            else
            {
                head = n;
            }
        }
    }

    void deleteNode(int value)
    {
        curr = head;

        while (curr != nullptr && curr->data != value)
        {
            curr = curr->next;
        }

        if (curr == nullptr)
        {
            cout << "Value not found!" << endl;
            return;
        }

        temp = curr->next;
        temp2 = curr->prev;

        if (temp2 != nullptr)
        {
            temp2->next = temp;
        }
        else
        {
            head = temp;
        }

        if (temp != nullptr)
        {
            temp->prev = temp2;
        }
        else
        {
            tail = temp2;
        }

        delete curr;
    }
};

int main()
{
    DoublyList l1;
    // taking input from the user for number of integers to be appended in the doubly list
    int num;
    cout << "Enter the number of integers to append in doubly list : ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int newData;
        cout << "Enter the value to be inserted at node " << i + 1 << " : ";
        cin >> newData;
        l1.addNode(newData);
    }
    l1.printForward();
    l1.printReverse();
    // taking input from the user for position and value to be inserted before
    int position;
    int value;
    cout<<"Enter the position of node before which you want to insert value: ";
    cin>>position;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    l1.insertBefore(position, value);
    l1.printForward();
    cout<<"Enter the value of node you want to delete: ";
    cin>>value;
    l1.deleteNode(value);
    l1.printForward();
    l1.clearList();

    return 0;
}
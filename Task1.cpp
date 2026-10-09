// UsmanSami 545491 CS-D
#include <iostream>
using namespace std;

//defining class
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

public:
    //first i used traversing technique using tail pointer but i got a better way to insert
    // which reduced the time complexity.
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
};

int main()
{
    DoublyList l1;
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
    l1.clearList();

    return 0;
}
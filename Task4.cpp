//UsmanSami 545491 CS-D
#include <iostream>
using namespace std;

class CircularList
{
    typedef struct node
    {
        int data;
        node *next;
    } *nodeptr;
    nodeptr head=nullptr;
    nodeptr tail=nullptr;
    nodeptr curr;
    public:
    // task3 functions
    void addNode(int value)
    {
        nodeptr n = new node;
        n->data = value;
        if (head == nullptr)
        {
            head = n;
            tail = n;
            n->next = head;
        }
        else
        {
            tail->next = n;
            tail = n;
            n->next = head;
        }
    }
    void printList()
    {
        curr = head;
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            do
            {
                cout << curr->data << " ";
                curr = curr->next;
            } while (curr != head);
            cout << endl;
        }
    }
    void countNodes()
    {
        int count = 0;
        curr = head;
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            do
            {
                count++;
                curr = curr->next;
            } while (curr != head);
            cout << "Number of nodes in the list: " << count << endl;
        }
    }
    void clearList(){
        curr = head;
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            do
            {
                nodeptr temp = curr;
                curr = curr->next;
                delete temp;
            } while (curr != head);
            head = nullptr;
            tail = nullptr;
            cout << "List cleared" << endl;
        }
    }
    // new functions for task4
    void deleteNode(int value)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    curr = head;
    nodeptr prev = tail;

    do
    {
        if (curr->data == value)
        {
            if (curr == head && curr == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                prev->next = curr->next;

                if (curr == head)
                    head = curr->next;

                if (curr == tail)
                    tail = prev;
            }

            delete curr;
            return;
        }

        prev = curr;
        curr = curr->next;

    } while (curr != head);

    cout << "Value not found" << endl;
}
};
    int main()
    {
        CircularList l1;
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
        l1.printList();
        l1.countNodes();
        int value;
        cout<<"Enter the value to be deleted: ";
        cin>>value;
        l1.deleteNode(value);
        l1.printList();
        l1.clearList();
        return 0;
    }

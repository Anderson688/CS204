#include <iostream>
using namespace std;

class node
{
    public:
        int x;
        int y;
        node* next;
};

node* head = NULL;

void AddFirst(int a, int b)
{
    node* new_node = new node();
    new_node->x = a;
    new_node->y = b;
    new_node->next = head;
    head = new_node;
}

void DelFirst()
{
    if(head == NULL)
        cout << -1 << endl;
    else
    {
        node* temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
}

// Used in Del() function.
void dlt(node* ptr, node* prev)
{
    prev->next = ptr->next;
    delete ptr;
}

void Del(int a, int b)
{
    int counter = 0;
    node *prev, *temp = head;
    if(temp == NULL)
        cout << -1 << endl;
    while(temp != NULL)
    {
        /* There can be more than one node with same value of x and y,
           therefore deleting all. */
        if(temp->x == a && temp->y == b)
        {
            if(temp == head)
                DelFirst();
            else
                dlt(temp, prev);
            counter++;
        }
        prev = temp;
        temp = temp->next;
    }
    if(counter == 0)
        cout << -1 << endl;
    delete temp, prev;
}

void Search(double d)
{
    int counter = 0;
    node* temp = head;
    while(temp != NULL)
    {
        if((double)(temp->x)*(double)(temp->x) + (double)(temp->y)*(double)(temp->y) <= d*d)
            counter++;
        temp = temp->next;
    }
    delete temp;
    if(counter == 0)
        cout << -1;
    else
        cout << counter;
    cout << endl;
}

void Search(int a, int b)
{
    node* temp = head;
    while(temp != NULL)
    {
        if((temp->x == a) && (temp->y == b))
        {
            cout << "True\n";
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL)
        cout << "False\n";
    temp = NULL;
}

void Length()
{
    int l = 0;
    node* temp = head;
    while(temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    cout << l << endl;
}

int main()
{
    int T, decider, x, y;
    cin >> T;
    while(T--)
    {
        cin >> decider;
        switch(decider)
        {
            case 1:
                cin >> x >> y;
                AddFirst(x, y);
                break;
            case 2:
                DelFirst();
                break;
            case 3:
                cin >> x >> y;
                Del(x, y);
                break;
            case 4:
                double d;
                cin >> d;
                Search(d);
                break;
            case 5:
                cin >> x >> y;
                Search(x, y);
                break;
            case 6:
                Length();
                break;
            default:
                cout << "Invalid input.\n";
        }
    }
    return 0;
}


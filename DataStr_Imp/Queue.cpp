// Program To Implement Queue using Linked List

#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int info;
    node *link;
}*front, *rear;

class queue_list
{
    public:
        void insert(int);
        void display();
        void del();
        queue_list()
        {
            front = NULL;
            rear = NULL;
        }
};

int main()
{
    int choice, item;
    queue_list ql;
    while(1)
    {
        cout << "Operations on Queue" << endl;
        cout << "1.Insert Element into the Queue" << endl;
        cout << "2.Delete Element from the Queue" << endl;
        cout << "3.Traverse the Queue" << endl;
        cout << "4.Quit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter value to be inserted into the queue: ";
                cin >> item;
                ql.insert(item);
                break;
            case 2:
                ql.del();
                break;
            case 3:
                ql.display();
                break;
            case 4:
                exit(1);
                break;
            default:
                cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}

void queue_list::insert(int item)
{
    node *tmp;
    tmp = new(struct node);
    tmp->info = item;
    tmp->link = NULL;
    if(front == NULL)
        front = tmp;
    else
        rear->link = tmp;
    rear = tmp;
}

void queue_list::del()
{
    node *tmp;
    if(front == NULL)
        cout << "Queue Underflow" << endl;
    else
    {
        tmp = front;
        cout << "Element Deleted: " << tmp->info << endl;
        front = front->link;
        free(tmp);
    }
}

void queue_list::display()
{
    node *ptr;
    ptr = front;
    if(front == NULL)
        cout << "Queue is empty" << endl;
    else
    {
        cout << "Queue elements : ";
        while(ptr != NULL)
        {
            cout << ptr->info << " ";
            ptr = ptr->link;
        }
        cout << endl;
    }
}

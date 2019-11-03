//queue
//adt
//enqueue() − add an item to the queue
//dequeue() − remove/access an item from the queue.

#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int key;
    node* next;
};

 class que
{
public:
    node* start;
    node* rear;
};

node* newnode(int k)
{
    node* temp= new node();
    temp->key=k;
    temp->next=NULL;
    return temp;
}



void enqueue(que* q,int k)
{
    node *temp=newnode(k);

    if(q->rear==NULL)
    {
        q->start=temp;
        q->rear=temp;
        return;
    }
    q->rear->next=temp;
    q->rear=temp;
    return;

}

node* dequeue(que*q)
{
    if(q->start==NULL)
        return NULL;
    node* temp=q->start;


    q->start=q->start->next;
    if(q->start==NULL)
        q->rear=NULL;
    return temp;
}



int main()
{
    que* q= new que();
    q->start=NULL;
    q->rear=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        enqueue(q,a);
    }

    node* t=dequeue(q);
    cout<< t->key<<endl;
    return 0;
}

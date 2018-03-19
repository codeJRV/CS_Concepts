//
// Created by jrv on 3/18/18.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node{
   int data;
   struct node* next;
};

void BadAppend(struct node** headRef, int newData)
{
   //Problem with bad append is that it doesnt care what the current->next already has.
   //Can leave a bunch of dangling pointers.
   struct node* current = *headRef;
   current->next = new node();
   current->next->data = newData;

}

void Append(struct node** head, int newData)
{
   struct node* current = *head;
   for(; current->next!=NULL; current=current->next);

   current->next = new node();
   current->next->data = newData;
//    cout<<endl<<current->data<<endl;
}


void Push(struct node**head, int newData)
{
   struct node* newHead = new node();
   newHead->next = *head;
   newHead->data = newData;
   *head = newHead;

}

int length(struct node* head)
{
   int count = 0;
   for (struct node* current = head; current!=NULL; current=current->next) count++;
   return count;
}

struct node* BuildOneTwoThree()
{
   struct node* one = new node();
   one->data = 1;
   struct node* two = new node();
   two->data = 2;
   struct node* three = new node();
   three->data = 3;

   one->next = two;
   two->next = three;
   three->next = NULL;

   return one;



}

void Print(struct node** head)
{

   for (struct node* current = *head; current!=NULL; current=current->next)
       if(current->next)
           cout<<current->data<<"->";
       else
           cout<<current->data;
   cout<<endl;
}


int main()
{
   struct node* head = BuildOneTwoThree();

   int i = 5;
   struct node* current = head->next->next;
   while(i--)
   {
       BadAppend(&current,i);
       current = current->next;

   }

   cout<<head->data<<endl;

   Push(&head, 22);
   Append(&head,15);
   Print(&head);
   cout<<length(head);



}
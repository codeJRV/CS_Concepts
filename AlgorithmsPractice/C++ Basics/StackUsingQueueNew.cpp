//
// Created by jrv on 3/18/18.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class MyStack {
public:
   /** Initialize your data structure here. */
   MyStack() {

   }

   /** Push element x onto stack. */
   void push(int x) {
   int s = q.size();

       q.push(x);
       while(s--)
       {
           q.push(q.front());
           q.pop();
       }
   }

   /** Removes the element on top of the stack and returns that element. */
   int pop() {
       int val =  q.front();
       q.pop();
       return val;

   }

   /** Get the top element. */
   int top() {
       return q.front();
   }

   /** Returns whether the stack is empty. */
   bool empty() {
       return q.empty();
   }

private:
   queue<int> q;
};


int main()
{

}
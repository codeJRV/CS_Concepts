////
//// Created by jrv on 3/18/18.
////
//
//#include <iostream>
//#include <bits/stdc++.h>
//
//class MyQueue {
//public:
//    /** Initialize your data structure here. */
//    MyQueue(): top(-1), size(-1) { }
//    ~MyQueue(){
//        while (!OldestOnTop.empty())
//            OldestOnTop.pop();
//        while (!NewestOnTop.empty())
//            NewestOnTop.pop();
//    }
//
//    /** Push element x to the back of queue. */
//    void push(int x) {
//        NewestOnTop.push(x);
//    }
//
//    /** Removes the element from in front of queue and returns that element. */
//    int pop() {
//
//        int val;
//        if(!OldestOnTop.empty()) {
//            val = OldestOnTop.top();
//            OldestOnTop.pop();
//        }
//        else
//        {
//            while(!NewestOnTop.empty())
//            {
//                OldestOnTop.push(NewestOnTop.top());
//                NewestOnTop.pop();
//
//            }
//            val = OldestOnTop.top();
//            OldestOnTop.pop();
//        }
//        return val;
//
//    }
//
//    /** Get the front element. */
//    int peek() {
//
//        if(!OldestOnTop.empty())
//            return OldestOnTop.top();
//        else
//        {
//            while(!NewestOnTop.empty())
//            {
//                OldestOnTop.push(NewestOnTop.top());
//                NewestOnTop.pop();
//
//            }
//            return OldestOnTop.top();
//        }
//
//    }
//
//    /** Returns whether the queue is empty. */
//    bool empty() {
//        return (OldestOnTop.empty() && NewestOnTop.empty() );
//    }
//
//private:
//    std::stack<int> OldestOnTop;
//    std::stack<int> NewestOnTop;
//    int top;
//    int size;
//};
//
///**
// * Your MyQueue object will be instantiated and called as such:
// * MyQueue obj = new MyQueue();
// * obj.push(x);
// * int param_2 = obj.pop();
// * int param_3 = obj.peek();
// * bool param_4 = obj.empty();
// */
//
//using namespace std;
//
//int main()
//{
//
//    MyQueue *obj = new MyQueue();
//    obj->push(1);
//    obj->push(2);
//    obj->push(3);
//    obj->push(4);
//
//    int param_2 = obj->pop();
//    cout<<param_2<<endl;
//    int param_3 = obj->peek();
//    cout<<param_3<<endl;
//    int poo = obj->pop();
//    cout<<"poo:"<<poo<<endl;
//    bool param_4 = obj->empty();
//    if(param_4)
//        cout<<"empty";
//
//    return 0;
//
//
//}
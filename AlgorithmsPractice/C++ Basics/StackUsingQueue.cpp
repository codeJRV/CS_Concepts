#include <iostream>
#include<queue>

using namespace std;
class Stack
{

queue<int> q1,q2;

int curr_size;

public:
	Stack()
	{
		curr_size = 0;
	};

	void push(int x);
	void pop();
	int top();
	int size();

};

void Stack::push(int x)
{
	curr_size++;
	q2.push(x);
	cout<<x;
	while (!q1.empty())
	{

		q2.push(q1.front());
		q1.pop();
	}
		//swap the names of the two queues
		queue<int> temp;
		temp = q1;
		q1  = q2;
		q2 = temp;

		//cout<<" q1 "<< q1.front() << " q2 "<<q2.front()<<endl;

	
}

void Stack::pop()
{

	if (q1.empty())
		return;
	q1.pop();
	curr_size--;
}

int Stack::top()
{
	if(q1.empty())
		return -1;

	return q1.front();
}

int Stack::size()
{
	return curr_size;
}

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout<<" curr_size : "<<s.size()<<endl;
	cout<<" top : "<<s.top()<<endl;
	s.pop();
	cout<<" top : "<<s.top()<<endl;
	s.pop();
	cout<<" top : "<<s.top()<<endl;
	cout<<" curr_size : "<<s.size()<<endl;


	return 0;
}
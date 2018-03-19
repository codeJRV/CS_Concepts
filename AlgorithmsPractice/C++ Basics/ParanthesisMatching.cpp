#include <iostream>
#include<string>
#include<stack>
#include<bits/stdc++.h>

using namespace std;

bool ParMatch ( char expr[] )
{
	stack<char> s;
	char a;

	for (int i = 0; i <strlen(expr); i++ )
	{
		if(expr[i] == '[' || expr[i] == '(' || expr[i] == '{')
			{
				//cout<<expr[i]<<" ";
				s.push(expr[i]);
			}
		else
		{
			if (s.size()>0)
			{
			switch(expr[i])
			{
				case ']':
							a  = s.top();
							s.pop();
							if(a !='[')
								{ cout<<"Imbalanced"<<endl;
								return false;
								}
							break;

				case '}':
							a  = s.top();
							s.pop();
							if(a !='{')
								{ cout<<"Imbalanced"<<endl;
								return false;
								}
							break;
				case ')':
							a  = s.top();
							s.pop();
							if(a !='(')
								{ cout<<"Imbalanced"<<endl;
								return false;
								}
							break;

			}
		}
		
		}
	}

	if(s.empty())
		return true;
	else 
		return false;

	return false;


}

int main()
{
	char expr[] =  "[][]{{{((()))}}}{(}[]";

	bool check = ParMatch(expr);

	if (check)
		cout<<"Yaay\n";
}
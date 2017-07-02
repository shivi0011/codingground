#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class node{
	vector<T> data;

public:
	void push(T element);

	void pop();

	T top();
};



template <class T>
void node<typename T>:: push(T element)
{
	data.push_back(element);
}

template <class T>
void node <typename T>::pop()
{
	if(data.size() <= 0)
	{
		cout << ("Stack is empty");
	}
	else
	 data.pop_back();
}

template <class T>
T node <typename T>::top()
{
	if(data.size() <= 0)
	{
		cout << ("Stack is empty");
		return 0;
	}
	else
	{
		return data.back();
	}
	
}




int mainr()
{

	int found = 0;
	try{
		node <char> t;

		char str[] = "{}{{{{}{}}{}";

		for(int i = 0; i < strlen (str) ; i++)
		{
			t.push(str[i]);
		}

		bool search_back = false;
	char i;

		while( i =  t.top() )
		{
			if(search_back == true)
			{
				if(i == '{')
				{
					search_back = false;

					++found;
				}
				t.pop();
				continue;
			}

			if( i == '}')
				search_back = true;
			t.pop();
		}

	}
	catch(std::out_of_range())
	{
		cout<<"Exception caught";
	}
	
	return 0;
}

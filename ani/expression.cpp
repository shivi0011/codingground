#include<iostream>
#include<vector>
using namespace std;

template < class T>
class stack{

	

};

int maintftg()
{
	vector<int> value;
	vector <char> operand;


	char expr[] = "(2+3)*5";
	int sum = 0;
	for(int i =0 ; i< strlen(expr);i++)
	{
		if(operand.size() == 1 && isdigit(expr[i]))
		{
			char opera = operand.back();
			int val = value.back();
			int secval = expr[i] - 48;
			if(opera == '+')
			{
				sum = secval + val;
			}

			if(opera == '-')
			{
				sum = val - secval;
			}
			if(opera == '*')
			{
				sum = val * secval;
			}
			if(opera == '/')
			{
				sum = val / secval;
			}
			operand.pop_back();
			value.pop_back();
			value.push_back(sum);
			continue;
		}

		if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
		{
			operand.push_back(expr[i]);
		}

		if(isdigit(expr[i]))
		{
			value.push_back(expr[i] - 48);
		}
	}
return 0;

}

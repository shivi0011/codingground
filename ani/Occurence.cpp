#include <iostream>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

int mainvvv()
{
	char str[] = "XXDDCAABBAACCDC"; 
	unordered_set<char> s;
	unordered_map<char ,int> mymap;

	for(int i = 0; i< strlen (str) ; i++)
	{

		/*unordered_set<char>::iterator itr= s.find(str[i]);
		if(itr != s.end())*/
			s.insert(str[i]);
	}

	for(int i = 0; i< strlen (str) ; i++)
	{

		/*unordered_set<char>::iterator itr= s.find(str[i]);
		if(itr != s.end())*/

		pair<unordered_map<char,int>::iterator,bool> ret;
		ret =  mymap.insert(make_pair(str[i], 1));
		if(ret.second == false)
		{
			ret.first->second++;
		}
		
	}

	int high =0;
	unordered_map<char,int>::iterator itr = mymap.begin();
	unordered_map<char, int> highest;
	for(itr;itr!= mymap.end();itr++)
	{
		if( high <=  itr->second)
		{
			high= itr->second;
		}
	}

	return 0;
}

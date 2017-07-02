#include <iostream>
using namespace std;


int maiddn()
{
	int arr[] ={6,5,4,4,8,9,1,2};

	int size = sizeof(arr)/sizeof(arr[0]);

	int pos = arr[size-2];
	int length = arr[size-1];

	while(length > 0)
	{
		for(int i = pos; i< size-3 ; i++)
		{
			arr[i] = arr[i+1];
		}
		length--;
	}

	for(int i = 0; i < (size -3) - arr[size-1] ; i++ )
	{
		cout<<arr[i];
	}

	return 0;
}

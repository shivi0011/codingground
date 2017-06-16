Given an array A[] and a number x, check for pair in A[] with sum as x[
#include <stdio.h>
#define MAX 100000
 
void printPairs(int arr[], int arr_size, int sum)
{
  int i, temp;
  bool binMap[MAX] = {0}; /*initialize hash map as 0*/
 
  for (i = 0; i < arr_size; i++)
  {
      temp = sum - arr[i];
      if (temp >= 0 && binMap[temp] == 1)
         printf("Pair with given sum %d is (%d, %d) \n",sum, arr[i], temp);
      binMap[arr[i]] = 1;
  }
}
/* Driver program to test above function */
int main()
{
    int A[] = {1, 4, 45, 6, 10, 8};
    int n = 16;
    int arr_size = sizeof(A)/sizeof(A[0]);
 
    printPairs(A, arr_size, n);
 
    getchar();
    return 0;
}
]
Majority Element[	-- which appears more than n/2 times -- 
findCandidate(a[], size)
1.  Initialize index and count of majority element
     maj_index = 0, count = 1
2.  Loop for i = 1 to size � 1
    (a) If a[maj_index] == a[i]
          count++
    (b) Else
        count--;
    (c) If count == 0
          maj_index = i;
          count = 1
3.  Return a[maj_index]

 Check if the element obtained in step 1 is majority

printMajority (a[], size)
1.  Find the candidate for majority
2.  If candidate is majority. i.e., appears more than n/2 times.
       Print the candidate
3.  Else
       Print "NONE"
]
Find the Number Occurring Odd Number of Times[
int getOddOccurrence(int ar[], int ar_size)
{
     int i;
     int res = 0; 
     for (i=0; i < ar_size; i++)     
        res = res ^ ar[i];
      
     return res;
}]
Kadanes algo (max subarray sum)Largest SUM Contiguous SUBARRAY -- [
int maxSubArraySum(int a[], int size)
{
    int ms = 0, maxE = 0;
    for (int i = 0; i < size; i++)
    {
        maxE = maxE + a[i];
        if (maxE < 0)
            maxE = 0;
        if (ms < maxE)
            ms = maxE;
    }
    return ms;
}
or
int maxSubArraySum(int a[], int size)
{
   int ms = a[0];
   int maxE = a[0];
 
   for (int i = 1; i < size; i++)
   {
        maxE = max(a[i], maxE+a[i]);
        ms = max(ms, maxE);
   }
   return ms;
}

]
Find the Missing Number[
METHOD 2(Use XOR)

  1) XOR all the array elements, let the result of XOR be X1.
  2) XOR all numbers from 1 to n, let XOR be X2.
  3) XOR of X1 and X2 gives the missing number.
  
  OR
  
int getMissingNo (int a[], int n)
{
    int i, total;
    total  = (n+1)*(n+2)/2;   //one number is missing so we've to include its count also
    for ( i = 0; i< n; i++)
       total -= a[i];
    return total;
}
]
Search an element in a sorted and pivoted array
Merge an array of size n into another array of size m+n[    ---Dooo---
#include<stdio.h>
#include<stdlib.h>
#define NA -1
int shiftValues(int mPlusN[], int m)
{
	int i,j;
	j=m-1;
	for(i=m-1;i>=0;i--)
	{
		if(mPlusN[i]!= NA)
		{
			mPlusN[j] = mPlusN[i];
			j--;
		}
	}
	return 0;
}
void mergeArray(int mPlusN[],int N[],int m,int n)
{
int i=n;  //n is the size of N[]
int j=0;
int k=0;

	for(k=0;k<m;k++)
	{
		if(( i<m &&  mPlusN[i]<=N[j]) || (j==n))
		{
			mPlusN[k] = mPlusN[i];
			i++; 
		}
		
		else
		{
			mPlusN[k] = N[j];
			j++;	
		}
	}
}
int main()
{
int N[]={3,5,6,9,100};
int mPlusN[]={2,NA,7,NA,8,NA,NA,10,NA,15};
int m = sizeof(mPlusN)/sizeof(mPlusN[0]);
int n = sizeof(N)/sizeof(N[0]);
shiftValues(mPlusN,m);
mergeArray(mPlusN,N,m,n);
for(int i=0;i<m;i++)
printf("%d ",mPlusN[i]);
return 0;
}
]
Median of two sorted arrays of different sizes  -- ***
Median of two sorted arrays[   ---Doo---
int getMedian(int a[], int b[], int n)
{
    /* return -1  for invalid input */
    if (n <= 0)
        return -1;
    if (n == 1)
        return (a[0] + b[0])/2;
    if (n == 2)
        return (max(a[0], b[0]) + min(a[1], b[1])) / 2;
 
    int m1 = median(a, n); /* get the median of the first array */
    int m2 = median(b, n); /* get the median of the second array */
 
    /* If medians are equal then return either m1 or m2 */
    if (m1 == m2)
        return m1;
 
    /* if m1 < m2 then median must exist in a[m1....] and        ie. include chhote se aage wale and bade se peechhe wale
        b[....m2] */
    if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(a + n/2 - 1, b, n - n/2 +1);
        return getMedian(a + n/2, b, n - n/2);
    }
 
    /* if m1 > m2 then median must exist in a[....m1] and
        b[m2...] */
    if (n % 2 == 0)
        return getMedian(b + n/2 - 1, a, n - n/2 + 1);
    return getMedian(b + n/2, a, n - n/2);
}
 
/* Function to get median of a sorted array */
int median(int arr[], int n)
{
    if (n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    else
        return arr[n/2];
}
 
/* Driver program to test above function */
int main()
{
    int a[] = {1, 2, 3, 6};
    int b[] = {4, 6, 8, 10};
    int n1 = sizeof(a)/sizeof(a[0]);
    int n2 = sizeof(b)/sizeof(b[0]);
    if (n1 == n2)
        printf("Median is %d", getMedian(a, b, n1));
    else
        printf("Doesn't work for arrays of unequal size");
    return 0;
}
]
Write a program to reverse an array[
void rvereseArray(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];   
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }   
}     
RCURSIVE
void rvereseArray(int arr[], int start, int end)
{
   int temp;
   if (start >= end)
     return;
   temp = arr[start];   
   arr[start] = arr[end];
   arr[end] = temp;
   rvereseArray(arr, start+1, end-1);   
}     
using Vectors in C++
==========================
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
vector<int> v;

for(int i=1;i<=10;i++)
v.push_back(i);

reverse(v.begin(),v.end());

vector<int>::iterator it;
for(it=v.begin(); it!=v.end(); ++it)
cout << *it << " ";

cout<< endl;
return 0;
}
]
Program for 1D array rotation [ DONE
	int reverse(int a[],int start,int end)
	{
		int temp;
		while(start < end)
		{
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;

		start++;
		end--;
		}
	}

	int leftrotate(int a[],int n,int d)
	{
	//we divided array in 2 parts with d number of elements and with n-d elements
		reverse(a,0,d-1);	//reverse A
		reverse(a,d,n-1);	//reverse B
		reverse(a,0,n-1);	//reverse all
	}

	int rightrotate(int a[],int n,int d)
	{
	//we divided array in 2 parts with d number of elements and with n-d elements
		reverse(a,0,n-1);	//reverse all
		reverse(a,d,n-1);	//reverse B
		reverse(a,0,d-1);	//reverse A
	}

	int main()
	{
	int a[] = {1,2,3,4,5,6,7};	
	int size = sizeof(a)/sizeof(a[0]);
	int d;
	printf("Enter by what value u want to rotate: ");
	scanf("%d",&d);
	printf("LEFT ROTATION:::\n");
	leftrotate(a,size,d);
	}
]
Reversal algorithm for array rotation-- SAME AS ABOVE
Block swap algorithm for array rotation-- SAME AS ABOVE
Maximum sum such that no two elements are adjacent [*
Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array. So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).

int FindMaxSum(int arr[], int n)
{
  int incl = arr[0];
  int excl = 0;
  int new_excl;
 
  for (int i = 1; i < n; i++)
  {
     /* current max excluding i */
     new_excl = max(incl, excl);
 
     /* current max including i */
     incl = excl + arr[i];		//ie. pichhla wala exclusive and current ka sum
     excl = new_excl;			//pichhli max value..chaahe kisi ki bhi ho incl ki ya excl ki kyunki current value to add kr nai rahe
  }
 
   /* return max of incl and excl */
   return max(incl, excl);
}
 int max(int a, int b) 
 {return a > b ? a : b; }
 
/* Driver program to test above function */
int main()
{
  int arr[] = {5, 5, 10, 100, 10, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("%d \n", FindMaxSum(arr, 6));
  return 0;
}
]
Leaders in an array[
 An element is leader if it is greater than all the elements to its right side. And the rightmost element is always a leader. For example in the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.
		int maxE = a[n-1];  //last element will always be Leader
        for(i=n-2;i>=0;i--)
        {
            if(a[i]>maxE)
            {
                maxE = a[i];
            }
            else a[i]=-1;
        }
        for(i=0;i<n;i++)
		{	
            if(a[i]!=-1)
            printf("%d ",a[i]);
		}
]
Sort elements by frequency | Set 1 -- **
Count Inversions in an array[ ---Dooo--
Inversion Count for an array indicates � how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
]
Two elements whose sum is closest to zero
Find the smallest and second smallest element in an array[
A Better Solution is to scan the array twice. In first traversal find the minimum element. Let this element be x. In second traversal, find the smallest element greater than x. Time complexity of this solution is O(n).
The above solution requires two traversals of input array.

An Efficient Solution can find the minimum two elements in one traversal. Below is complete algorithm.
Algorithm:
1) Initialize both first and second smallest as INT_MAX
   first = second = INT_MAX
2) Loop through all the elements.
   a) If the current element is smaller than first, then update first 
       and second. 
   b) Else if the current element is smaller than second then update 
    second

	#include <limits.h> /* For INT_MAX */ 
	void print2Smallest(int arr[], int arr_size)
	{
		int i, first, second;
	 
		/* There should be atleast two elements */
		if (arr_size < 2)
		{
			printf(" Invalid Input ");
			return;
		}
		first = second = INT_MAX;
		for (i = 0; i < arr_size ; i ++)
		{
			/* If current element is smaller than first 
			   then update both first and second */
			if (arr[i] < first)
			{
				second = first;
				first = arr[i];
			}
	 
			/* If arr[i] is in between first and second 
			   then update second  */
			else if (arr[i] < second && arr[i] != first)
				second = arr[i];
		}
		if (second == INT_MAX)
			printf("There is no second smallest element\n");
		else
			printf("The smallest element is %d and second "
				   "Smallest element is %d\n", first, second);
	}
]
Check for Majority Element in a sorted array[
** Whenever you encounter sorted array...most of the time TC should be O(logn) **
METHOD 1 (Using Linear Search)
================================
Linearly search for the first occurrence of the element, once you find it (let at index i), check element at index i + n/2. If element is present at i+n/2 then return 1 else return 0.
bool isMajority(int arr[], int n, int x)
{
    int i;
    /* get last index according to n (even or odd) */
    int last_index = n%2? (n/2+1): (n/2);					//** good point to remember
 
    /* search for first occurrence of x in arr[]*/
    for (i = 0; i < last_index; i++)
    {
        /* check if x is present and is present more than n/2
           times */
        if (arr[i] == x && arr[i+n/2] == x)
            return 1;
    }
    return 0;
}

Using Moore�s Voting Algorithm
findCandidate(a[], size)
1.  Initialize index and count of majority element
     maj_index = 0, count = 1
2.  Loop for i = 1 to size � 1
    (a) If a[maj_index] == a[i]
          count++
    (b) Else
        count--;
    (c) If count == 0
          maj_index = i;
          count = 1
3.  Return a[maj_index]
]
Maximum and minimum of an array using minimum number of comparisons
Segregate 0s and 1s in an array[
Method 1 (Count 0s or 1s) 
Thanks to Naveen for suggesting this method.
1) Count the number of 0s. Let count be C.
2) Once we have count, we can put C 0s at the beginning and 1s at the remaining n � C positions in array.
Time Complexity: O(n)

The method 1 traverses the array two times. Method 2 does the same in a single pass.
Method 2 (Use two indexes to traverse)
Maintain two indexes. Initialize first index left as 0 and second index right as n-1.

Do following while left < right
a) Keep incrementing index left while there are 0s at it
b) Keep decrementing index right while there are 1s at it
c) If left < right then exchange arr[left] and arr[right]
]
k largest(or smallest) elements in an array | added Min Heap method
Maximum difference between two elements
Union and Intersection of two sorted arrays
Floor and Ceiling in a sorted array
A Product Array Puzzle
Segregate Even and Odd numbers[
Algorithm: segregateEvenOdd()
1) Initialize two index variables left and right:  
            left = 0,  right = size -1 
2) Keep incrementing left index until we see an odd number.
3) Keep decrementing right index until we see an even number.
4) If lef < right then swap arr[left] and arr[right]
]
Find the two repeating elements in a given array[***
You are given an array of n+2 elements. All elements of the array are in range 1 to n. And all elements occur once except two numbers which occur twice. Find the two repeating numbers.

For example, array = {4, 2, 4, 5, 2, 3, 1} and n = 5

The above array has n + 2 = 7 elements with all elements occurring once except 2 and 4 which occur twice. So the output should be 4 2.

void printRepeating(int arr[], int size)
{
  int xor = arr[0]; /* Will hold xor of all elements */
  int set_bit_no;  /* Will have only single set bit of xor */
  int i;
  int n = size - 2;
  int x = 0, y = 0;
   
  /* Get the xor of all elements in arr[] and {1, 2 .. n} */
  for(i = 1; i < size; i++)
    xor ^= arr[i];  
  for(i = 1; i <= n; i++)
    xor ^= i;   
 
  /* Get the rightmost set bit in set_bit_no */
  set_bit_no = xor & ~(xor-1);
 
  /* Now divide elements in two sets by comparing rightmost set
   bit of xor with bit at same position in each element. */
  for(i = 0; i < size; i++)
  {
    if(arr[i] & set_bit_no)
      x = x ^ arr[i]; /*XOR of first set in arr[] */
    else
      y = y ^ arr[i]; /*XOR of second set in arr[] */
  }
  for(i = 1; i <= n; i++)
  {
    if(i & set_bit_no)
      x = x ^ i; /*XOR of first set in arr[] and {1, 2, ...n }*/
    else
      y = y ^ i; /*XOR of second set in arr[] and {1, 2, ...n } */
  }
   
  printf("\n The two repeating elements are %d & %d ", x, y);
}     
 
 
int main()
{
  int arr[] = {4, 2, 4, 5, 2, 3, 1};
  int arr_size = sizeof(arr)/sizeof(arr[0]);  
  printRepeating(arr, arr_size);
  getchar();
  return 0;
}
]
Find even occurring elements in an array of limited range[  --bit-magic--
/*given that range of numbers is from 0 to 63 only ie. we can take an array of 65 which is constant. This extra space is not O(n), it is O(1) as it doesnt hv any relation with inout size*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//By Srivastav's modulo
void findEven(int b[],int n)
{
int i;
int a[64];    //extra array but constant space as we know the range is 0 to 63 only
memset(a,0,sizeof(a));
for(i=0;i<n;i++)
	a[b[i]]++;

for(i=0;i<64;i++)
{
if(!a[i])continue;
printf("\n%d %s",i,(a[i]%2==0?"Even":"Odd"));
}
}
int main()
{
int a[] = {1,2,3,3,1,50,50};
int size = sizeof(a)/sizeof(a[0]);

findEven(a,size);
return 0;
}
]
Print 1 to 100 in C++, without loop and recursion[ ******
#include<iostream>
using namespace std;

struct NaturalNum
{
    NaturalNum()
    {
        static int i=1;
        cout<<i++<<" ";
    }
} N[100];	//declare 100 objects

main(){}
]
Sort an array of 0s, 1s and 2s[ ******mostly asked que
Given an array A[] consisting 0s, 1s and 2s, write a function that sorts A[]. The functions should put all 0s first, then all 1s and all 2s in last.

Example
Input = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
Output = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}

void sort012(int a[], int arr_size)
{
int low=0,high=n-1,mid=0;
        
            while(mid<=high)		//remember this  mid<=high hai na ki low<=high
            {
                switch(a[mid])
                {
                    case 0:
                        swap(&a[low],&a[mid]);
                        low++;mid++;
                        break;
                    case 1:
                        mid++;break;
                    case 2:
                        swap(&a[mid],&a[high]);
                        high--;
                        break;
                }
                
            }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
]
Find the Minimum length Unsorted Subarray, sorting which makes the complete array sorted[  *Microsoft* Doesnt need sorting **
1) Find the candidate unsorted subarray 
	a) Scan from left to right and find the first element which is greater than the next element. Let s be the index of such an element. In the above example 1, s is 3 (index of 30).
	b) Scan from right to left and find the first element (first in right to left order) which is smaller than the next element (next in right to left order). Let e be the index of such an element. In the above example 1, e is 7 (index of 31).

2) Check whether sorting the candidate unsorted subarray makes the complete array sorted or not. If not, then include more elements in the subarray.
	a) Find the minimum and maximum values in arr[s..e]. Let minimum and maximum values be min and max. min and max for [30, 25, 40, 32, 31] are 25 and 40 respectively.
	b) Find the first element (if there is any) in arr[0..s-1] which is greater than min, change s to index of this element. There is no such element in above example 1.
	c) Find the last element (if there is any) in arr[e+1..n-1] which is smaller than max, change e to index of this element. In the above example 1, e is changed to 8 (index of 35)


void findUnsorted(int a[],int n)
{
int i,index1,index2;
for(i=0;i<n-1;i++)
{
	if(a[i]>a[i+1])
	{
	index1 = i;
	break;
	}	
}
if(i+1==n-1) printf("The complete array is sorted!!\n");
for(i=n-1;i>=0;i--)
{
	if(a[i]<a[i-1])
	{
		index2=i;
		break;
	}
}
//now find min and max in b/w index1 and index2
int max = a[index1];
int min = a[index1];
for(i=index1+1;i<=index2;i++)
{
	if(a[i]>max)
	max = a[i];
	if(a[i] < min)
	min = a[i];
}
//now check if there is any element greater than min before the index1
for(i=0;i<index1;i++)
{
	if(a[i]>min)
	{
	index1 = i;	//if any greater element found
	break;
	}
}
//check if there is any element smaller than max after the index2
for(i=n-1;i>index2;i--)
{
	if(a[i]<max)
	{
	index2 = i;
	break;
	}
}
printf("\nThe unsorted array which makes the given array sorted lies between %d and %d\n",index1, index2);
}
int main()
{
int a[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
int size = sizeof(a)/sizeof(a[0]);
findUnsorted(a,size);
return 0;
}
]
Find duplicates in O(n) time and O(1) extra space
Equilibrium index of an array
Linked List vs Array
Which sorting algorithm makes minimum number of memory writes?[
Minimizing the number of writes is useful when making writes to some huge data set is very expensive, such as with EEPROMs or Flash memory, where each write reduces the lifespan of the memory.

Selection Sort makes least number of writes (it makes O(n) swaps).  But, Cycle Sort almost always makes less number of writes compared to Selection Sort.  In Cycle Sort, each value is either written zero times if it�s already in its correct position, or written one time to its correct position. This matches the minimal number of overwrites required for a completed in-place sort.
]
Turn an image by 90 degree
Check if array elements are consecutive | Added Method 3
Find the smallest missing number
Count the number of occurrences in a sorted array
Interpolation search vs Binary search
Given an array arr[], find the maximum j � i such that arr[j] > arr[i]
Maximum of all subarrays of size k (Added a O(n) method)
Find whether an array is subset of another array | Added Method 3
Find the minimum distance between two numbers
Find the repeating and the missing | Added 3 new methods[  *
Given an unsorted array of size n. Array elements are in range from 1 to n. One number from set {1, 2, �n} is missing and one number occurs twice in array. Find these two numbers.

Examples:

  arr[] = {3, 1, 3}
  Output: 2, 3   // 2 is missing and 3 occurs twice 

  arr[] = {4, 3, 6, 2, 1, 1}
  Output: 1, 5  // 5 is missing and 1 occurs twice 
  
  void printTwoElements(int arr[], int size)
{
    int i;
    printf("\n The repeating element is");
 
    for(i = 0; i < size; i++)
    {
        if(arr[abs(arr[i])-1] > 0)		//subtracting 1 as range is given as 1 to n
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        else
            printf(" %d ", abs(arr[i]));
    }
 
    printf("\nand the missing element is ");
    for(i=0; i<size; i++)
    {
        if(arr[i]>0)
            printf("%d",i+1);
    }
}
 
/* Driver program to test above function */
int main()
{
    int arr[] = {7, 3, 4, 5, 5, 6, 2};
    int  n = sizeof(arr)/sizeof(arr[0]);
    printTwoElements(arr, n);
    return 0;
}

Method 5 (Use XOR)  -- same as finding two non repeating element
==========================
Let x and y be the desired output elements.
Calculate XOR of all the array elements.

     xor1 = arr[0]^arr[1]^arr[2].....arr[n-1]
XOR the result with all numbers from 1 to n

     xor1 = xor1^1^2^.....^n
In the result xor1, all elements would nullify each other except x and y. All the bits that are set in xor1 will be set in either x or y. So if we take any set bit (We have chosen the rightmost set bit in code) of xor1 and divide the elements of the array in two sets � one set of elements with same bit set and other set with same bit not set. By doing so, we will get x in one set and y in another set. Now if we do XOR of all the elements in first set, we will get x, and by doing same in other set we will get y.

Time Complexity: O(n)

This method doesn�t cause overflow, but it doesn�t tell which one occurs twice and which one is missing. We can add one more step that checks which one is missing and which one is repeating. This can be easily done in O(n) time.
]
Median in a stream of integers (running integers)
Find a Fixed Point in a given array
Maximum Length Bitonic Subarray-----*** DO IT AGAIN-- bitonic means Mountain shape--[
	int bitonic(int arr[], int n)
	{
    int inc[n]; // Length of increasing subarray ending at all indexes
    int dec[n]; // Length of decreasing subarray starting at all indexes
    int i, max;
 
    // length of increasing sequence ending at first index is 1
    inc[0] = 1;
 
    // length of increasing sequence starting at first index is 1
    dec[n-1] = 1;
 
    // Step 1) Construct increasing sequence array
    for (i = 1; i < n; i++)
       inc[i] = (arr[i] > arr[i-1])? inc[i-1] + 1: 1;
 
    // Step 2) Construct decreasing sequence array
    for (i = n-2; i >= 0; i--)
       dec[i] = (arr[i] > arr[i+1])? dec[i+1] + 1: 1;
 
    // Step 3) Find the length of maximum length bitonic sequence
    max = inc[0] + dec[0] - 1;
    for (i = 1; i < n; i++)
        if (inc[i] + dec[i] - 1 > max)
            max = inc[i] + dec[i] - 1;
 
    return max;
	}
	]
Find the maximum element in an array which is first increasing and then decreasing
Count smaller elements on right side
Minimum number of jumps to reach end[ ***Mostly asked que
Given an array of integers where each element represents the max number of steps that can be made forward from that element. Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Example:
Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 8 ->9)
First element is 1, so can only go to 3. Second element is 3, so can make at most 3 steps eg to 5 or 8 or 9

]
Implement two stacks in an array
Find subarray with given sum
Dynamic Programming | Set 14 (Maximum Sum Increasing Subsequence)
Longest Monotonically Increasing Subsequence Size (N log N)
Find a triplet that sum to a given value
Find the smallest positive number missing from an unsorted array
Find the two numbers with odd occurrences in an unsorted array
The Celebrity Problem
	Dynamic Programming | Set 15 (Longest Bitonic Subsequence) --- DONE
Find a sorted subsequence of size 3 in linear time
Largest subarray with equal number of 0s and 1s[****

]
Dynamic Programming | Set 18 (Partition problem)
Maximum Product Subarray
Find a pair with the given difference
Replace every element with the next greatest -- *asking greatest so easy if its next greater then tricky*[
just traverse from right and keep a track of max element]
Next Greater Element--**[
void nextGreater(int a[],int n)
{
	int i;
	int max = a[n-1];
        stack<int> S;
        S.push(-1);     //printf("%d ",-1);        
        for(i=n-2;i>=0;i--)
        {
            if(a[i]<a[i+1])
            S.push(a[i+1]);   //printf("%d ",a[i+1]);
            else if(a[i]<max)
            S.push(max);      //printf("%d ",max);
            else if(a[i]>max)
            {
            	max = a[i]; 
            	S.push(-1);	//printf("%d ",-1);
            }
        }
	
	while(!S.empty())
	{
		int tmp = S.top();
		S.pop();
		printf("%d ",tmp);
	}
}

int main()
{
int a[] = {1, 3, 2, 4};
int size = sizeof(a)/sizeof(a[0]);
nextGreater(a,size);
}
]

Dynamic Programming | Set 20 (Maximum Length Chain of Pairs)
Find four elements that sum to a given value | Set 1 (n^3 solution)
Find four elements that sum to a given value | Set 2 ( O(n^2Logn) Solution)
Sort a nearly sorted (or K sorted) array
Maximum circular subarray sum
Find the row with maximum number of 1s
Median of two sorted arrays of different sizes
Shuffle a given array
Count the number of possible triangles
Iterative Quick Sort
Find the number of islands[ **** CODE IT {{{{{{{}}}}}}}
// Program to count islands in boolean 2D matrix
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
#define ROW 5
#define COL 5
 
// A function to check if a given cell (row, col) can be included in DFS
int isSafe(int M[][COL], int row, int col, bool visited[][COL])
{
    // row number is in range, column number is in range and value is 1 and not yet visited
    return (row >= 0) && (row < ROW) &&     
           (col >= 0) && (col < COL) &&      
           (M[row][col] && !visited[row][col]); 
}

// A utility function to do DFS for a 2D boolean matrix. It only considers
// the 8 neighbours as adjacent vertices
void DFS(int M[][COL], int row, int col, bool visited[][COL])
{
    // These arrays are used to get row and column numbers of 8 neighbours 
    // of a given cell
    static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};
 
    // Mark this cell as visited
    visited[row][col] = true;
 
    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row+rowNbr[k], col+colNbr[k], visited) )
            DFS(M, row+rowNbr[k], col+colNbr[k], visited);
}
 
// The main function that returns count of islands in a given boolean
// 2D matrix
int countIslands(int M[][COL])
{
    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));			//**** TRICK to fill array with any char here that char is 0
 
    // Initialize count as 0 and travese through the all cells of
    // given matrix
    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)
            if (M[i][j] && !visited[i][j]) // If a cell with value 1 is not
            {                         // visited yet, then new island found
                DFS(M, i, j, visited);     // Visit all cells in this island.
                ++count;                   // and increment island count
            }
 
    return count;
}
// Driver program to test above function
int main()
{
    int M[][COL]= {  {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
    printf("Number of islands is: %d\n", countIslands(M));
    return 0;
}
]
Construction of Longest Monotonically Increasing Subsequence (N log N)
Find the first circular tour that visits all petrol pumps
Arrange given numbers to form the biggest number
Pancake sorting
A Pancake Sorting Problem
Tug of War
Divide and Conquer | Set 3 (Maximum Subarray Sum)
Counting Sort
Merge Overlapping Intervals
Find the maximum repeating number in O(n) time and O(1) extra space
Stock Buy Sell to Maximize Profit
Rearrange positive and negative numbers in O(n) time and O(1) extra space
Sort elements by frequency | Set 2
Find a peak element
Print all possible combinations of r elements in a given array of size n
Given an array of of size n and a number k, find all elements that appear more than n/k times
Find the point where a monotonically increasing function becomes positive first time
Find the Increasing subsequence of length three with maximum product
Find the minimum element in a sorted and rotated array[*
Input: {5, 6, 1, 2, 3, 4}
Output: 1

int findMin(int a[],int low,int high)
{
if(high<low)	return a[0];	//case when array is already sorted  -- point to remember

if(low==high) return a[low];

int mid = low + (high-low)/2;

// Check if element (mid+1) is minimum element. Consider the cases like {3, 4, 5, 1, 2}
if(mid+1<=high && a[mid]>a[mid+1])	 //mid<high esliye lagaya kyunki we're checking a[mid+1]<a[mid] so for this first we need to check the index sahi h k nai
return a[mid+1];		 

// Check if mid itself is minimum element
if(mid-1>=low && a[mid]<a[mid-1])		//mid>low bas wo index check karne k liye lagaya jo hum yahan access kar rahe hain
return a[mid];

// Decide whether we need to go to left half or right half
if(a[mid]<a[high])
return findMin(a,low,mid-1);

return findMin(a,mid+1,high);
}

int main()
{
int a[] = {5,6,1,2,3,4};
int size = sizeof(a)/sizeof(a[0]);
printf("%d\n",findMin(a,0,size-1));
return 0;
}
]
Stable Marriage Problem
Merge k sorted arrays | Set 1
Radix Sort
Move all zeroes to end of array
Find number of pairs such that x^y > y^x
Count all distinct pairs with difference equal to k [ ***
Method 4 (Use Hashing)
We can also use hashing to achieve the average time complexity as O(n) for many cases.

1) Initialize count as 0.
2) Insert all distinct elements of arr[] in a hash map.  While inserting, 
   ignore an element if already present in the hash map.
3) Do following for each element arr[i].
   a) Look for arr[i] + k in the hash map, if found then increment count.
   b) Look for arr[i] - k in the hash map, if found then increment count.
   c) Remove arr[i] from hash table. 
A very simple case where hashing works in O(n) time is the case where range of values is very small. For example, in the following implementation, range of numbers is assumed to be 0 to 99999. A simple hashing technique to use values as index can be used.

/* An efficient program to count pairs with difference k when the range
   numbers is small */
#define MAX 100000
int countPairsWithDiffK(int arr[], int n, int k)
{
    int count = 0;  // Initialize count
 
    // Initialize empty hashmap.
    bool hashmap[MAX] = {false};
 
    // Insert array elements to hashmap
    for (int i = 0; i < n; i++)
        hashmap[arr[i]] = true;
 
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        if (x - k >= 0 && hashmap[x - k])
            count++;
        if (x + k < MAX && hashmap[x + k])
            count++;
        hashmap[x] = false;
    }
    return count;
}
==========================
Using C++ unorderd_set
==========================
#include <iostream>
#include <bits/stdc++.h>		//** includes all the headers
using namespace std;
void res(int a[],int n,int k)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
        s.insert(a[i]);
    for(int i=0;i<n;i++)
    {
        if(s.find(a[i]+k)!=s.end())
            cout<<a[i]<<" "<<a[i]+k<<endl;
    }
}
int main()
{
    int a[] =  {1, 5, 3, 4, 2};
    int n = sizeof(a)/sizeof(a[0]);
    int k = 3;
    res(a,n,k);
    cout<<"second test\n";
    int a2[] = {8, 12, 16, 4, 0, 20};
    k = 4;
    res(a2,6,k);
    return 0;
}

===========================
Method 5 (Use Sorting)
===========================
#include <iostream>
#include <algorithm>
using namespace std;
/* Returns count of pairs with difference k in arr[] of size n. */
int countPairsWithDiffK(int arr[], int n, int k)
{
    int count = 0;
    sort(arr, arr+n);  // Sort array elements
 
    int l = 0;
    int r = 0;
    while(r < n)
    {
         if(arr[r] - arr[l] == k)
        {
              count++;
              l++;
              r++;
        }
         else if(arr[r] - arr[l] > k)
              l++;
         else // arr[r] - arr[l] < sum
              r++;
    }   
    return count;
}
=============================
C++ unordered_set another ex
=============================
// Print duplicates in arr[0..n-1] using unordered_set
void printDuplicates(int arr[], int n)
{
    // declaring unordered sets for checking and storing
    // duplicates
    unordered_set<int> intSet;
    unordered_set<int> duplicate;
 
    // looping through array elements
    for (int i = 0; i < n; i++)
    {
        // if element is not there then insert that
        if (intSet.find(arr[i]) == intSet.end())
            intSet.insert(arr[i]);
 
        // if element is already there then insert into
        // duplicate set
        else
            duplicate.insert(arr[i]);
    }
 
    // printing the result
    cout << "Duplicate item are : ";
    unordered_set<int> :: iterator itr;
 
    // iterator itr loops from begin() till end()
    for (itr = duplicate.begin(); itr != duplicate.end(); itr++)
        cout << *itr << " ";
}
]
Find if there is a subarray with 0 sum
Smallest subarray with sum greater than a given value
Sort an array according to the order defined by another array
Maximum Sum Path in Two Arrays
Check if a given array contains duplicate elements within k distance from each other
Sort an array in wave form
K�th Smallest/Largest Element in Unsorted Array
K�th Smallest/Largest Element in Unsorted Array in Expected Linear Time
K�th Smallest/Largest Element in Unsorted Array in Worst Case Linear Time
Find Index of 0 to be replaced with 1 to get longest continuous sequence of 1s in a binary array
Find the closest pair from two sorted arrays
Given a sorted array and a number x, find the pair in array whose sum is closest to x
Count 1�s in a sorted binary array
Print All Distinct Elements of a given integer array
Construct an array from its pair-sum array
Find common elements in three sorted arrays
Find the first repeating element in an array of integers
Find the smallest positive integer value that cannot be represented as sum of any subset of a given array
Rearrange an array such that �arr[j]� becomes �i� if �arr[i]� is �j�--[
Given an array of size n where all elements are in range from 0 to n-1, change contents of arr[] so that arr[i] = j is changed to arr[j] = i.
void rearrange(int a[], int n)
{
    int i;
    
	for(i=0;i<n;i++)
	a[a[i]%n] = a[a[i]%n] + i*n;		//a[i]%n is index as we're changing its content we need to add something in this only

	for(i=0;i<n;i++)
	a[i] = a[i]/n;
}
]
Rearrange an array so that arr[i] becomes arr[arr[i]] with O(1) extra space[  -- Srivastav's logic **
**if u are using malloc then make sure u r multiplying by number of int u need ie. by n --- ur common MISTAKE**
use assert defined in #include<assert.h> to check whether malloc has created good space or not... assert(p!=NULL); ur code..
All values is array are from 0 to n-1 so we dont need to take modulo n on a[i]...in case if they are not...we need to take
void rearrangeArray(int a[],int n)
{	
	int i;

	for(i=0;i<n;i++)
	{
		a[i] = a[i] + a[a[i]]%n * n;
//		printf("%d ",a[i]);
	}
	printf("\n");

	for(i=0;i<n;i++)
	a[i] = a[i]/n;
}
]
Find position of an element in a sorted array of infinite numbers
Can QuickSort be implemented in O(nLogn) worst case time complexity?
Check if a given array contains duplicate elements within k distance from each other
Find the element that appears once
Replace every array element by multiplication of previous and next
Check if any two intervals overlap among a given set of intervals
Delete an element from array (Using two traversals and one traversal)
Given a sorted array and a number x, find the pair in array whose sum is closest to x
Find the largest pair sum in an unsorted array
Online algorithm for checking palindrome in a stream
Find Union and Intersection of two unsorted arrays
Pythagorean Triplet in an array
Maximum profit by buying and selling a share at most twice
Find Union and Intersection of two unsorted Arrays
Count frequencies of all elements in array in O(1) extra space and O(n) time
Generate all possible sorted arrays from alternate elements of two given sorted arrays
Minimum number of swaps required for arranging pairs adjacent to each other
Trapping Rain Water [ asked its variation to me in eZDI couldnt give ans *** 
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

An element of array can store water if there are higher bars on left and right. We can find amount of water to be stored in every element by finding the heights of bars on left and right sides. The idea is to compute amount of water that can be stored in every element of array. For example, consider the array {3, 0, 0, 2, 0, 4}, we can store two units of water at indexes 1 and 2, and one unit of water at index 2.

A Simple Solution is to traverse every array element and find the highest bars on left and right sides. Take the smaller of two heights. The difference between smaller height and height of current element is the amount of water that can be stored in this array element. Time complexity of this solution is O(n2).

An Efficient Solution is to prre-compute highest bar on left and right of every bar in O(n) time. Then use these pre-computed values to find the amount of water in every array element. Below is C++ implementation of this solution.

TC - O(n) 
SC - O(n)
void findWater(int a[],int n)
{
int i,water=0;
int left[n];	//to store left greater
int right[n];	//to store right greater

left[0]=a[0];
for(i=1;i<n;i++)
	left[i] = max(left[i-1],a[i]);

right[n-1] = a[n-1];
for(i=n-2;i>=0;i--)
	right[i] = max(right[i+1],a[i]);

for(i=0;i<n;i++)
	water += min(left[i],right[i])-a[i];

printf("%d\n",water);
}

int main()
{ 
int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
int size = sizeof(a)/sizeof(a[0]);
findWater(a,size);
return 0;
}

]
Trapping rain water with max area[ asked to me in eZDI
Given n non-negative integers a1, a2, ..., an,
where each represents a point at coordinate (i, ai).
'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Your program should return an integer which corresponds to the maximum area of water that can be contained
int solve(int arr[], int n) 
{     
    int i = 0;
    int j = n - 1;
    int ans = 0;
    int area, mini;
     
    while(i < j) 
	{     
        mini = min(arr[i], arr[j]);
        area = (j - i) * mini;
        ans = max(area, ans);
        if(arr[i] > arr[j]) j--;
        else i++;
    }
     
     return ans;
}

int main() 
{     
    int arr[] = {1, 5, 4, 3};
    int n = sizeof arr / sizeof arr[0];
    cout << solve(arr, n) << endl;  
    return 0;
}
]
Convert array into Zig-Zag fashion[ *Srivastav's -- take trio of elements and keep current on mid element and then bring the max of trio in middle
Given an array of distinct elements, rearrange the elements of array in zig-zag fashion in O(n) time. The converted array should be in form a < b > c < d > e < f.
if any trio is fit according to situation then go ahead and take next trio.
This will minimise the number of swaps.
Can check geek's solution by using flag -- if flag is zero means > is expected else < expected and at last flip the flag for next iteration.
]
Find maximum average subarray of k length  
Find maximum value of Sum( i*arr[i]) with only rotations on given array allowed [  CHECK it ###
int maxSum(int arr[], int n)
{
    // Find array sum and i*arr[i] with no rotation
    int arrSum = 0;  // Stores sum of arr[i]
    int currVal = 0;  // Stores sum of i*arr[i]
    for (int i=0; i<n; i++)
    {
        arrSum = arrSum + arr[i];
        currVal = currVal+(i*arr[i]);
    }
 
    // Initialize result as 0 rotation sum
    int maxVal = currVal;
 
    // Try all rotations one by one and find
    // the maximum rotation sum.
    for (int j=1; j<n; j++)
    {
        currVal = currVal + arrSum-n*arr[n-j];
        if (currVal > maxVal)
            maxVal = currVal;
    }
 
    // Return result
    return maxVal;
}
]
Reorder an array according to given indexes [ Srivastav logic
void reorder(int a[], int index[], int n)
{
	int i;
	int max= a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		max = a[i];
	}
	
	max++;
	for(i=0;i<n;i++)
		a[index[i]] = a[index[i]] + (a[i]%max)*max; 
	
	for(i=0;i<n;i++)
		a[i] /= max;
	
	
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}

int main()
{
int a[] =     {50, 40, 70, 60, 90};
int index[] = {3,  0,  4,  1,  2};
int n = sizeof(a)/sizeof(a[0]);int i;
reorder(a, index, n);
printf("\n");
return 0;
}
] 

Find zeroes to be flipped so that number of consecutive 1�s is maximized  
Count triplets with sum smaller than a given value [ *** Srivastav
void countTriplet(int a[],int n,int sum)
{
int i,j,k;
int count=0;

sort(a,a+n);		//sorting

for(i=0;i<n-2;i++)
{
	j=i+1;	//we fixed j
	k=n-1;
	while(j<k)
	{
		if(a[i] + a[j] + a[k] >= sum)
			k--;
		
		else
		{
		count = count + (k-j);	   //all the elements b/w j and k will make triplet
		j++;
		//printf("%dhiiii",count);
		}
	}
}

printf("%d\n",count);

}
] 
Find the subarray with least average[*
The idea is to use sliding window of size k. Keep track of sum of current k elements. To compute sum of current window, remove first element of previous window and add current element (last element of current window).

1) Initialize res_index = 0 // Beginning of result index
2) Find sum of first k elements. Let this sum be 'curr_sum'
3) Initialize min_sum = sum
4) Iterate from (k+1)'th to n'th element, do following
   for every element arr[i]
      a) curr_sum = curr_sum + arr[i] - arr[i-k]
      b) If curr_sum < min_sum
           res_index = (i-k+1)
5) Print res_index and res_index+k-1 as beginning and ending
   indexes of resultant subarray.
   ]  
Count Inversions of size three in a give array
Longest Span with same Sum in two Binary arrays
Merge two sorted arrays with O(1) extra space
Form minimum number from given sequence
Subarray/Substring vs Subsequence and Programs to Generate them[
int main()
{
char a[] = "abc";
int i,j;
int n = strlen(a);

for(i=1;i<(1<<n);i++)		//if we'll start from i=0 then 1st o/p will be a space
{							//so start from i=1
	for(j=0;j<n;j++)
	{
		if(i & (1<<j))	
		printf("%c",a[j]);
	} 
	printf("\n");
}	
return 0;
}
]
Count Strictly Increasing Subarrays
Rearrange an array in maximum minimum form[ ** Srivastav's logic
void rearrangeMinMax(int a[],int n)
{
	int largest = a[n-1]+1, min=0,max=n-1,i;
        for(i=0;i<n;i++)
        {
            if((i%2)==0)    //even
            {
                a[i] = a[i] + a[max]%largest * largest;    //use modulo*****
                max--;
            }
            else
            {
				a[i] = a[i] + a[min]%largest * largest;
				min++;
            }
        }
        for(i=0;i<n;i++)
        a[i] = a[i]/largest;
}
]
Find minimum difference between any two elements
Find lost element from a duplicated array
Count pairs with given sum
Count minimum steps to get the given desired array
Find minimum number of merge operations to make an array palindrome
Minimize the maximum difference between the heights
How to dynamically allocate a 2D array in C [  -- how Double pointer works??
//using single pointer
void SinglePointer(int r,int c)
{
int *a,count=0;
a = (int *)malloc(r*c*sizeof(int));		//r -- row and c -- col
int i,j;
for(i=0;i<r;i++)
	for(j=0;j<c;j++)
		*(a+c*i+j) = count++;

	for(i=0;i<r;i++)
	for(j=0;j<c;j++)
		printf("%d ",*(a+c*i+j));
}

//using array of pointers			BEST ONE
void arrayOfPointers(int r, int c)
{
int i,j;
int count =0;
int *a[r];		//allocated an array of size = row and then for each row do malloc equals to cols

for(i=0;i<r;i++)
a[i] =  (int *)malloc(sizeof(int)*c);

for(i=0;i<r;i++)
	for(j=0;j<c;j++)
		a[i][j] = count++;


for(i=0;i<r;i++)
	for(j=0;j<c;j++)
		printf("%d ",a[i][j]);
	
}
int main()
{
int i,j;
int r=2,c=3;

SinglePointer(r,c);
printf("\n");
arrayOfPointers(r,c);
return 0;
}
]





Other Random Problems
Runlength Encoding[**
IF Given a string "aaabbbcc", compress it, = "a3b3c2" . Given that output string's length is always smaller than input string, you have do it inplace. No extra space like array should be used.

below is not inplace-
char* findEncoding(char a[],int len)
{
int i,j=0,tmpCount;
char *dest = (char *)malloc(sizeof(char)*(len*2+1));   //in WC it can take twice the length of given string as for abcd, it will generate a1b1c1d1
char tmp[5];

	for(i=0;i<len;i++)
	{
		dest[j++] = a[i];
		tmpCount=1;
		while(i+1<len (JUST OUT OF BOUND CHECK OF ARRAY) && a[i]==a[i+1])
		{
			i++;
			tmpCount++;
		}
		sprintf(tmp,"%d",tmpCount);	  //to store int in char array -- we cant do this without sprintf
		dest[j++] = tmp[0];
	}
dest[j] = '\0';
/*
for(int k=0;k<j;k++)
printf("%c ",dest[k]);
*/
return dest;
}

int main()
{
char a[] = "geeeeks";
int len = strlen(a);

char *res = findEncoding(a,len);
printf("%s\n",res);
return 0;
}

IN-PLACE
===================
void findEncoding(char *a)
{
int i=0,k=0;

while(a[i] != '\0')
{
	int cc=1;	//char count
	char c=a[i];	//char
	while(a[i] == a[i+1])
	{
		cc++;
		i++;
	}
	a[k++]=c;
	a[k++] = '0' + cc;
	i++;
	cc=1;
}
a[k] = '\0';
}
]
Inplace rotate square matrix by 90 degrees---  by Srivastavs modulo[
#include<stdio.h>
#include<stdlib.h>
#define N 4

int findmax(int a[][N])
{
int i,j,max=a[0][0];

for(i=0;i<N;i++)
{
	for(j=0;j<N;j++)
	{
		if(a[i][j] > max)
		max = a[i][j];
	}
}
return max+1;
}

void rotateMat(int a[][N])
{
	int i,j;

	int max = findmax(a);

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			a[j][N-1-i] = a[j][N-1-i] + (a[i][j]%max)*max ;    //jis index pe jana h us index pe add some value....thats y both side we've same value
		}
	}

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			a[i][j] /= max;
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

}

int main()
{
int a[N][N] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
rotateMat(a);

return 0;
}
]
For handling -ve -- find max negative value and add to each element then apply above modulo magic and later add that max negative value to restore values[
#include<stdio.h>
#include<stdlib.h>
#define N 4

int findmax(int a[][N])
{
int i,j,max=a[0][0];

for(i=0;i<N;i++)
{
	for(j=0;j<N;j++)
	{
		if(a[i][j] > max)
		max = a[i][j];
	}
}
return max+1;
}

void rotateMat(int a[][N])
{
int i,j;

int max = findmax(a);

for(i=0;i<N;i++)
{
	for(j=0;j<N;j++)
	{
		a[j][N-1-i] = (a[i][j]%max)*max + a[j][N-1-i] ;
	}
}

for(i=0;i<N;i++)
{
	for(j=0;j<N;j++)
	{
		a[i][j] /= max;
	}
}
}

void printMat(int a[][N])
{
int i,j;
for(i=0;i<N;i++)
{
	for(j=0;j<N;j++)
	{
		printf("%d ",a[i][j]);
	}
	printf("\n");
}
}

int findmin(int a[][N])
{
int i,j;
int min = a[0][0];
for(i=0;i<N;i++)
{
	for(j=0;j<N;j++)
	{
		if(a[i][j] < min)
		min  = a[i][j];
	}
}
return min;
}

void makePosArr(int a[][N],int min,int flag)
{
int i,j;
for(i=0;i<N;i++)
{
	for(j=0;j<N;j++)
	{
		if(flag==0)
		a[i][j] -= min;
		
		else
		a[i][j] += min;
		
	}
}
}


int main()
{
int a[N][N] =
    {
        {1, -2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, -11, 12},
        {13, 14, 15, 16}
    };

int min = findmin(a);
makePosArr(a,min,0);

rotateMat(a);

makePosArr(a,min,1);

printMat(a);
return 0;
}

]

Find if two rectangles overlap[
#include<bits/stdc++.h>
struct Point
{
    int x, y;
};
 
// Returns true if two rectangles (l1, r1) and (l2, r2) overlap
bool doOverlap(Point l1, Point r1, Point l2, Point r2)
{
    // If one rectangle is on left side of other
    if (l1.x > r2.x || l2.x > r1.x)			//use the concept of opposite.... as fail hone ki conditions jyada hai so check for those
        return false;
 
    // If one rectangle is above other
    if (l1.y < r2.y || l2.y < r1.y)
        return false;
 
    return true;
}
/* Driver program to test above function */
int main()
{
    Point l1 = {0, 10}, r1 = {10, 0};
    Point l2 = {5, 5}, r2 = {15, 0};
    if (doOverlap(l1, r1, l2, r2))
        printf("Rectangles Overlap");
    else
        printf("Rectangles Don't Overlap");
    return 0;
}
]


::::::::::::::::::::::::::MATRIX:::::::::::::::::::::::::::::::
========================================================================
Count zeros in a row wise and column wise sorted matrix [ complexity - O(n)
#define N 5

int countZeros(int a[][N])
{
int i=0,j=N-1,count=0;		//start scanning from top right 

	while(i<N && j>=0)
	{
		if(a[i][j]==0)
		{
		//printf("0 --[i][j] = [%d][%d]",i,j);
		count = count + j+1;    //jitni j ki value hai us place pe us se 1 jyada 0's honge
		i++;
		}
		else
		j--; 
	}
return count;
}
int main()
{
int a[][N] = {{0,0,0,0,1},
	          {0,0,0,1,1},
	          {0,0,0,1,1},
	          {0,1,1,1,1},
	          {0,1,1,1,1},
	         };
printf("%d\n",countZeros(a));
return 0;
}
]
Count Negative Numbers in a Column-Wise and Row-Wise Sorted Matrix-- same as above que[
]
Search in a row wise and column wise sorted matrix-- DONE[
]
Print a given matrix in spiral form-- check in copy[
]
A Boolean Matrix Question[***
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define N 3		//row
#define M 4		//col

void modifyMatrix(bool a[][M])
{
bool rowM[N],colM[M];
memset(rowM,0,N);
memset(colM,0,M);

for(int i=0;i<N;i++)
{
	for(int j=0;j<M;j++)
	{
		if(a[i][j]==1)
		{
			rowM[i]=1;
			colM[j]=1;
		}	
	}
}

for(int i=0;i<N;i++)
{
	for(int j=0;j<M;j++)
	{
		if(rowM[i]==1 || colM[j]==1)
		a[i][j] =1;
	}
}

}

void printMatrix(bool a[][M])
{
int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
		printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
bool a[N][M] = {{1,0,0,1},
		{0,0,1,0},
		{0,0,0,0},
		};
printMatrix(a);
modifyMatrix(a);
printMatrix(a);
return 0;
}
=================In-Place versison==================== use matrix's 1st row and 1st col for storing..and other things as above
[
void modifyMatrix(bool a[][M])
{
int rowF,colF;	//rowFlag, colFlag

for(int i=0;i<M;i++)
{if(a[i][0]==1) colF=1;}

for(int j=0;j<N;j++)
{if(a[0][j]==1) rowF=1;}

for(int i=1;i<N;i++)
{
	for(int j=1;j<M;j++)
	{
		if(a[i][j]==1)
		{
			a[0][j]=1;	//row
			a[i][0]=1;	//col
		}	
	}
}

for(int i=1;i<N;i++)
{
	for(int j=1;j<M;j++)
	{
		if(a[i][0]==1 || a[0][j]==1)
		a[i][j] =1;
	}
}


/*setting 1st row and 1st col*/    //***
if(rowF==1)
{
for(int i=0;i<M;i++)
a[0][i]=1;
}
if(colF==1)
{
for(int i=0;i<N;i++)
a[i][0]=1;
}
}

void printMatrix(bool a[][M])
{
int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
		printf("%d ",a[i][j]);
		}
		printf("\n");
	}
printf("\n");
}
]

]
Print unique rows in a given boolean matrix
Maximum size square sub-matrix with all 1s
Inplace M x N size matrix transpose | Updated
Print Matrix Diagonally
Dynamic Programming | Set 27 (Maximum sum rectangle in a 2D matrix)
Strassen�s Matrix Multiplication
Create a matrix with alternating rectangles of O and X
Find the row with maximum number of 1s in a row sorted 2D array[ **
Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s.
#include<stdio.h>
#include<stdlib.h>

#define N 4

int first(int a[],int low,int high)		//applying binary search to find the 1st appearance of 1
{
	if(low<=high)
	{
	int mid = low + (high-low)/2;

	if(a[mid]==1 && a[mid-1]==0)
	return mid;

	else if(a[mid]==0)	//u want to search 1's so put condition on 0 **
	first(a,mid+1,high);

	else
	first(a,low,mid-1);
	}
return -1;
}

void countOne(int a[N][N])
{
int i,j=0,f;

j=first(a[0],0,N-1);	//sending only first row to find the first appearance of 1 in first row **TRICK

if(j==-1) j=N-1;

printf("first at %d\n",j);

i=1;  //pehli row already covered so start from 2nd row ie. 1th row
while(i<N && j<N && j>=0)
{
	if(a[i][j]==1)
	{
	printf("a[%d][%d]\n",i,j);
	j--;
	}
	else
	i++;
}
printf("%d--%d\n",i,j+1);
printf("Max no. of 1's are : %d\n",N-j-1);
}

int main()
{
int a[N][N] = {{0,0,1,1},
	       {0,0,1,1},
	       {1,1,1,1},
	       {0,0,0,0}
	      };
countOne(a);
return 0;
}
TC for above is O(m log n)
=====================
Below is O(m+n)	 -- go for this ****

Step1: Get the index of first (or leftmost) 1 in the first row.
Step2: Do following for every row after the first row
�IF the element on left of previous leftmost 1 is 0, ignore this row.
�ELSE Move left until a 0 is found. Update the leftmost index to this index and max_row_index to be the current row.

The time complexity is O(m+n) because we can possibly go as far left as we came ahead in the first step.

Following is C++ implementation of this method.

// The main function that returns index of row with maximum number of 1s.
int rowWithMax1s(bool mat[R][C])
{
    // Initialize first row as row with max 1s
    int max_row_index = 0;
 
    // The function first() returns index of first 1 in row 0.
    // Use this index to initialize the index of leftmost 1 seen so far
    int j = first(mat[0], 0, C-1);
    if (j == -1) // if 1 is not present in first row
      j = C - 1;
 
    for (int i = 1; i < R; i++)
    {
        // Move left until a 0 is found
        while (j >= 0 && mat[i][j] == 1)
        {
           j = j-1;  // Update the index of leftmost 1 seen so far
           max_row_index = i;  // Update max_row_index
        }
    }
    return max_row_index;
}



]
Print all elements in sorted order from row and column wise sorted matrix
Given an n x n square matrix, find sum of all sub-squares of size k x k
Count number of islands where every island is row-wise and column-wise separated
Given a matrix of �O� and �X�, replace �O� with �X� if surrounded by �X�
Find the longest path in a matrix with given constraints
Given a Boolean Matrix, find k such that all elements in k�th row are 0 and k�th column are 1.
Find the largest rectangle of 1�s with swapping of columns allowed
Validity of a given Tic-Tac-Toe board configuration
Minimum Initial Points to Reach Destination
Find length of the longest consecutive path from a given starting character
Collect maximum points in a grid using two traversals
Rotate Matrix Elements
Find sum of all elements in a matrix except the elements in row and/or column of given cell?
Find a common element in all rows of a given row-wise sorted matrix
Number of paths with exactly k coins
Collect maximum coins before hitting a dead end
Program for Rank of Matrix
Submatrix Sum Queries
Maximum size rectangle binary sub-matrix with all 1s
Count Negative Numbers in a Column-Wise and Row-Wise Sorted Matrix -- DONE
Construct Ancestor Matrix from a Given Binary Tree
Construct tree from ancestor matrix
In-place convert matrix in specific order
Common elements in all rows of a given matrix
Print maximum sum square sub-matrix of given size
Find a specific pair in Matrix
Find orientation of a pattern in a matrix
Shortest path in a Binary Maze
Inplace rotate square matrix by 90 degrees[ DONE check above
]
Return previous element in an expanding matrix




:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::STRING:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
Given a string, find its first non-repeating character[  Mostly asked **DO IT**
Given a string, find the first non-repeating character in it. For example, if the input string is �GeeksforGeeks�, then output should be �f� and if input string is �GeeksQuiz�, then output should be �G�.

Naive approach:

1) Scan the string from left to right and construct the count array.
2) Again, scan the string from left to right and check for count of each
 character, if you find an element who's count is 1, return it.

 
 Can we do it by traversing the string only once?
The above approach takes O(n) time, but in practice it can be improved. The first part of the algorithm runs through the string to construct the count array (in O(n) time). This is reasonable. But the second part about running through the string again just to find the first non-repeater is not good in practice. In real situations, your string is expected to be much larger than your alphabet. Take DNA sequences for example: they could be millions of letters long with an alphabet of just 4 letters. What happens if the non-repeater is at the end of the string? Then we would have to scan for a long time (again).
We can augment the count array by storing not just counts but also the index of the first time you encountered the character e.g. (3, 26) for �a� meaning that �a� got counted 3 times and the first time it was seen is at position 26. So when it comes to finding the first non-repeater, we just have to scan the count array, instead of the string. 
 
]
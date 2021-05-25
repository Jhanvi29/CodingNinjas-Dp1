/*  You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:
First line will contain T (number of test case), each test is consists of two lines. 
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 
Output Format:
Length of Largest Bitonic subsequence for each test case in a newline.
Input Constraints:
1 <= T <= 10
1<= N <= 5000
Sample Input 1:
1
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
1
2
1 5
Sample Output 2:
2
Sample Input 3:
1
2
5 1
Sample Output 3:
2
*/

/* Dynamic Programming implementation of longest bitonic subsequence problem */
#include<stdio.h>
#include<stdlib.h>
 
/* lbs() returns the length of the Longest Bitonic Subsequence in
    arr[] of size n. The function mainly creates two temporary arrays
    lis[] and lds[] and returns the maximum lis[i] + lds[i] - 1.
 
    lis[i] ==> Longest Increasing subsequence ending with arr[i]
    lds[i] ==> Longest decreasing subsequence starting with arr[i]
*/
int longestBitonicSequence(vector<int> &ARR, int N) 
{
	/*
		LIS[i] stores the length of longest increasing sequence  
		ending at index i.
	*/

	/*
		LDS[i] stores the length of the longest decreasing sequence  
		starting at index i.
	*/
	
    int LIS[N], LDS[N];

    for(int i = 0; i < N; i++)
    {
        LIS[i] = 1;

        for(int j = 0; j < i; j++)
        {
            if(ARR[i] >= ARR[j])
            {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }

    for(int i = N - 1; i >= 0; i--)
    {
        LDS[i] = 1;

        for(int j = i + 1; j < N; j++)
        {
            if(ARR[i] >= ARR[j])
            {
                LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }
    }

    int maxLength = 0;

    for(int i = 0; i < N; i++)
    {
        maxLength = max(maxLength, LDS[i] + LIS[i] - 1);
    }

    return maxLength;    
}
 
/* Driver program to test above function */
int main()
{
  int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,
              13, 3, 11, 7, 15};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LBS is %d\n", lbs( arr, n ) );
  return 0;
}

/*
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
First line will contain T(number of test case), each test case consists of a single line containing an integer N.
Output Format :
For each test case print the required minimum count in a newline.
Constraints :
 1 <= T <= 1000
 1 <= N <= 1000
Sample Input 1 :
1
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
1
9
Sample Output 2 :
1

*/


#include<bits/stdc++.h>
using namespace std;

int getMinSquares(int n)
{
    // We need to check base case
    // for n i.e. 0,1,2
    // the below array creation
    // will go OutOfBounds.
    if(n<=3)
      return n;
     
    // Create a dynamic
    // programming table
    // to store sq
    int* dp = new int[n + 1];
 
    // getMinSquares table
    // for base case entries
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
 
    // getMinSquares rest of the
    // table using recursive
    // formula
    for (int i = 4; i <= n; i++)
    {
         
        // max value is i as i can
        // always be represented
        // as 1*1 + 1*1 + ...
        dp[i] = i;
 
        // Go through all smaller numbers to
        // to recursively find minimum
        for (int x = 1; x <= ceil(sqrt(i)); x++)
        {
            int temp = x * x;
            if (temp > i)
                break;
            else
                dp[i] = min(dp[i], 1 +
                                  dp[i - temp]);
        }
    }
 
    // Store result and free dp[]
    int res = dp[n];
    delete[] dp;
 
    return res;
}
int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << getMinSquares(n) << endl;
        
    }
    return 0;
}

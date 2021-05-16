/* You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make a change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
W can be pretty large so output the answer % mod(10^9 + 7)
Input Format
First line will contain T (number of test case), each test case is consists of 3 three lines.
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
For each test case print the number of ways (W) % mod(10^9 +7) in new line.
Constraints :
1 <= T <= 10
1 <= N <= 10
1 <= V <= 5000

*/





#include<bits/stdc++.h>
using namespace std;

long long m = 1000000000 + 7;
#define mod 1000000007


int count( int S[], int m, int n )
{
    int i, j, x, y;
 
    // We need n+1 rows as the table
    // is constructed in bottom up
    // manner using the base case 0
    // value case (n = 0)
    int table[n + 1][m];
     
    // Fill the enteries for 0
    // value case (n = 0)
    for (i = 0; i < m; i++)
        table[0][i] = 1;
 
    // Fill rest of the table entries
    // in bottom up manner
    for (i = 1; i < n + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;
            
 
            // Count of solutions excluding S[j]
            y = (j >= 1) ? table[i][j - 1] : 0;
 			
            // total count
            
            table[i][j] = (x + y)%mod;
        }
    }
    return table[n][m - 1];
}
 
// Driver Code
int main()
{
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        int arr[m];
        for(int i=0; i<m; i++){
            cin >> arr[i];
        }
        int n;
        cin >> n;
        cout << count(arr, m, n) << endl;
    }
    /*int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    cout << count(arr, m, n);*/
    return 0;
}

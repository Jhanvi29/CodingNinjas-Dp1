/*				PROBLEM STATEMENT
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format
Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house
Output Format
 Line 1 : Maximum amount of money looted
Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4
Sample Input :
6
5 5 10 100 10 5
Sample Output 1 :
110
*/


#include<bits/stdc++.h>
using namespace std;

int maxMoney(int arr[], int n){
    
    if(n==0){
        return 0;
    }
    int dp[n+1];
    dp[0] = 0;
    dp[1] = arr[0];
    
    for(int i=1; i<n; i++){
        dp[i+1] = max(dp[i], arr[i]+dp[i-1]);
    }
    
    return dp[n];
}
int main(){
    
    // write your code here
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    cout << maxMoney(arr,n);
    return 0;
}

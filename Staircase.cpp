/* A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large print the answer % mod(10^9 +7) */

#include<bits/stdc++.h>
using namespace std;

long long m = 1000000000 + 7;

long long countWays(long long n)
{
	long long res[n + 1];
	res[0] = 1;
	res[1] = 1;
	res[2] = 2;
	for (int i = 3; i <= n; i++){
		res[i] = res[i - 1] + res[i - 2]
				+ res[i - 3];
        res[i] = res[i] % m;}

	return res[n]%m;
}



int main(){
    
    
    // write your code here
    int t;
    cin >> t;
    while(t--){
        long long steps;
        cin >> steps;
        cout << countWays(steps) << endl;
    }
    return 0;
}

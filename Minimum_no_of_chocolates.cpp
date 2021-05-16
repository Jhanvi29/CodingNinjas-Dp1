/*
Noor is a teacher. She wants to give some chocolates to the students in her class. All the students sit in a line and each of them has a score according to performance. Noor wants to give at least 1 chocolate to each student. She distributes chocolates to them such that If two students sit next to each other then the one with the higher score must get more chocolates. Noor wants to save money, so she wants to minimise the total number of chocolates.
Note that when two students have equal score they are allowed to have different number of chocolates.
Input Format:
First line will contain T(number of test case), each test case consists of two lines.
First Line: Integer N, the number of students in Noor’s class. 
Second Line: Each of the student's score separated by spaces.
Output Format:
Output the minimum number of chocolates Noor must give for each test case in a newline.
Input Constraints
1 <= T <= 50
1 <= N <= 50000
1 <= score <= 10^9
Sample Input:
1
4
1 4 4 6
sample Output:
6
Sample Input:
1
3
8 7 5
sample Output:
6
*/


#include <bits/stdc++.h>

using namespace std;

int rate [100000 + 10];
long long values [100000 + 10];   // use long long

int main()
{   
    int t;
    cin >> t;
    while(t--){
    int n;
    long long ans = 0, tmp = 0;

    cin >> n;

    for(int i = 0; i < n; i++) cin >> rate[i];

    values[0] = 1;
                                        // case 1
    for(int i = 1; i < n; i++){         // scan input array from left to right

        if(rate[i] > rate[i - 1]){

            values[i] = values[i - 1] + 1;  // case 1, a

        } else values[i] = 1;               // case 1,b
    }

    ans = values[n - 1];                // case 2

    for(int i = n - 2; i >= 0; i--){ // scan input array from right to left

        if(rate[i] > rate[i + 1]){

            tmp = values[i + 1] + 1;        // case 2, a

        } else tmp = 1;                     // case 2, b

        ans += max(tmp, values[i]);   // maximum of the two values for child (i)
        values[i] = tmp;
    }

    cout << ans << endl ; }

    return 0;
}

/*

An Interesting Sequence Problem Code: INTSEQ
Submit

You are given an integer K

.

Consider an integer sequence A=[A1,A2,…,AN]

.

Define another sequence S
of length N, such that Si=A1+A2+…+Ai for each 1≤i≤N

.

A
is said to be interesting if Ai+Si=K for every 1≤i≤N

.

Find the maximum length of an interesting sequence. If there are no interesting sequences, print 0

.
Input Format

    The first line of input contains an integer T

, denoting the number of test cases. The description of T
test cases follows.
Each test case consists of a single line of input, which contains a single integer K

    .

Output Format

    For each test case, print a new line containing one integer — the maximum length of an interesting sequence for a given value of K

    .

Constraints

    1≤T≤5000

1≤K≤109

Sample Input 1

2
8
4

Sample Output 1

3
2

Explanation

Test Case 1
: Consider the sequence A=[4,2,1]. S=[4,4+2,4+2+1]=[4,6,7]. The sum of the corresponding elements of A and S are 4+4=8, 2+6=8 and 1+7=8. Thus A is an interesting sequence of size 3

.

Test Case 2
: Consider the sequence A=[2,1]. S=[2,2+1]=[2,3]. The sum of the corresponding elements of A and S are 2+2=4 and 1+3=4. Thus A is an interesting sequence of size 2

.

It's guaranteed that, in both examples above, there doesn't exist a longer sequence satisfying the problem constraints.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll k;
		cin>>k;
		int cnt = 0;
		while(k%2==0 && k>0){
			cnt++;
			k/=2;
		}
		cout<<cnt<<endl;
	}
}
**********************************************************************************  Question  *********************************************************************************************************
Given a number n, the task is to find out whether this number is a Smith number or not. A Smith number is a composite number whose sum of digits is equal to the sum of digits of its prime factors.

Example 1:

Input:
n = 4
Output:
1
Explanation:
The sum of the digits of 4 is 4, and the sum of the digits of its prime factors is 2 + 2 = 4.
Example 2:

Input:
n = 378
Output:
1
Explanation:
378 = 21*33*71 is a Smith number since 3+7+8 = 2*1+3*3+7*1.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smithNum() which takes an Integer n as input and returns the answer.

Expected Time Complexity: O(n * log(n))
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 105



***********************************************************************************  Solution  ********************************************************************************************************
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
      void sieve(int n, vector<int> &prime){
        for(int i = 2; i <= sqrt(n); i++){
            if(prime[i] == 1){
                for(int j = i*i; j <= n; j +=i){
                    prime[j] = 0;
                }
            }
        }
        
    }
    
    int sumD(int temp){
        int sum_digits = 0;
        
        while(temp > 0){
            sum_digits += temp % 10;
            temp = temp / 10;
        }
        
        return sum_digits;
        
    }
    
    int sumP(int n, vector<int> &prime){
        int k = n;
        int sum = 0;
        for(int i = 2; i < k; i++){
            if(n < 1)break;
            if(prime[i] == 1){
                while(n % i == 0){
                    n = n/i;
                    sum += sumD(i);
                }
                
            }
        }
        
        return sum;
    }
    
    int smithNum(int n) {
        //Sieve
        vector<int>prime(n+1, 1);
        sieve(n, prime);
        if(prime[n] == 1)return 0;
        
        //Sum of Digits
        int sum_digits = sumD(n);
        
        //Sum of primefactors
        int sum = sumP(n, prime);
        
        if(sum == sum_digits)return 1;
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends

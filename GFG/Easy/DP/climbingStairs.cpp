#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int ways(int dp[], int n)
    {
        // memoization
        if (dp[n] != -1)
            return dp[n] % 1000000007;
        if (n == 1 || n == 0)
            return dp[n] = 1;
        else
            dp[n] = (ways(dp, n - 1) % 1000000007 + ways(dp, n - 2) % 1000000007) % 1000000007;
        return dp[n] % 1000000007;
    }
    int nthPoint(int n)
    {
        // Code here
        int dp[n + 1];
        // memset() is used to fill a block of memory with a particular value.
        memset(dp, -1, sizeof dp);
        ways(dp, n);
        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cout << "Enter no. of testcases: ";
    cin >> T;
    while (T--)
    {
        int n;
        cout << "Enter the value of nth stair: ";
        cin >> n;
        Solution ob;
        int ans = ob.nthPoint(n);
        cout << ans << "\n";
    }
    return 0;
}
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        // code here : Tabulation Method
        vector<vector<bool>> tabulation(arr.size(), vector<bool>(sum + 1, 0)); // tabulation
        // base case: Bottom Up Approach
        for (int i = 0; i < arr.size(); i++) // sum is zero --> got our expected sum
            tabulation[i][0] = true;
        if (arr[0] <= sum) // the element is not greater than sum
            tabulation[0][arr[0]] = true;
        for (int index = 1; index < arr.size(); index++)
            for (int target = 1; target < sum + 1; target++)
            {
                bool not_take = tabulation[index - 1][target];
                bool take = false;
                if (arr[index] <= target) // if element is not greater than target
                    take = tabulation[index - 1][target - arr[index]];
                tabulation[index][target] = take | not_take;
            }
        return tabulation[arr.size() - 1][sum];
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
        int N, sum;
        cout << "Enter no. of elements in an array: "<<endl;
        cin >> N;
        vector<int> arr(N);
        cout << "Enter elements: ";
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cout << "Type the targeted sum: "<<endl;
        cin >> sum;

        Solution ob;
        if(ob.isSubsetSum(arr, sum))
            cout << "Yes! The subset exists which has "<< sum << "." << endl;
        else cout << "No! Subset doesn't exists which has "<< sum << "." << endl;
    }
    return 0;
}
// } Driver Code Ends
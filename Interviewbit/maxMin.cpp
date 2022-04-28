#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxMin(vector<int> &A)
    {
        int N = A.size();
        sort(A.begin(), A.end());
        return A[0] + A[N - 1];
    }
};
// driver code
int main()
{
    int T;
    cout << "Enter no. of testcases: ";
    cin >> T;
    while (T--)
    {
        int N;
        cout << "Enter no. of elements in an array: " << endl;
        cin >> N;
        vector<int> arr(N);
        cout << "Enter elements: ";
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        int sum = ob.maxMin(arr);
        cout << "Sum of is " << sum << "." << endl;
    }
    return 0;
}
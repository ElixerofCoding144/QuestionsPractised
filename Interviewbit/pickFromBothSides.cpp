#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int pickFromBothSides(vector<int> &A, int N, int B)
        {
            if(B > N)
                return -1; 
            int leftSum = 0;
            //getting the sum of first B elements from the left
            for(int i = 0; i < B; i++)
                leftSum += A[i];
            int max_Sum = leftSum, sum = leftSum;
            
            for(int right = N-1, left = B - 1; right >= 0 && left >= 0; right--, left--)
            {
                sum += A[right];
                sum -= A[left];
                max_Sum = max(max_Sum, sum);
            }
            return max_Sum;
        }
};

//driver code
int main()
{
    int T;
    cout << "Enter no. of testcases: ";
    cin >> T;
    while (T--)
    {
        int N, B;
        cout << "Enter no. of elements in an array: "<<endl;
        cin >> N;
        vector<int> arr(N);
        cout << "Enter elements: ";
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cout << "Enter no. of elements to pick: "<<endl;
        cin >> B;
        Solution ob;
        int sum = ob.pickFromBothSides(arr, N, B);
        cout << "Maximum Sum is "<< sum << "." << endl;
    }
    return 0;
}
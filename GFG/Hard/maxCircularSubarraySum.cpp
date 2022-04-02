#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int max_kadane(int A[], int n)
    {
        int max_final = INT_MIN, sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += A[i];
            max_final = max(max_final, sum);
            if (sum < 0) sum = 0;
        }
        return max_final;
    }
    
    int min_kadane(int A[], int n)
    {
        int min_final = INT_MAX, sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += A[i];
            min_final = min(min_final, sum);
            if(sum > 0) sum = 0;
        }
        return min_final;
    }
    
    int circularSubarraySum(int arr[], int num){
        // your code here
        if(num == 1) return arr[0];
        int sum = 0;
        for (int i = 0; i < num; i++) 
            sum += arr[i];
        int max_final = max_kadane(arr, num);
        //cout << max_final << endl;
        int min_final = min_kadane(arr, num);
        //cout << min_final << endl;
        if(sum-min_final == 0) return max_final;
        return max(max_final, sum-min_final);
    }
};

int main()
 {
	int T;
	cout<<"Test Case: "<<endl;
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    cout << "Size of array: "<<endl;
	    cin>>num;
	    int arr[num];
	    
	    cout << "Insert elements"<<endl;
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}	
	return 0;
}
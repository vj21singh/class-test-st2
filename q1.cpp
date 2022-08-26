// Name : Vijay Singh
// Roll no: 2010991772
// /set : 5
// Q1 : Given an integer array, find the maximum length subarray having a given sum
#include<bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(int arr[], int n, int k)
{
    //creating map m1 to store values
    unordered_map<int, int> m1;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++)
    {

        sum += arr[i];

        // check if the subarray starts from index 0
        if (sum == k)
            maxLen = i + 1;

        // making  an entry for sum if it isn't   present in map m1
        if (m1.find(sum) == m1.end())
            m1[sum] = i;

        // here we check if (sum - k) is present in map m1 or not
        if (m1.find(sum - k) != m1.end())
        {
            // if not present then update maxLength
            if (maxLen < (i - m1[sum - k]))
                maxLen = i - m1[sum - k];
        }
    }

    // returning maximum length of the sub array
    return maxLen;
}

int main()
{
    // Taking n i.e size of array as input
    int n;
    cin >> n;

    // initialize array of size n
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    // target elemet to be checked
    int t;
    cin >> t;

    //var to store length
    int ans;

    //Using try and catch block for exception handeling
    try
    {
        ans = lenOfLongSubarr(arr, n, t);
        if (!ans)
        {
            throw("No subarray found");
        }
            
    }
    catch (int error)
    {
        cout << "Error: " << error << endl;
    }

    cout << "The longest subarray having length= " << ans;
    return 0;
}
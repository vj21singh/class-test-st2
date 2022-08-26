// Name : Vijay Singh
// Roll no: 2010991772
// /set : 5
// Q2 : Print all subarrays with 0 sum


#include <bits/stdc++.h>
using namespace std;

// Function to print all subarrays in the array which has sum 0
vector<pair<int, int>> findSubArrays(int arr[], int n)
{
    // create a map
    unordered_map<int, vector<int>> map;

    // creating a vector of pairs to store subarray from  starting and ending index
    vector<pair<int, int>> output;

    // Maintains sum of elements so far
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        // addinng current element to sum
        sum += arr[i];

        // if sum is 0, we found a subarray starting from index 0 and ending at index i
        if (sum == 0)
            output.push_back(make_pair(0, i));

        // If sum already exists in the map there exists at-least one subarray ending at index i with 0 sum
        if (map.find(sum) != map.end())
        {
            // storing index of all the subarray in map[sum]
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                output.push_back(make_pair(*it + 1, i));
        }

        map[sum].push_back(i);
    }

    // returning output vector
    return output;
}

//  function to print all subarrays having sum 0
void print(vector<pair<int, int>> out, int arr[])
{
    for (auto it = out.begin(); it != out.end(); it++)
    {
        for (int i = it->first; i <= it->second; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
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

    // creating vecctor for output
    vector<pair<int, int>> output;

    // using try catch block for exception handeling
    try
    {
        output = findSubArrays(arr, n);
        if (output.size() == 0)
            throw(0);
    }
    catch (int size)
    {
        cout << "Size is " << size << endl;
    }

    // if no  subarray with 0 sum exist , then return subarray doesn’t exists
    if (output.size() == 0)
        cout << "No subarray exists";
    else
        print(output, arr);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int ans(int arr[], int n, int k)
{
    int i = 0, j = 0;
    long maxi = INT_MIN;
    long sum = 0;

    while (j < n)
    {
        sum += arr[j];

        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            maxi = max(maxi, sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return maxi;

    // int sum = 0;
    // for (int i = 0; i < k; i++)
    // {
    //     sum += arr[i];
    // }
    // int max = sum;
    // for (int i = k; i < n; i++)
    // {
    //     sum += arr[i] - arr[i - k];
    //     if (sum > max)
    //     {
    //         max = sum;
    //     }
    // }
    // return max;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << ans(arr, n, k) << endl;
    return 0;
}
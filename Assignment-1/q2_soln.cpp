#include <bits/stdc++.h>
using namespace std;

int minSubArray(int arr[], int low, int high) {
    if(low==high)
        return arr[low];
    int mid = (low+high)/2;
    int left = minSubArray(arr, low, mid);
    int right = minSubArray(arr, mid+1, high);

    int sum = 0;
    int leftSum = INT_MAX;

    for(int i=mid; i>=low; i--) {
        sum+=arr[i];
        if(sum<leftSum)
            leftSum = sum;
    }
    sum = 0;
    int rightSum = INT_MAX;
    for(int i=mid + 1; i<=high; i++) {
        sum+=arr[i];
        if (sum<rightSum)
            rightSum = sum;
    }
    int cross = leftSum+rightSum;
    return min(left, min(right, cross));
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<minSubArray(arr, 0, n-1);
    return 0;
}

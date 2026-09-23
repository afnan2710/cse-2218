#include <iostream>
#include <algorithm>
using namespace std;

int findMinDiff(int A[], int N, int M)
{
    sort(A, A+N);
    int minDiff = A[M-1] - A[0];
    for (int i=1; i<=N-M; i++)
    {
        int diff = A[i+M-1] - A[i];
        if (diff < minDiff)
            minDiff = diff;
    }
    return minDiff;
}

int main()
{
    int N, M;
    cout<<"input N and M: ";
    cin>>N>>M;
    int A[N];
    cout<<"input chocolates in each packet: ";
    for (int i=0; i<N; i++)
        cin>>A[i];
    int result = findMinDiff(A, N, M);
    cout<<"Min difference: "<<result<<endl;
    return 0;
}

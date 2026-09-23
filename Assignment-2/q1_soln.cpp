#include <iostream>
using namespace std;

int minimumDays(int S, int N, int M) {
    if (N < M)
        return -1;
    int totalFood = S*M;
    int buyingDays = S-(S/7);
    if (totalFood>buyingDays*N)
        return -1;
    int days = totalFood/N;
    if (totalFood%N!=0)
        days++;
    return days;
}

int main() {
    int S = 10;
    int N = 20;
    int M = 30;
    int result = minimumDays(S, N, M);
    cout<<"Minimum number of days to buy food: "<<result<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArrays(vector<int> &A, vector<int> &B) {
    /*
    Algorithm:
    Firstly creating space for array B at the end of Array A.
    Starting from last I start comparing elements and arrange them in decreasing order in array A.
    */
    int indexA = A.size() - 1,indexB = B.size() - 1;
    int k = indexA + indexB + 1;
    for(int i = indexA; i <= k ; i++)
    {
        A.push_back(INT_MIN);
    }
    while(indexB >= 0)
    {
        if(A[indexA] > B[indexB])
        {
            A[k] = A[indexA];
            indexA--;
        }
        else
        {
            A[k] = B[indexB];
            indexB--;
        }
        k--;
    }
    return A;
}

/*
Time Complexity: O(m + n)
Space Complexity: O(m + n)
Input Format

Length of Array1
Sorted Array1 elements seperated by space

Length of Array2
Sorted Array2 elements seperated by space

Example:

5
1 3 5 6 8 (Array1)
3 
0 2 10 (Array2)


*/

int main() {
    int lenA, lenB;
    vector<int> A,B;
    cin>> lenA;
    for(int i = 0; i < lenA; i++)
    {
        int input;
        cin >> input;
        A.push_back(input);
    }
    
    cin >> lenB;
    for(int i = 0; i < lenB; i++)
    {
        int input;
        cin >> input;
        B.push_back(input);
    }
    if(lenA == 0)
    {
        A = B;
    }
    else if(lenB == 0)
    {
        //ok
    }
    else
    {
        mergeSortedArrays(A, B);
    }
    for(int i =0 ; i < lenA +lenB ; i++ )
    {
        cout << A[i] << " ";
    }
}

#include<bits/stdc++.h>
using namespace std;
#define N 5

int findMaxValue(int mat[][N]){
    int maxValue = INT_MIN;
    // maxArr[i][j] stores max of elements in matrix 
    // from (i, j) to (N-1, N-1)
    int maxArr[N][N];
    // last element of maxArr will be same's as of 
    // the input matrix 
    maxArr[N-1][N-1] = mat[N-1][N-1];

    // preprocess last row
    int maxv = mat[N-1][N-1]; // Initialize max.
    for(int j=N-2; j>=0; j--){
        if(mat[N-1][j] > maxv)
            maxv = mat[N-1][j];
        maxArr[N-1][j] = maxv;
    }
    // preprocess last column.
    maxv = mat[N-1][N-1];
    for(int i=N-2; i>=0; i--){
        if(mat[i][N-1] > maxv)
            maxv = mat[i][N-1];
        maxArr[i][N-1] = maxv;
    }
    // preprocess rest of matrix from the bottom.
    for(int i=N-2; i>=0; i--){
        for(int j=N-2; j>=0; j--){
            // update max value
            if(maxArr[i+1][j+1] - mat[i][j] > maxValue)
                maxValue = maxArr[i+1][j+1] - mat[i][j];
            maxArr[i][j] = max(mat[i][j], max(maxArr[i][j+1], maxArr[i+1][j]));

        }
    }
    return maxValue;
}

int main(){
    int mat[N][N] = {
                { 1, 2, -1, -4, -20 }, 
                { -8, -3, 4, 2, 1 }, 
                { 3, 8, 6, 1, 3 }, 
                { -4, -1, 1, 7, -6 }, 
                { 0, -4, 10, -5, 1 }
                };
    cout<<"Maximum value is "<< findMaxValue(mat);
    return 0;
}
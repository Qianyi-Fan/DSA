#include "solve.h"
#include<cstdio>


void Solver1::initialize(int *matrix, int *sum, int n, int m, int arrayN, int arrayM){
    Matrix = matrix;
    Sum = sum;
    N = n;
    M = m;
    ArrayN = arrayN;
    ArrayM = arrayM;
}

void Solver2::initialize(int *matrix, int *sum, int n, int m, int arrayN, int arrayM){
    Matrix = matrix;
    Sum = sum;
    N = n;
    M = m;
    ArrayN = arrayN;
    ArrayM = arrayM;
    for(int i=1;i<=n;++i){
        sum[i*arrayM + 0] = 0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            sum[i*arrayM + j] = sum[i*arrayM + j - 1] + matrix[i*arrayM + j];
    
        }
    }



}


int Solver1::solve(Task task){
    int ans = 0;
    for(int j=0;j<task.a;++j){
        for(int k=0;k<task.b;++k){
            ans += Matrix[(task.x+j)*ArrayM + (task.y+k)];
            // it means "sum += matrix[x+j][y+k];"
        }
    }
    return ans;
}

int Solver2::solve(Task task){
    int ans = 0;
    for(int j=0;j<task.a;++j){
        ans += (Sum[(task.x+j)*ArrayM +  (task.y+task.b-1)] - Sum[(task.x+j)*ArrayM + (task.y-1)]);
        //it means "sum += rowsum[x+j][y+b] - rowsum[x+j][y];"
    }
    return ans;
}

#pragma once

struct Task{
    int x,y,a,b;
    Task(int X, int Y, int A, int B):
        x(X), y(Y), a(A), b(B){}
};


class Solver {
public:
    int* Matrix;
    int* Sum;
    int N, M, ArrayN, ArrayM;
    virtual void initialize(int *matrix, int *sum, int n, int m, int arrayN, int arrayM) = 0;
    virtual int solve(Task task) = 0;

};

class Solver1 : public Solver {
public:
    virtual void initialize(int *matrix, int *sum, int n, int m, int arrayN, int arrayM) override;
    virtual int solve(Task task) override;
};

class Solver2 : public Solver {
public:
    virtual void initialize(int *matrix, int *sum, int n, int m, int arrayN, int arrayM) override;
    virtual int solve(Task task) override;
};



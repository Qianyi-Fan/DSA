#include<cstdio>
#include<cstdlib>
#include "solve.h"
const int maxn = 2000;
int matrix[maxn][maxn];
int sum[maxn][maxn];

int main(int argc, char** argv){
    int n,m,q;
    int cmdline_arg = 0;
    if(argc >= 1){
        cmdline_arg = atoi(argv[1]); 
    }
    if(cmdline_arg!=1 && cmdline_arg!=2){
        return -1;
    }

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%d",&matrix[i][j]);
        }
    }

    

    Solver* solver;
    if (cmdline_arg == 1) {
        solver = new Solver1();
    } else {
        solver = new Solver2();
    }

    solver->initialize(matrix[0], sum[0], n, m, maxn, maxn);


    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        int x,y,a,b;
        scanf("%d %d %d %d",&x,&y,&a,&b);
        int sum;
        sum = solver->solve(Task(x,y,a,b));
        printf("%d\n",sum);

    }
    return 0;
}
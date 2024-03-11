#include<cstdio>
const int maxn = 2000;
int matrix[maxn][maxn];
int main(){
    int n,m,q;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){     //矩阵原点应是（0，0）
        for(int j=0;j<m;++j){
            scanf("%d",&matrix[i][j]);
        }
    }
    scanf("%d",&q);
    
    for(int i=1;i<=q;++i){
        int x,y,a,b;
        int sum = 0;
        scanf("%d %d %d %d",&x,&y,&a,&b);
        for(int j=0;j<a;++j){
            for(int k=0;k<b;++k){

                    //每次重新赋值sum
                sum += matrix[x+j-1][y+k-1];  //正确匹配
                // printf("sum = %d ", sum);
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
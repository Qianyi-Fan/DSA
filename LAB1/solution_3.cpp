#include<cstdio>
const int maxn = 2001;
int matrix[maxn][maxn];
long long ULsum[maxn][maxn];
int main(){
    int n,m,q;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){   //同1
            scanf("%d",&matrix[i][j]);
        }
    }

    for(int i=0;i<=n;++i){
        ULsum[i][0] = 0;}
    for(int j=0;j<=m;++j){
        ULsum[0][j] = 0;}


    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            ULsum[i][j] =   matrix[i][j]  +   ULsum[i][j-1] + ULsum[i-1][j] - ULsum[i-1][j-1];
        }
    }

    scanf("%d",&q);
    
    for(int i=1;i<=q;++i){
        int x,y,a,b;
        long long sum = 0;
        scanf("%d %d %d %d",&x,&y,&a,&b);

        sum = (ULsum[x+a-1][y+b-1] - ULsum[x+a-1][y-1] - ULsum[x-1][y+b-1] + ULsum[x-1][y-1]);
        printf("%lld\n",sum);
    }
    return 0;
}



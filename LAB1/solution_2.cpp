#include<cstdio>
const int maxn = 2001;
int matrix[maxn][maxn];
long long rowsum[maxn][maxn];
int main(){
    int n,m,q;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){  
            scanf("%d",&matrix[i][j]);
        }
    }

    for(int i=0;i<=n;++i){
        rowsum[i][0] = 0;}
    for(int j=0;j<=m;++j){
        rowsum[0][j] = 0;}

    for(int i=1;i<=n;++i){
        // rowsum[i][0] = matrix[i][0];
        for(int j=1;j<=m;++j){
            rowsum[i][j] = rowsum[i][j-1] + matrix[i][j];
        }

    }
    scanf("%d",&q);
    
    for(int i=1;i<=q;++i){
        int x,y,a,b;
        long long sum = 0; 
        scanf("%d %d %d %d",&x,&y,&a,&b);
        for (int i=0; i<a; i++){
        sum += (rowsum[x+i][y+b-1] - rowsum[x+i][y-1]);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
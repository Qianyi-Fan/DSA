#include <iostream>



void merge( int arr[], int lo, int mi, int hi ) { //lo < mi < hi
    int i = 0; 
    int* A = arr + lo; //A = _elem[lo, hi)
    int j = 0; 
    int lb = mi - lo;
    int* B = new int[lb]; //B[0, lb) <-- _elem[lo, mi)

    for ( int i = 0; i < lb; i++ ) {
        B[i] = A[i];  //复制出A的前缀
    } 

    int k = 0;
    int lc = hi - mi;
    int* C = arr + mi;
    //后缀C[0, lc) = _elem[mi, hi)，就地
    
    while ( ( j < lb ) && ( k < lc ) ){ //反复地比较B、C的首元素
        A[i++] = ( B[j] <= C[k] ) ? B[j++] : C[k++];  //小者优先归入A中
    } 
    while ( j < lb ) {  //若C先耗尽，则
        A[i++] = B[j++];   //将B残余的后缀归入A中
    } 
    while ( k < lc ) {  //若B先耗尽，则
        A[i++] = C[k++];   //将C残余的后缀归入A中
    } 
    delete[] B;
}

void mergeSort( int arr[], int lo, int hi ) {
    if ( hi - lo < 2 ) return; //单元素区间自然有序，否则...
    int mi = (lo + hi) >> 1; //以中点为界
    mergeSort( arr, lo, mi ); //对前半段排序
    mergeSort( arr, mi, hi ); //对后半段排序
    merge( arr, lo, mi, hi ); //归并
}

int binSearch( int* arr_x, int* arr_y, int const & x, int const & y, int lo, int hi ) {
    while ( lo < hi ) {     //不变性：[0, lo) <= e < [hi, n)
        int mi = (lo + hi) >> 1;

        // printf("mi = %d\n", mi);
        long long z = (long long)(arr_x[mi])*( y- arr_y[mi]) + (long long)(arr_y[mi])* (x);
        // printf("z = %lld\n", z);
        z < 0 ? hi = mi : lo = mi + 1; //[lo, mi)或(mi, hi)，[mi]或被遗漏？

    } //出口时，区间宽度缩短至0，且必有[lo = hi] = M
    return lo; 
}



int main(){
    int n,m;  //n 条直线、m 个点
    scanf("%d %d", &n, &m);
    int arr_x[n], arr_y[n];
    for (int i = 0; i < n; i++){
        scanf("%d %d", &arr_x[i], &arr_y[i]);
    }
    mergeSort(arr_x, 0, n);
    mergeSort(arr_y, 0, n);

    for (int i = 0; i < m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        int result = binSearch(arr_x, arr_y, x, y, 0, n);
        printf("%d\n", result);
    }


}
int singleNumber(int* a, int n) {
    int res=0;
    for(int i=0;i<n;i++){
        res=res^a[i];
    }
    return res;

}
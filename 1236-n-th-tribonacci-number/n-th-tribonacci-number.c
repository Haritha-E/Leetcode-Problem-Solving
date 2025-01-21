int tribonacci(int n) {
    if(n==0 || n==1) return n;
    if(n==2) return 1;
    int f0=0, f1=1, f2=1, c=0;
    for(int i=3;i<=n;i++){
        c=f0+f1+f2;
        f0=f1;
        f1=f2;
        f2=c;
    }
    return c;
}
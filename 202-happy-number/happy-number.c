bool isHappy(int n) {
    int sum,i=0;
    while(i<10){
        sum=0; 
        while(n!=0){
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        n=sum;
        if(sum==1)
            return true;
        i++;
    }
    return false;
}
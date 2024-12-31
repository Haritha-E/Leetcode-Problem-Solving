bool isHappy(int n) {
    int sum=0;
    while(1){
      sum=0; 
      while(n!=0){
        sum+=(n%10)*(n%10);
        n=n/10;
      }
      if(sum>9)
         n=sum;
      else
        break;
    }
    if(sum==1 || sum==7)
        return true;
    else
        return false;
}
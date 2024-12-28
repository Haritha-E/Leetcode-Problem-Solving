int findMin(int* a, int n) {
    int left=0, right=n-1;
    if(a[0] < a[right])
        return a[0];
    while(left<right){
        int mid=(left+right)/2;
        if(a[mid] > a[mid+1])
            return a[mid+1];
        else if(a[mid-1] > a[mid])
            return a[mid];
        else if(a[mid] > a[0])
            left=mid+1;
        else
            right=mid-1;
    }
    return a[0];
}
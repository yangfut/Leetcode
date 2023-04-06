int search(int* nums, int numsSize, int target){
    if(numsSize == 1) return (nums[0] == target) ? 0 : -1;

    int st = 0;
    int ed = numsSize;
    int pivotIdx = (st+ed)/2;
    int pivot = *(nums+pivotIdx);

    while(ed-st>1){
        if (pivot == target)
            return pivotIdx;
        else if (pivot>target)
            ed = pivotIdx;
        else if (pivot<target)
            st = pivotIdx;
        
        pivotIdx = (st+ed)/2;
        pivot = *(nums+pivotIdx);
    }
    return (nums[st] == target) ? st : -1;
}
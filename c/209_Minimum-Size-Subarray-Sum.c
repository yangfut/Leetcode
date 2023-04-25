int minSubArrayLen(int target, int* nums, int numsSize){
	
	//Sliding window
	int minLen = numsSize + 1;
	int curr = 0;

	for(int st = 0, ed = 0; ed < numsSize;){
        if(curr < target){
            curr = curr + nums[ed];
        }

        while(curr >= target){
            if((ed - st + 1) < minLen){
                if(ed == st) return 1;
                minLen = ed - st + 1;
            }
            curr = curr - nums[st];
            ++st;
        }
        ++ed;
    }		

    if(minLen > numsSize){
        return 0;
    }
    return minLen;
}

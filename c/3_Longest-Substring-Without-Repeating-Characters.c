int lengthOfLongestSubstring(char * s){
    int lengthOfLongestSubstring(char *s){
	
    //Sliding window
    int *asciiMap;
    char *st = s;
    char *ed = s;
    int n = strlen(s);
    int maxLen = 0;
    asciiMap = calloc(128, sizeof(int));

    while(ed < s+n) {
        
        //Valid addon
        if (asciiMap[*ed] == 0) {
            //Expand the window
            asciiMap[*ed] = 1;
            ed++;
            if ((ed - st) > maxLen){
                maxLen = ed - st;
            }
        } else {
            //Strink the window
            asciiMap[*st] = 0;
            st++;
        }
    }
    free(asciiMap);
    return maxLen;
}

    
    
    
    //Naive approach
    /*
    if (*s=='\0') return 0;
    int asciiMap[127] = {0};
    int idx = 0;
    int maxSubLen = 1;
    char *head = s, *tail = s;
    
    
    while(*head){
        tail = head;
        while(*tail){
            if(asciiMap[*tail]==0){
                asciiMap[*tail]=1;
                tail++;
            }else{
                break;
            }
        }
        maxSubLen = ((tail - head) > maxSubLen) ? tail-head : maxSubLen;
        for(int idx=0;idx<127;idx++) asciiMap[idx]=0;
        head++;
    }
    return maxSubLen;
    */

}
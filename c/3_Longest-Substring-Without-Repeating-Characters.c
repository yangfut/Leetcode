int lengthOfLongestSubstring(char * s){
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
}
#include <math.h>

int singleNumber(int* nums, int numsSize){
    if (numsSize == 1)
        return *nums;
    int mapSize = 6*10*10*10*10 + 1;
    int offset = 3*10*10*10*10;
    int hashmap[6*10*10*10*10 + 1] = {};
    for (int i = 0; i < numsSize; i++){
        hashmap[*(nums+i) + offset]++;
    }
    
    for (int j = 0; j < mapSize; j++){
        if (hashmap[j] == 0){
            continue;
        }
        if (hashmap[j] == 1){
            return j - offset;
        }
    }
    return 0;
}

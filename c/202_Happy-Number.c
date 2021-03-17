#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int divde_square(int n){
    int s = 0;
    int mod;
    while(n>0){
        mod = n%10;
        n=n/10;
        s += (mod*mod);
    }
    return s;
}

bool isHappy(int n){
    
    int hashmap[731] = {};
    
    if(n==1)
        return true;
    while(true){
        n = divde_square(n);
        if(n==1)
            return true;
        if(hashmap[n]==-1)
            return false;
        hashmap[n]=-1;
    }
}


int main(){
    int num = 7;
    printf("%d", isHappy(num));
    return 0;
}

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    if(n==1) return 1;

    unsigned int st = 0;
    unsigned int ed = n;
    unsigned int mid = (ed+st)/2;
    /*
    int leads signed integer overflow.

    Data Type           Bytes   Range
    short int	        2	    -32,768 to 32,767
    unsigned short int	2	    0 to 65,535
    unsigned int	    4	    0 to 4,294,967,295
    int	                4	    -2,147,483,648 to 2,147,483,647
    long int	        4	    -2,147,483,648 to 2,147,483,647
    unsigned long int	4	    0 to 4,294,967,295
    signed char	        1	    -128 to 127
    unsigned char	    1	    0 to 255
    float	            4	    1.2E-38 to 3.4E+38
    double	            8	    2.3E-308 to 1.7E+308
    */
    
    while((ed-st)>1){
        if(isBadVersion(mid)) 
            ed = mid;
        else
            st = mid;
        mid = (ed+st)/2;
    }
    return (isBadVersion(st)) ? st : ed;
}
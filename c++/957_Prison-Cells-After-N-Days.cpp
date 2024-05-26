class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
    
        int t = 0;
        bitset<8> prison;
        for(int i = 0; i < 8; ++i){
          if(cells[i] == 1) prison.set(i);
          if(cells[i] == 0) prison.reset(i);
        }

        unordered_map<bitset<8>,int> pattern;
        vector<bitset<8>> hh;

        while(!pattern.count(prison)){
          hh.push_back(prison);
          bitset<8> org = prison;
          pattern[prison] = t++;
          prison.reset(0);
          prison.reset(7);
          for(int i = 1; i < 7; ++i){
            if(org[i+1] == org[i-1]) prison.set(i);
            else prison.reset(i);
            }
        }
        
        int end_loop = t - 1;
        int start_loop = pattern[prison];
        int loop_size = end_loop - start_loop + 1;
        vector<int> output(8);
        bitset<8> temp;
        if(n < t){
          temp = hh[n];
        }else{
          int a = n - start_loop;
          int b = (a % loop_size);
          temp = hh[b + start_loop];
        }

        for(int i = 0; i < 8; ++i){
          output[i] = temp[i];
        }
        return output;

    }
};
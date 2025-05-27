class Solution{
    public:
       int countBitsFlip(int a, int b){
        
        // Your logic here
        int cnt = 0;
        int c = (a ^ b);
        while (c){
            if ((c&1)){
                cnt++;
            }
            c = (c>>1);
        }
        return cnt;
    }
};

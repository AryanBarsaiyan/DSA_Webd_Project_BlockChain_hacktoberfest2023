//ques link-https://leetcode.com/problems/number-of-1-bits
//TC- 100%
#include <iostream>
using namespace std;
int hammingWeight(uint32_t n){
    int count = 0;
        while(n != 0){
            //checking last bit
            if(n&1){
                count++;
            }
            n = n >> 1;
        }
        return count;
}


int main(){
    uint32_t n;
    cin>>n;
    int c = hammingWeight(n);
    cout<<c<<endl;
}


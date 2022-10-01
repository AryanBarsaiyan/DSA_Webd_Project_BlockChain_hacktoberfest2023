//ques link- https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
//TC- 100%
#include <iostream>
using namespace std;
int subtractProductAndSum(int n) {
    int prod = 1;
    int sum = 0;
        while(n != 0){
            int digits = n % 10;
            prod = prod * digits;
            sum = sum + digits;
            n = n/10;
        }
        int ans = prod - sum;
        return ans;
    }
    int main(){
        int n;
        cin>>n;
        int c =subtractProductAndSum(n);
        cout<<c<<endl;

    }




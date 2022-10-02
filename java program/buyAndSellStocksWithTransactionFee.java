import java.util.*;

class buyAndSellStocksWithTransactionFee{
static int getAns(int[] Arr, int ind, int buy, int n, int fee, int[][] dp ){

    if(ind==n) return 0; //base case
    
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        
    int profit=0;
    
    if(buy==0){// We can buy the stock
        profit = Math.max(0+getAns(Arr,ind+1,0,n,fee,dp), -Arr[ind] + getAns(Arr,ind+1,1,n,fee,dp));
    }
    
    if(buy==1){// We can sell the stock
        profit = Math.max(0+getAns(Arr,ind+1,1,n,fee,dp), Arr[ind] -fee + getAns(Arr,ind+1,0,n,fee,dp));
    }
    
    return dp[ind][buy] = profit;
}


static int maximumProfit(int n, int fee, int[] Arr)
{
    //Write your code here
    
    int dp[][]= new int[n][2];
    
    for(int row[]: dp)
    Arrays.fill(row,-1);
    
    if(n==0) return 0;
    int ans = getAns(Arr,0,0,n,fee,dp);
    return ans;
}

public static void main(String args[]) {

  int prices[] = {1,3,2,8,4,9};
  int n = prices.length;
  int fee = 2;
                                 
  System.out.println("The maximum profit that can be generated is "+
  maximumProfit(n,fee,prices));
}
}

public class TargetSum{

  static int target(int nums[], int s){

    int sum = 0;

    for(int num: nums)
      sum+=num;

    int dp[] = new int[2*sum+1];
    dp[sum] = 1;

    for(int num: nums){

      int next[] = new int[2*sum+1];

      for(int i=0; i<dp.length; i++){
        if(dp[i] == 0) continue;

        next[i+num]+= dp[i];
        next[i-num]+=dp[i];
      }
      dp = next;
    }
    return dp[sum+s];
  }

  public static void main(String[] args){
    int a[] = {1,1,1,1,1};
    int s = 3;

    System.out.println(target(a,s));
  }
}

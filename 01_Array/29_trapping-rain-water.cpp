#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int trappingWater(int arr[], int n){
            int left=0, right=n-1;
            int leftmax=0, rightmax=0;
            int res=0;
            while(left<=right){
                if(arr[left]<=arr[right]){
                    if(arr[left] >= leftmax) leftmax=arr[left];
                    else res +=leftmax-arr[left];
                    left++;
                }
                else{
                    if(arr[right]>=rightmax) rightmax=arr[right];
                    else res+=rightmax-arr[right];
                    right--;
                }
            }
            return res;
        }

};



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        Solution obj;
        cout<<obj.trappingWater(a, n)<<endl;
    }
    return 0;
}
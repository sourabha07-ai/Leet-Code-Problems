class Solution {
public:
   vector<int> searchRange(vector<int>& arr, int target) {
    vector<int> ans(2,-1);

     //first occurance
        int low = 0; int high = arr.size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(arr[mid] == target){
                ans[0] =  mid;
                high = mid -1;
            }else if(arr[mid] < target){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
        
        low = 0,high = arr.size()-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(arr[mid] == target){
                ans[1] =  mid;
                low = mid + 1;
            }else if(arr[mid] < target){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }

        return ans;
        }

};
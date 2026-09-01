class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
    int n = arr.size();
    if(target < arr[0]){
        return 0;
    }
    if(target > arr[n-1]){
        return n;
    }

     int lo_idx = 0, hi_idx = n-1;
     while(lo_idx <= hi_idx){
        int mid = (lo_idx+hi_idx)/2;
        if(arr[mid] > target){
            hi_idx = mid - 1;
        }else if(arr[mid] < target){
            lo_idx = mid + 1;
        }else{
             return mid;
        }
     }

     return lo_idx;
        
    }
};
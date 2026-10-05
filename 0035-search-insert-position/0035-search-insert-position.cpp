class Solution {
public:
   int searchInsert(vector<int> &arr, int target){

    if(target < arr[0]) return 0;
    int n = arr.size();
    if (target > arr[n-1]) return n;

    int low = 0,high = n - 1;

    while(low <= high ){
        int mid = low + (high - low)/2;

        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
   return low;
}
     
};
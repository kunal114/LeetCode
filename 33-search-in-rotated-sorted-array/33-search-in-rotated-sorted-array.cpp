class Solution {
public:
    int pivot(vector<int > arr,int low,int  high){
        
        //No elements in the array
        if(high<low) return -1;
        //1 element in the array
        if(high==low) return low;
        
        int mid = (low + high) / 2; /*low + (high - low)/2;*/
        if (mid < high && arr[mid] > arr[mid + 1])
            return mid;

        if (mid > low && arr[mid] < arr[mid - 1])
            return (mid - 1);

        if (arr[low] >= arr[mid])
            return pivot(arr, low, mid - 1);

        return pivot(arr, mid + 1, high);
    }
    int binary(vector<int> arr, int target, int low , int high){
        
        if (high < low)
        return -1;

        int mid = (low + high) / 2; /*low + (high - low)/2;*/
        if (target == arr[mid])
            return mid;

        if (target > arr[mid])
            return binary(arr, target, (mid + 1), high);

        // else
        return binary(arr, target, low, (mid - 1));
    }
    
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int ind = pivot(arr, 0, n - 1);
 
        // If we didn't find a pivot,
        // then array is not rotated at all
        if (ind == -1)
            return binary(arr,target, 0, n - 1);

        // If we found a pivot, then first compare with pivot
        // and then search in two subarrays around pivot
        if (arr[ind] == target)
            return ind;

        if (arr[0] <= target)
            return binary(arr,target, 0, ind - 1);

        return binary(arr, target, ind + 1, n - 1);
    }
};
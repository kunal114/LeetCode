class Solution {
public:
    void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
        int i, k;
        if(n>0&&m>0){
            for (i = 0; i < n; i++) {
        if (arr1[i] > arr2[0]) {
          int temp = arr1[i];
          arr1[i] = arr2[0];
          arr2[0] = temp;
        }
        int first = arr2[0];
        // insertion sort is used here
        for (k = 1; k < m && arr2[k] < first; k++) {
          arr2[k - 1] = arr2[k];
        }
        arr2[k - 1] = first;
      }
        }
      
       
        k=0;
    for(i=n;i<m+n;i++){
        arr1[i] = arr2[k];
        k++;
    }
    }
};
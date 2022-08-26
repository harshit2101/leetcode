/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int iterativeBinarySearch(MountainArray &mountainArr, int x, int low, int high, int option) {
        int mid;
        
      
        while(low <= high) {
            mid = (low + high) / 2;
            if(mountainArr.get(mid) == x)
                return mid;
           
            if(option == 0) {
                if(mountainArr.get(mid) < x)
                    low = mid + 1;
                else if(mountainArr.get(mid) > x)
                    high = mid - 1;    
            }
           
            else if(option == 1) {
                if(mountainArr.get(mid) < x)
                    high = mid - 1;
                else if(mountainArr.get(mid) > x)
                    low = mid + 1;
            }
        }
        return -1;
    }
    
    int findPeakElement(MountainArray &mountainArr, int n) {
        int low = 0, high = n-1, mid;
        
        
        while(low < high) {
            mid = low + (high-low)/2;
            
            
            if(mountainArr.get(mid) > mountainArr.get(mid+1)) {
                high = mid;
            }
            
            
            if(mountainArr.get(mid) < mountainArr.get(mid+1)) {
                low = mid + 1;
            }
        }
        return high; 
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = findPeakElement(mountainArr, n);
        int found = -1;
        
        
        if(target <= mountainArr.get(peak) and target >= mountainArr.get(0))
            found = iterativeBinarySearch(mountainArr, target, 0, peak, 0);
        
       
        if(found == -1 and target <= mountainArr.get(peak) and target >= mountainArr.get(n-1))
            found = iterativeBinarySearch(mountainArr, target, peak, n-1, 1);
        
        return found;
    }
};
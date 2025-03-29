/*
param nums --> points to 0th index of integer array
param numsSize --> 1-based size of integer array nums such tha (numsSize-1)[nums] gets last element
*/

// Only beat 75% of runtimes on leetcode, this is not the best optimization, only beat the solutions I saw posted for C

int removeDuplicates(int* nums, int numsSize) 
{
    
    int i = 0;
    
    // y is row index (multiples of 2 in 1D array), x is column (0 or 1)
    int y = 0;  // Starting row
    int z;      // Scout pointer
    
    while (y < numsSize) {
        // Place first occurrence (column 0)
        if (i < numsSize) {
            nums[i] = nums[y];
            i++;
        } else {
            break;
        }
        
        // Check for second occurrence (column 1)
        if (y + 1 < numsSize && nums[y] == nums[y + 1]) {
            if (i < numsSize) {
                nums[i] = nums[y + 1];
                i++;
            }
            // Scout ahead with z to skip additional duplicates
            z = y + 2;
            while (z < numsSize && nums[z] == nums[y]) {
                z++;  // Skip all extra duplicates
            }
            y = z;  // Move to next unique number
        } else {
            y++;  // No second occurrence, move to next pair
        }
    }
    
    return i;

}

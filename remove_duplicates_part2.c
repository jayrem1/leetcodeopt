/*
param nums --> points to 0th index of integer array
param len --> 1-based size of integer array nums such tha (len-1)[nums] gets last element
*/

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/solutions/6643714/beats-9836-of-runtimes-by-jdbryan-1g8c
// This version beats 98.36% of runtimes 

#include <string.h>

int removeDuplicates(int* nums, int len) {

    if (len <= 2) return len;
    
    // Linear time complexity for larger cases 
    if(len > 30) 
    {
        int i = 1, w=1, c=1;
        for(;i<len;i++)
        {
            if(nums[i]==nums[i-1]) c++;
            else c=1;
            if(c <= 2) 
            {
                nums[w]=nums[i];
                w++;
            }
        }
        return w;
    }

    // Polynomial time complexity for smaller cases
    int write = 1;
    int count = 1;
    int newLen = len;

    for (int read = 1; read < newLen; read++) {
        if (nums[read] == nums[write - 1]) {
            count++;
            if (count <= 2) {
                if (write != read) {
                    nums[write] = nums[read];
                }
                write++;
            } else {
                memmove(&nums[write], &nums[read + 1], (newLen - read - 1) * sizeof(int));
                newLen--;
                read--;
            }
    } else {
            if (write != read) {
                nums[write] = nums[read];
            }
            write++;
            count = 1;
        }
    }
    return write;
}

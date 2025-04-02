/*
param nums --> points to 0th index of integer array
param numsSize --> 1-based size of integer array nums such tha (numsSize-1)[nums] gets last element
*/

// This version beats 92% of runtimes and uses less memory than 84.95% cases 

int removeDuplicates(int* nums, int numsSize) 
{
    if(numsSize <= 2) return numsSize;
    int i = 1, w=1, c=1;
    for(;i<numsSize;i++)
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

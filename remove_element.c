int removeElement(int* nums, int numsSize, int val) 
{
    int j = 0, i = 0;
    for(; i < numsSize; i++) 
    {
        if(nums[i] != val) 
        {
            nums[j] = nums[i];
            j++;
        }
    }


    return j;
}

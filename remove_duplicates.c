int removeDuplicates(int* nums, int numsSize) {
    int j = 0;
    for (int i = 0; i < numsSize; i++){
        if (nums[j] != nums[i]){
            nums[j + 1] = nums[i];
            j++;
        }
    }
    
    return j + 1;
}

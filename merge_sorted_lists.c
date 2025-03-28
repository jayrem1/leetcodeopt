void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
    if(n == 0) return;
    
    //Combine

    for(m = nums1Size - nums2Size, n = 0; n < nums2Size && m < nums1Size; m++, n++) 
    {
        nums1[m] = nums2[n];
    }

    m = nums1Size-1; // Higher index in pair
    n = m-1; // Lower index in pair

    // Check pairs of numbers from last pair of array to starting pair
    // If (number at lower index > number at higher index) --> swap #s
    int pivot = m;
    int pivotUp = m;
    int tail_end = m;
    int tail_start = 0;
    while(m >= 1) 
    {
        //swap w/o third variable
        //Side by side pair swap
        if(n >= 0 && m <= nums1Size-1 && nums1[n] > nums1[m]) 
        {
            nums1[m] = nums1[m] + nums1[n];
            nums1[n] = nums1[m] - nums1[n];
            nums1[m] = nums1[m] - nums1[n];
        }

        //Tail end swap
        if(tail_start < tail_end && tail_end < nums1Size-1 && nums1[tail_start] > nums1[tail_end]) 
        {
            nums1[tail_start] = nums1[tail_start] + nums1[tail_end];
            nums1[tail_end] = nums1[tail_start] - nums1[tail_end];
            nums1[tail_start] = nums1[tail_start] - nums1[tail_end];
            if(tail_end > nums1Size - nums2Size - 1) {
                tail_end--;
                tail_start++;
            }
            else {
                tail_end = pivot;
                tail_start = 0;
            }
        }

        if(m != 1) 
        {
            m--;
            n--;
            continue;
        }

        // m = 1
        if(pivot != 1) 
        {
            m=pivot;
            n=m-1;
            pivot--;
            continue;
        }

        //pivot = 1
        if(nums1[0] > nums1[1]) 
        {
            nums1[1] = nums1[1] + nums1[0];
            nums1[0] = nums1[1] - nums1[0];
            nums1[1] = nums1[1] - nums1[0];
        }

        if(nums1[nums1Size-2] > nums1[nums1Size-1]) 
        {
            nums1[nums1Size-2] = nums1[nums1Size-2] + nums1[nums1Size-1];
            nums1[nums1Size-1] = nums1[nums1Size-2] - nums1[nums1Size-1];
            nums1[nums1Size-2] = nums1[nums1Size-2] - nums1[nums1Size-1];
        }


        if(pivot == pivotUp) 
        {
            tail_start++;
            for(n = nums1Size-1; n >= 1; n--) 
            {
                if(nums1[n] < nums1[n-1]) 
                {
                    tail_start *= -1; // flag
                }
            }
            if(tail_start < 0) 
            {
                // Reset iterators
                pivot = nums1Size;
                pivotUp = pivot;
                m = nums1Size-1;
                n = m-1;
                tail_end = nums1Size;
                tail_start = 0;
                continue;
            } else 
            {
                break;
            }
        } else 
        {
            pivotUp--;
            m = pivotUp;
            n = pivotUp - 1;
            continue;
        }
        

    }

}

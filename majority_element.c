// In a markdown file, enter ![0..PNG](https://assets.leetcode.com/users/images/59e8e46e-a2e2-40f5-8dd8-c531c1b2ed13_1743563245.2294648.png)
// Beats 100% of runtimes as of April 1st, 2025 
int majorityElement(int* D, int E) 
{
    int A = 0, B=0, C=0;
    for(int C = 0; C < E; C++) 
    {
        if(B==0) A=D[C];
        B += (D[C]==A) ? 1 : -1;
    }
    return A;
} 

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


// { a[n] }
// sum{k=i,k=j}{a[k]}

#define NUMSIZE 9
int nums[NUMSIZE] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

/*
// ---- O(n^2) method-------//
int MaxSubArray(int *nums, int numSize)
{
    int MaxVal = INT_MIN;
    // Progama in here ----------------------//

    int headIdx = 0, idx1 = 0, idx2 = 0;
    int sum;

    for (headIdx = 0; headIdx < numSize; headIdx++)
    {
        sum = 0;
        for(idx1 = headIdx; idx1 < numSize; idx1++)
        {
            sum += nums[idx1];

            if (MaxVal < sum)
            {
                MaxVal = sum;
            }

        }

    }


    //--------------------------------------//
    return MaxVal;
}
*/

//---- Divid and Conquer -----------------//
//  1. Divid Two Part
//  2. Compare three Value : Left Part Max, Right Part Max and Pass the Midimum
//
int MaxSubArray(int *nums, int numSize)
{
    int MaxVal = INT_MIN;
    //Print The Nums in Now.
    // Inital Condition
    if (numSize == 1)
    {
        printf("Max%d\n", nums[0]);
        return nums[0];
    }
    // Progama in here ----------------------//
    int leftMaxVal = MaxSubArray(nums, (numSize / 2));
    int rightMaxVal = MaxSubArray((nums + (numSize / 2)) , numSize - (numSize / 2));


    int leftSubMaxVal = INT_MIN, rightSubMaxVal = INT_MIN;
    int headIdx = ((numSize / 2) - 1), idx1 = 0;
    int sum = 0;
    for (idx1 = headIdx; idx1 >= 0; idx1--)
    {
        sum += nums[idx1];

        if (leftSubMaxVal < sum)
        {
            leftSubMaxVal = sum;
        }

    }

    headIdx = (numSize / 2);
    sum = 0;

    for (idx1 = headIdx; idx1 < numSize; idx1++)
    {
        sum += nums[idx1];

        if (rightSubMaxVal < sum)
        {
            rightSubMaxVal = sum;
        }
    }


    MaxVal = leftSubMaxVal + rightSubMaxVal;

    if (MaxVal < leftMaxVal)
    {
        MaxVal = leftMaxVal;
    }

    if (MaxVal < rightMaxVal)
    {
        MaxVal = rightMaxVal;
    }

    int numsIdx = 0;
    for (numsIdx = 0; numsIdx < numSize; numsIdx++)
    {
        printf("%d, ", nums[numsIdx]);
    }
    printf("\n");
    printf("this seqence max is %d\n", MaxVal);


    //--------------------------------------//
    return MaxVal;
}
int main(void)
{

    int ret = MaxSubArray(nums, NUMSIZE);
    printf("%d\n", ret);






    return 0;
}

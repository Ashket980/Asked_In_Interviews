imum = nums[i + 1];
        }
 
        // update max
        if (maximum > max) {        // 2nd comparison
            max = maximum;
        }
 
        // update min
        if (minimum < min) {        // 3rd comparison
            min = minimum;
        }
    }
 
    // handle the last element if the array has an odd number of elements
 
    if (odd)                        // comparison
    {
        if (nums[n] > max) {         // extra comparison for an odd element
            max = nums[n];
        }
 
        if (nums[n] < min) {         // extra comparison for an odd element
            min = nums[n];
        }
    }
}
 
int main()
{
    vector<int> nums = { 4, 7, 5, 1, 3 };
 
    // to store minimum and maximum element, respectively
    int min, max;
 
    findMinAndMax(nums, min, max);
 
    cout << "The minimum array element is " << min << endl;
    cout << "The maximum array element is " << max << endl;
 
    return 0;
}

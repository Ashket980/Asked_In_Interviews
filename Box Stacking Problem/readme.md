## Box Stacking Problem ##

**Given a set of rectangular 3D boxes (cuboids), create a stack of boxes as tall as possible and return the maximum height of the stacked boxes.**

**A box can be placed on top of another box only if the dimensions of the 2D base of the lower box is each “strictly” larger than of the 2D base of the higher box. 
Note that “multiple” instances of the same box can be used, such that a box can be rotated to use any of its sides as the base, and the solution does not have to include 
the every box to achieve maximum height.**

**Consider the following boxes where each box has dimensions L × W × H:**

    (4 × 2 × 5)
    (3 × 1 × 6)
    (3 × 2 × 1)
    (6 × 3 × 8)
 
**The valid rotations (length more than the width) of the boxes are:**
    
    (4 × 2 × 5), (5 × 4 × 2), (5 × 2 × 4)
    (3 × 1 × 6), (6 × 3 × 1), (6 × 1 × 3)
    (3 × 2 × 1), (3 × 1 × 2), (2 × 1 × 3)
    (6 × 3 × 8), (8 × 6 × 3), (8 × 3 × 6)

**The maximum height possible is 22, which can be obtained by arranging the boxes in the following order:**

    (3 × 1 × 6)
    (4 × 2 × 5)
    (6 × 3 × 8)
    (8 × 6 × 3)
**Note that (3 × 2 × 1) box is not included to achieve the maximum height.**

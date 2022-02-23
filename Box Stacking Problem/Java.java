import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
 
// A class to store a box (L × W × H)
class Box
{
    // constraint: width is never more than length
    int length, width, height;
 
    private Box(int length, int width, int height) {
        this.length = length;
        this.width = width;
        this.height = height;
    }
 
    public static Box of(int a, int b, int c) {
        return new Box(a, b, c);
    }
}
 
class Main
{
    // Function to generate rotations of all the boxes
    public static List<Box> createAllRotations(List<Box> boxes)
    {
        // stores all rotations of each box
        List<Box> rotations = new ArrayList<>();
 
        // do for each box
        for (Box box: boxes)
        {
            // push the original box: L × W × H
            rotations.add(box);
 
            // push the first rotation: max(L, H) × min(L, H) × W
            rotations.add(Box.of(Math.max(box.length, box.height),
                                Math.min(box.length, box.height),
                                box.width));
 
            // push the second rotation: max(W, H) × Math.min(W, H) × L
            rotations.add(Box.of(Math.max(box.width, box.height),
                                Math.min(box.width, box.height),
                                box.length));
        }
 
        return rotations;
    }
 
    // Create a stack of boxes that is as tall as possible
    public static int findMaxHeight(List<Box> boxes)
    {
        // base case
        if (boxes == null || boxes.size() == 0) {
            return 0;
        }
 
        // generate rotations of each box
        List<Box> rotations = createAllRotations(boxes);
 
        // sort the boxes in descending order of base area (L × W)
        Collections.sort(rotations, (x, y) -> (y.length * y.width -
                                x.length * x.width));
 
        // max_height[i] store the maximum possible height when the i'th box
        // is on the top
        int[] max_height = new int[rotations.size()];
 
        // fill `max_height[]` in a bottom-up manner
        for (int i = 0; i < rotations.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                // dimensions of the lower box are each strictly larger than those
                // of the higher box
                if (rotations.get(i).length < rotations.get(j).length &&
                            rotations.get(i).width < rotations.get(j).width) {
                    max_height[i] = Math.max(max_height[i], max_height[j]);
                }
            }
 
            max_height[i] += rotations.get(i).height;
        }
 
        // return the maximum value in max_height[]
        return Arrays.stream(max_height).max().getAsInt();
    }
 
    public static void main(String[] args)
    {
        // input boxes
        List<Box> boxes = Arrays.asList(Box.of(4, 2, 5), Box.of(3, 1, 6),
                                        Box.of(3, 2, 1), Box.of(6, 3, 8));
 
        System.out.println("The maximum height is " + findMaxHeight(boxes));
    }
}

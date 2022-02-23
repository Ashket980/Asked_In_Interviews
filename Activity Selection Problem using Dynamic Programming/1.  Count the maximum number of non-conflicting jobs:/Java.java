
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
 
// A class to store the start and finish time of the jobs.
class Job
{
    public final int start;     // start field of a job
    public final int finish;    // finish field of a job
 
    // Constructs a new Job with specified values
    private Job(int start, int finish)
    {
        this.start = start;
        this.finish = finish;
    }
 
    // Factory method for creating a Job immutable instance
    public static Job of(int a, int b)
    {
        // calls private constructor
        return new Job(a, b);
    }
}
 
class Main
{
    // Returns the maximum count of non-conflicting jobs that can be performed
    // by a single person
    public static int findNonConflictingJobsLength(List<Job> jobs)
    {
        // Sort the jobs according to increasing order of their start time
        Collections.sort(jobs, Comparator.comparingInt(job -> job.start));
 
        // L[i] stores the maximum count of non-conflicting jobs ending at i'th job
        int[] L = new int[jobs.size()];
 
        for (int i = 0; i < jobs.size(); i++)
        {
            // consider each `j` less than `i`
            for (int j = 0; j < i; j++)
            {
                // L[i] = Math.max(L[j]), where `jobs[j].finish` is less than
                // `jobs[i].start`
                if (jobs.get(j).finish < jobs.get(i).start && L[i] < L[j]) {
                    L[i] = L[j];
                }
            }
 
            // increment L[i] since it ends at the i'th job
            L[i]++;
        }
 
        // return the maximum job length in the list
        return Arrays.stream(L).max().getAsInt();
    }
 
    public static void main(String[] args)
    {
        // Each pair stores the start and the finish time of a job
        List<Job> jobs = Arrays.asList(
                Job.of(1, 4), Job.of(3, 5), Job.of(0, 6),
                Job.of(5, 7), Job.of(3, 8), Job.of(5, 9),
                Job.of(6, 10), Job.of(8, 11), Job.of(8, 12),
                Job.of(2, 13), Job.of(12, 14)
        );
 
        System.out.println("The maximum number of non-conflicting jobs is "
                + findNonConflictingJobsLength(jobs));
    }
}

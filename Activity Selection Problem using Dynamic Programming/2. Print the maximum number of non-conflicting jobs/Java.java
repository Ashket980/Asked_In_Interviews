import java.util.*;
 
// A class to store the start and finish time of the jobs.
class Job
{
    public int start, finish;
 
    Job(int start, int finish)
    {
        this.start = start;
        this.finish = finish;
    }
 
    @Override
    public String toString() {
        return "(" + this.start + ", " + this.finish + ")";
    }
}
 
class Main
{
    // Find the maximum number of non-conflicting jobs that can be performed
    // by a single person
    public static void findNonConflictingJobs(List<Job> jobs)
    {
        // sort the jobs according to increasing order of their start time
        Collections.sort(jobs, Comparator.comparingInt(x -> x.start));
 
        // `L[i]` stores the maximum non-conflicting jobs that end at i'th job
        List<List<Job>> L = new ArrayList<>();
        for (var job: jobs) {
            L.add(new ArrayList<>());
        }
 
        for (int i = 0; i < jobs.size(); i++)
        {
            // consider each `j` less than `i`
            for (int j = 0; j < i; j++)
            {
                // L[i] = Math.max(L[j]), where `jobs[j].finish` is less than
                // `jobs[i].start`
                if (jobs.get(j).finish < jobs.get(i).start &&
                        L.get(i).size() < L.get(j).size()) {
                    L.set(i, new ArrayList<>(L.get(j)));
                }
            }
 
            // `L[i]` ends at i'th job 
            L.get(i).add(jobs.get(i));
        }
 
        // find the list having a maximum size
        List<Job> max = L.stream().max(Comparator.comparingInt(x -> x.size())).get();
 
        // print maximum non-conflicting jobs
        System.out.print(max);
    }
 
    public static void main(String[] args)
    {
        // Each pair stores the start and the finish time of a job
        List<Job> jobs = Arrays.asList(new Job(1, 4), new Job(3, 5),
                new Job(0, 6), new Job(5, 7),
                new Job(3, 8), new Job(5, 9),
                new Job(6, 10), new Job(8, 11),
                new Job(8, 12), new Job(2, 13),
                new Job(12, 14));
 
        findNonConflictingJobs(jobs);
    }
}

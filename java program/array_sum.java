public class parallelWorker extends Thread{
    private int[] nums;
    private int low;
    private int high;
    private int partialSum;

    public parallelWorker(int[] nums,int low,int high)
    {
        this.nums=nums;
        this.low=low;
        this.high=high;
    }

    public int getPartialSum()
    {
        return this.partialSum;
    }

    public void run()
    {
        partialSum=0;

        for(int i=low;i<high;i++)
            partialSum+=nums[i];
    }

}


public class array_sum {
    private parallelWorker[] sums =new parallelWorker[3];

    public int sum(int[] nums)
    {
        int steps=10;
        for(int i=0;i<3;i++)
        {
            sums[i]=new parallelWorker(nums, i*steps, (i+1)*steps);
            sums[i].start();
        }
        try {
            for(parallelWorker worker :sums)
                worker.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        int total=0;

        for(parallelWorker worker :sums)
            total=worker.getPartialSum();

        return total;
    }

}

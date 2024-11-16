using System;

public class Solution {
    public long solution(long n) {

        double sqrt = Math.Sqrt(n);
        
        if (sqrt % 1 == 0) 
        {
            long x = (long)sqrt;
            return (x + 1) * (x + 1);
        } 
        else return -1;
        
    }
}
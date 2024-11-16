using System;

public class Solution {
    public long solution(long n) 
    {
        char[] digits = n.ToString().ToCharArray();
        
        Array.Sort(digits);
        Array.Reverse(digits);
        
        string sortedStr = new string(digits);   
        long answer = long.Parse(sortedStr);
        
        return answer;
    }
}
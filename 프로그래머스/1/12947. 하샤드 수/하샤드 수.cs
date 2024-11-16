using System;

public class Solution {
    public bool solution(int x) 
    {
        char[] num = x.ToString().ToCharArray();
        
        int result = 0;
        for(int i = 0; i < num.Length; i++)
        {
            result += int.Parse(num[i].ToString());
        }
        
        
        return x % result == 0;
    }
}
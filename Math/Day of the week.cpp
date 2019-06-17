int dayofweek(int d, int m, int y) 
{ 
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
    y -= m < 3; 
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7; 
} 

string Solution::solve(int A, int B, int C) 
{
    
    int day = dayofweek(A, B, C);
    
    string data[] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
    
    return data[day];
    
}

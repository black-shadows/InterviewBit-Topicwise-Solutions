vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
   int i;
   vector<Interval> A;
   for(i=0;i<intervals.size();i++)
   {
       if(newInterval.start>intervals[i].start && newInterval.start>intervals[i].end)
       {
           A.push_back(intervals[i]);
       }
       else
           break;
   }
   Interval s;
   if(i!=intervals.size() && intervals[i].start<newInterval.start )
        s.start=intervals[i].start;
    else if(i!=intervals.size())
        s.start=newInterval.start;
   if(i==intervals.size())
   {    s.start=newInterval.start;
        s.end=newInterval.end;
   }
   int f=0;
   while(i<intervals.size())
   {
       if(newInterval.end>=intervals[i].start && newInterval.end<intervals[i].end)
       {
           s.end=intervals[i].end;
           i++;
           f=1;
           break;
       }
       else if(newInterval.end<intervals[i].start )
       {
           s.end=newInterval.end;
           f=1;
           break;
       }
       i++;
   }
   if(f==0)
    s.end=newInterval.end;
   A.push_back(s);
   while(i<intervals.size())
   {
       A.push_back(intervals[i]);
       i++;
   }
   return A;
}
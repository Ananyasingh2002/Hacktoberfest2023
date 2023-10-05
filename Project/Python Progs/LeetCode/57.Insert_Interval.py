def insert(intervals, new_intervals): # Time complexity O(Nlog(N))
    count = 0
    # adding the new intervals to the list of intervals
    intervals = intervals + [new_intervals]
    # sort the intervals
    intervals = sorted(intervals)
    while count < len(intervals) - 1:
        # check [3,5] and [4,8] if end point of i < i+1 so we can swap end points  
        if intervals[count][1] >= intervals[count+1][0] and intervals[count][1] <= intervals[count+1][1]:
            intervals[count][1] = intervals[count+1][1]
            intervals.pop(count+1)
        # check [3,8] and [6,7] are overlapping so make [6,7] pop from intervals 
        elif intervals[count][1] >= intervals[count+1][0] and intervals[count][1] >= intervals[count+1][1]:
            intervals.pop(count+1)
            
        else:
            count += 1
    return intervals

intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
newInterval = [4,8]

print(insert(intervals,newInterval))

# optimized code min and max 
def insert(intervals,newInterval):
    i = 0
    while i < len(intervals):
        if intervals[i][0] < newInterval[i][1]:
            intervals.append(intervals[i])
        elif intervals[i][0] > newInterval[i][1]:
            break
        else:
            # Merge the intervals and new intervals
            intervals[0] = min(intervals[0], newInterval[0])
            intervals[1] = max(intervals[1], newInterval[1])
        i += 1
    intervals.append(newInterval)
    while i < len(intervals):
        print(intervals[i])
        i+=1
    return intervals
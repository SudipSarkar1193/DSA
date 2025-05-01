


```python

('a', 2) < ('b', 1)  # True, কারণ 'a' < 'b'
(1, 'x') < (2, 'a')  # True, কারণ 1 < 2
(2, 'a') < (2, 'b')  # True, কারণ 2 == 2, কিন্তু 'a' < 'b'

```

### Key Take-away :  
**Tuples are compared `lexicographically` in Python.**

### I used the concept in the following problem :

***Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.***

**Note: If a window does not contain a negative integer, then return 0 for that window.**

```python

import heapq 
class Solution:
    def firstNegInt(self, arr, k): 

        N = len(arr)
        l = 0 ;
        res = []
        
        pq = []  # min-heap of (index, value)
        
        for r in range(N) :
            
            if arr[r] < 0 :
                heapq.heappush(pq,(r,arr[r]))
            
            if r - l + 1 == k :
                # Remove elements outside the window
                while pq and pq[0][0] < l:
                    heapq.heappop(pq)
                    
                if pq :
                    res.append(pq[0][1]) 
                    # DO NOT remove the first negative. 
                    # Instead, we should just peek (i.e., use pq[0][1]) 
                    # — the same negative might still be needed for the next window.
                else :
                    res.append(0)  

                l += 1 # Incrementing the left ptr ... increment of right ptr is being taken care by the for-loop
                
        return res      

```
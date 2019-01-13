# Python Implementation of above approach 
import collections 

# function to find minimum area of Rectangle 
def minAreaRect(A): 

	# creating empty columns 
	columns = collections.defaultdict(list) 

	# fill columns with coordinates 
	for x, y in A: 
		columns[x].append(y) 

	lastx = {} 
	ans = float('inf') 

	for x in sorted(columns): 
		column = columns[x] 
		column.sort() 
		for j, y2 in enumerate(column): 
			for i in range(j): 
				y1 = column[i] 

				# check if rectangle can be formed 
				if (y1, y2) in lastx: 
					ans = min(ans, (x - lastx[y1, y2]) * (y2 - y1)) 
				lastx[y1, y2] = x 

	if ans < float('inf'): 
		return ans 
	else: 
		return 0


# Driver code 
# A = [[1, 1], [1, 3], [3, 1], [3, 3], [2, 2]] 
# A = [[0,1],[2,1],[1,1],[1,0],[2,0]]

# print(minAreaRect(A)) 

class Solution:
    def minAreaFreeRect(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """
        return minAreaRect(points)
        
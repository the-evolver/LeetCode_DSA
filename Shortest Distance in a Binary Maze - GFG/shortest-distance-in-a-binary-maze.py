#User function Template for python3

#Back-end complete function Template for Python 3

from typing import List

def isValid(x, y, n, m):
    return x >= 0 and x < n and y >= 0 and y < m

class Solution:
    
    def shortestPath(self, grid: List[List[int]], source: List[int], destination: List[int]) -> int:
        n = len(grid)
        m = len(grid[0])
        dist = [[int(1e9)] * m for i in range(n)]
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        queue = []

        queue.append(source)
        dist[source[0]][source[1]] = 0
      
        while queue:
            currentCell = queue.pop(0)
            currentX = currentCell[0]
            currentY = currentCell[1]
            if currentX == destination[0] and currentY == destination[1]:
                return dist[currentX][currentY]
            for i in range(4):
                nextX = currentX + dx[i]
                nextY = currentY + dy[i]
                if isValid(nextX, nextY, n, m) and grid[nextX][nextY] == 1 and dist[nextX][nextY] == int(1e9):
                    queue.append([nextX, nextY])
                    dist[nextX][nextY] = 1 + dist[currentX][currentY]

        return -1    

#{ 
 # Driver Code Starts
#Initial Template for Python 3

         
if __name__=="__main__":
    for _ in range(int(input())):
        n,m=map(int,input().strip().split())
        grid=[]
        for i in range(n):
            grid.append([int(i) for i in input().strip().split()])
        source = [0] * 2
        source[0], source[1] = map(int,input().strip().split())
        destination = [0] * 2
        destination[0], destination[1] = map(int,input().strip().split())
        obj=Solution()
        print(obj.shortestPath(grid, source, destination))
# } Driver Code Ends
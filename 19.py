import numpy as np

# prompt:

# A builder is looking to build a row of N houses that can be of K different colors. He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.

# Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, return the minimum cost which achieves this goal.
#      c1 | c2 | c3 | c4 | c5 | c6 | c7 | c8 |
# ---------------------------------------------
# h1 |    |    |    |    |    |    |    |    |
# ---------------------------------------------
# h2 |    |    |    |    |    |    |    |    |
# ---------------------------------------------
# h3 |    |    |    |    |    |    |    |    |
# ---------------------------------------------
# h4 |    |    |    |    |    |    |    |    |
# ---------------------------------------------
# h5 |    |    |    |    |    |    |    |    |
# ---------------------------------------------
# h6 |    |    |    |    |    |    |    |    |
# ---------------------------------------------
# h7 |    |    |    |    |    |    |    |    |
# ---------------------------------------------
# h8 |    |    |    |    |    |    |    |    |
# ---------------------------------------------

def matrix_processor(mat):
  runningTotal = 0
  prevColorIndex = [-1]
  for row in mat:
    result = np.amin(row)
    index = np.where(row == result)
    if index[0] != prevColorIndex:
      runningTotal += result
      prevColorIndex = index[0]
    else:
      #make a sorted copy to find the second cheapest option
      copy = row
      copy = np.sort(copy)
      secondLowest = copy[1]
      prevColorIndex = np.where(row == secondLowest)[0]
      runningTotal += secondLowest

  return runningTotal

a = np.array([[2,1,3,2,3], [4,1,3,5,6], [4,1,4,5,6], [4,1,4,5,6]])
print(matrix_processor(a))


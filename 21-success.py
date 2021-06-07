import numpy as numpy

# Prompt:

# Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

# For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.


# solution:

# this isn't an optimized solution, but take an array

def twentyOneProcessor(array):

  counterArray = numpy.zeros(numpy.amax(testingArray), dtype=int)

  for interval in array:
    for i in range(interval[0], interval[1]):
      counterArray[i] += 1
  
  return numpy.amax(counterArray)

#running the solution

testingArray = numpy.array([(30,75),(0,50),(60,150)])

print(twentyOneProcessor(testingArray))

testingArray2 = numpy.array([(0,30),(30,50),(50,70)])

print(twentyOneProcessor(testingArray2))

testingArray3 = numpy.array([(0,100),(30,50),(50,70)])

print(twentyOneProcessor(testingArray3))

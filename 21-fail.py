import numpy as numpy

# Prompt:

# Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

# For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.


# solution:

# iterate from front to back of time intervals

# for each interval, check if any following intervals overlap that one.

# test:
# array = numpy.array([(30,75),(0,50),(60,150)])

# for x in array:
#   print(x)

def overlapping(interval, array, i):
  if array[1] > interval[0] and array[1] < interval[1]:
    return true
  elif array[0] < interval[1] and array[0] > interval[0]:
    return true
  else:
    return false



# def twentyOneProcessor(array):
#   maxTables = 1
#   counter = 0 
#   for interval in array:
#     tables = 1
#     counter += 1
#     curOverlap = numpy.array()
#     for i in range(counter, len(array)):
#       # here is where we make the comparison between the range and all the consecutive ranges
#       print(array[i])
#       if array[i][1] > interval[0] and array[i][1] < interval[1]:
#         tables += 1
#       elif array[i][0] < interval[1] and array[i][0] > interval[0]:
#         tables += 1
#     print("current interval: ", interval, " current tables: ", tables)
#     if tables > maxTables:
#       maxTables = tables
#   return maxTables

  def twentyOneProcessor(array):
  maxTables = 1
  counter = 0 
  for interval in array:
    tables = 1
    counter += 1
    curOverlap = numpy.array()
    for i in range(counter, len(array)):
      # here is where we make the comparison between the range and all the consecutive ranges
      if overlapping(interval, array[i]):
        #to count as a table, there must be overlap between the table at hand, the other overlapping tables, and table if
        all()
        
      
    print("current interval: ", interval, " current tables: ", tables)
    if tables > maxTables:
      maxTables = tables
  return maxTables



testingArray = numpy.array([(30,75),(0,50),(60,150)])

print(twentyOneProcessor(testingArray))


testingArray2 = numpy.array([(0,30),(30,50),(50,70)])

print(twentyOneProcessor(testingArray2))

testingArray3 = numpy.array([(0,100),(30,50),(50,70)])

print(twentyOneProcessor(testingArray3))
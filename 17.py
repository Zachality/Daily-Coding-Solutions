import numpy as numpy

# something I learned: 

# the walrus operator both assigns and returns a value simultaneously

# inputs = list()
# while (current := input("Write something: ")) != "quit":
#     inputs.append(current)

# print(' '.join(inputs))


#problem:

# The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

# dir
#     subdir1
#     subdir2
#         file.ext
# The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

# The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

# dir
#     subdir1
#         file1.ext
#         subsubdir1
#     subdir2
#         subsubdir2
#             file2.ext
# The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

# We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).



#my approach:

# start by creating a tree from any imported string

# once the string has been imported into a tree, navigate it using a recursive algorithmt that can identify the longest path while adding the characters from each level


# class 

class treeBoi:
  def 
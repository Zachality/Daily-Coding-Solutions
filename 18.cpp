#include <iostream>
#include <algorithm>
#include <array>

using namespace std;
/*/
prompt:

Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.

Learned:

O(n):

this is linear time complexity meaning that the time this algorithm takes grows with the size of the inputs. the size of the input array in this case.

-- this allows for single loops, but not nested loops

O(k):

this is constant space complexity meanning that there are a set number of variables that dont increase or decreased based on the size of the input array

strategy:

start at index 0.

compute the max of the first k elements using the max_elements functions which runs linear time

save the subindex in the place of the winner:

in the subarray (10, 5, 2), 10 wins so the array becomes: (1,5,2), because the first element won

now in the second iteration, if that element is not 1, then the algorithm can go straight to the winning elemtn and compare to the next in the k + 1 position.

Here is a simulation, of this weird idea:

array = [10, 5, 2, 7, 8, 7] and k = 3
-------------
first subarray: (10, 5, 2)

10 wins and it is in posiiton 0, so we now have:

[0, 5, 2, 7, 8, 7]

-------------

next subarray (5, 2, 7)

refer to previous datapoint.

it says "0", so that data is not longer present in this subarray. Only values of 1->(k-1) would be in the present subarray. 

so, rerun the max_elements and do the same process. 

[0, 2, 2, 7, 8, 7]

---------------

next subarray (2, 7, 8)

refer to previous datapoint.

it says "2", so that datapoint coresponds to 7 in this case. 

is 7 more or less than the new 8?

less, so 8 is the winner, continue.

[0, 2, 2, 7, 8, 7]

----------------

next subarray (7, 8, 7)

refer to previous datapoint.

it says "3", so that datapoint corresponds to "8".

is "8" more than "7"?

yes. So the winner is 8, continue. 

-------------------

the next point is a null pointer so the loop is over.

/*/

void processor(int arr[], int k) {

int *temp = arr;

int counter = 0;
while (*temp){
  ++counter;
  ++temp;
}

int *max_index = std::max_element(arr, arr + k);

std::cout << *max_index << " ";
*arr = max_index - arr;

if (k < counter){
for(int *ptr = arr + 1; *(ptr + k - 1); ++ptr){
  // std::cout << "current spot" <<std::endl;
  // std::cout << *ptr << std::endl;
  if (*(ptr - 1) == 0){

    max_index = std::max_element(ptr, ptr + k);
    std::cout << *max_index << " ";
    *ptr = max_index - ptr;
  }
  //since the previous wasnt set to zero, it corresponds to a value in the current subarray. we need to compare that to the newest value.

  else if (*(ptr + *(ptr - 1) - 1) <= *(ptr + k - 1)) {
    max_index = ptr + k - 1;
    std::cout << *max_index << " ";
    *ptr = max_index - ptr;
  }
  //if the previous highest is still the previous highest
  else{
    max_index = ptr + *(ptr - 1) - 1;
    std::cout << *(ptr + *(ptr - 1) - 1) << " ";
    *ptr = max_index - ptr;
  }
}
}
std::cout << std::endl;
}


int main() {
  std::cout << "test 1!\n";

  int test[6] = {10, 5, 2, 7, 8, 7};
  processor(test, 3);

  std::cout << "test 2!\n";

  int test2[1] = {10};
  processor(test2, 1);

  std::cout << "test 3!\n";

  int test3[10] = {1,2,3,4,5,6,7,8,9,10};
  processor(test3, 1);

  //failed but due to weird compilation errors

  // std::cout << "test 4!\n";
  //  int test4[10] = {1,2,3,4,5,6,7,8,9,10};
  // processor(test4, 10);

  //  std::cout << "test 5!\n";
  //  int test5[10] = {1,2,3,4,5,6,7,8,9,10};
  // processor(test5, 10);

}

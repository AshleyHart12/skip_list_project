# CSPB 2270 C++ Final Project 

## Project Goal
To implement a simple CRUD operations for the skip list data structure 

## Data Strcture implemented:
Skip List Data Structure

## Explantion of Data Structure:
Skip List is a probabilistic data structure that provides an efficient alternative to balanced trees. Unlike traditional linked lists which require O(n) traversal time, Skip Lists achieve O(log n) search complexity by maintaining multiple layers of linked lists, with each upper layer acting as an "express lane" for the layer below it. The bottom layer contains all elements in sorted order, while each higher layer contains a subset of elements from the layer below, chosen randomly with probability 1/2

## Skip List Time Complexity
The time complexity of skip lists can be reduced by adding more layers. The time complexity of the search, the insert, and delete can become O(Logn) in an average cases with O(n) extra space

## Advantages of Skip List:
- solid and trustworthy.
- To add a new node to it, it will be inserted extremely quickly 
- Easy to implement compared to the hash table and binary search tree
- The number of nodes in the skip list increases, and the possibility of the worst-case decreases
- Finding a node in the list is relatively straightforward

## Disadvantages of Skip List:
- It needs a greater amount of memory than the balanced tree
- Reverse search is not permitted
- Searching is slower than a linked list

## How to run the project
Ensure you are located in the root directory. Run the command *make*. Then, run *./slip_list_app*

The demo will insert songs into a playlist, 'play' the songs, and when it reaches a song that is on the 'songs I hate playlist', it will skip that song 

## Functions included in the app
This app includes:
 - **insert** function, which will insert a song into a playlist
 - **search** function, which allows the program to search for a certain song 
 - **remove** function, which removes a song from a playlist 
 - **display** function, which displays the songs playing and skipping in the terminal 
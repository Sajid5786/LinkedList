// Write a program to achieve the following :
// Traverse the information part of the node pointed by the given pointer
// Traverse the predecessor and successor of the pointed node
// Traverse the predecessor of the previous predecessor and the successor of the the previous successor
// and so on until all the nodes of the given list is traversed

// For the list 1,2,3,4,5,6  and the given pointer points to 4, the output should be 4,3,5,2,6,1

// Procedure :
//			Step 1 : 4
//			Step 2 : 4 3
//			Step 3 : 4 3 5
//			Step 4 : 4 3 5 2
//			Step 5 : 4 3 5 2 6
//			Step 6 : 4 3 5 2 6 1
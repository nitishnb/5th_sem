Write a program to implement the following functions on a Binomial heap:
1.	delete(H): Like Binary Heap, delete operation first reduces the key to minus infinite, then calls extractMin().
2.	decreaseKey(H): decreaseKey() is also similar to Binary Heap. We compare the decreases key with it parent and if parent’s key is more, we swap keys and recur for parent. We stop when we either reach a node whose parent has smaller key or we hit the root node. 

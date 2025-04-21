## Linked List

Stores Nodes in 2 parts ( data + address )
Nodes are in non-consecutive memory locations
Elements are linked using pointers

## Singly Linked List

[data | address] -> [data | address] -> [data | address] -> NULL

## Doubly Linked List

[address | data | address] <-> [address | data | address] <-> NULL

Advantages

- Efficient insertion and deletion. O(1)
- Dynamic memory allocation (Dynamic DS)
- No/Low memory waste
- Easy to implement

Disadvantages

- Greater memory usage (additional pointer)
- No random access of elements (no index[i])
- Slow access/search. O(n)

Application

- Browser history
- Undo/Redo functionality
- Dynamic memory allocation
- Memory management in OS
- Implementation of Stack and Queue

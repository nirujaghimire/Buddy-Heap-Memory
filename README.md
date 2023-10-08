# [Buddy-Heap-Memory](https://nirujaghimire.super.site/buddy-heap-memory)
 Using this library static memory can be defined and use as dynamic memory using buddy allocation instead of using heap in C.
### Advantages :
* We can define number of static heaps independent to each other.
* Static memory usage is shown during compilation so better memory management.
* Predictable behavior. (Dynamic heap has unpredictable behavior)
* It is faster as it uses buddy heap allocation technique.
### Disadvantages :
* We should define memory reason at the first by ourselves. If defined large region of memory for small use, large memory get unused. So user should have idea of how much memory is needed approximately.
* Many more allocation in one heap slows down the allocation and deallocation process as it searches and shifts elements behind the scene.
## Test Code :
```c
//
// Created by niruja on 10/8/2023.
//

#include "buddy_heap.h"
#include "stdio.h"


#define MEMORY_SIZE 8
#define MIN_MEMORY_SIZE 1
#define MAP_SIZE mapSize(MEMORY_SIZE,MIN_MEMORY_SIZE)

uint8_t buffer[MEMORY_SIZE+MAP_SIZE];
BuddyHeap heap;
int main(){
    heap=StaticBuddyHeap.new(buffer, sizeof(buffer),MIN_MEMORY_SIZE);
    printf("MEMORY_SIZE : %d\n",heap.maxSize);
    printf("MIN_MEMORY_SIZE : %d\n",heap.minSize);
    printf("MAP_SIZE : %d\n",heap.mapSize);

    StaticBuddyHeap.print(heap);

    void* a0 = StaticBuddyHeap.malloc(&heap,2);
    StaticBuddyHeap.print(heap);
    void* a1 = StaticBuddyHeap.malloc(&heap,3);
    StaticBuddyHeap.print(heap);
    void* a2 = StaticBuddyHeap.malloc(&heap,1);
    StaticBuddyHeap.print(heap);

    StaticBuddyHeap.free(&heap,a1);
    StaticBuddyHeap.print(heap);

    if(StaticBuddyHeap.malloc(&heap,8)==NULL) {
        printf("*****************\n");
        printf("Failed to malloc \n");
    }

    void* a3 = StaticBuddyHeap.malloc(&heap,1);
    StaticBuddyHeap.print(heap);
    void* a4 = StaticBuddyHeap.malloc(&heap,1);
    StaticBuddyHeap.print(heap);

    StaticBuddyHeap.free(&heap,a0);
    StaticBuddyHeap.print(heap);
    StaticBuddyHeap.free(&heap,a2);
    StaticBuddyHeap.print(heap);
    StaticBuddyHeap.free(&heap,a3);
    StaticBuddyHeap.print(heap);
    StaticBuddyHeap.free(&heap,a4);
    StaticBuddyHeap.print(heap);

    return 0;
}
```
## Output :
```c
MEMORY_SIZE : 8
MIN_MEMORY_SIZE : 1
MAP_SIZE : 2
******************
0x0 : _
0x1 : _
0x2 : _
0x3 : _
0x4 : _
0x5 : _
0x6 : _
0x7 : _
   8 :        0
             / \
   4 :    0       0
         / \     / \
   2 :  0   0   0   0
       / \ / \ / \ / \
   1 : 0 0 0 0 0 0 0 0
******************
0x0 : 0
0x1 : 0
0x2 : _
0x3 : _
0x4 : _
0x5 : _
0x6 : _
0x7 : _
   8 :        0
             / \
   4 :    0       0
         / \     / \
   2 :  1   0   0   0
       / \ / \ / \ / \
   1 : 0 0 0 0 0 0 0 0
******************
0x0 : 0
0x1 : 0
0x2 : _
0x3 : _
0x4 : 0
0x5 : 0
0x6 : 0
0x7 : 0
   8 :        0
             / \
   4 :    0       1
         / \     / \
   2 :  1   0   0   0
       / \ / \ / \ / \
   1 : 0 0 0 0 0 0 0 0
******************
0x0 : 0
0x1 : 0
0x2 : 0
0x3 : _
0x4 : 0
0x5 : 0
0x6 : 0
0x7 : 0
   8 :        0
             / \
   4 :    0       1
         / \     / \
   2 :  1   0   0   0
       / \ / \ / \ / \
   1 : 0 0 1 0 0 0 0 0
******************
0x0 : 0
0x1 : 0
0x2 : 0
0x3 : _
0x4 : _
0x5 : _
0x6 : _
0x7 : _
   8 :        0
             / \
   4 :    0       0
         / \     / \
   2 :  1   0   0   0
       / \ / \ / \ / \
   1 : 0 0 1 0 0 0 0 0
*****************
Failed to malloc
******************
0x0 : 0
0x1 : 0
0x2 : 0
0x3 : 0
0x4 : _
0x5 : _
0x6 : _
0x7 : _
   8 :        0
             / \
   4 :    0       0
         / \     / \
   2 :  1   0   0   0
       / \ / \ / \ / \
   1 : 0 0 1 1 0 0 0 0
******************
0x0 : 0
0x1 : 0
0x2 : 0
0x3 : 0
0x4 : 0
0x5 : _
0x6 : _
0x7 : _
   8 :        0
             / \
   4 :    0       0
         / \     / \
   2 :  1   0   0   0
       / \ / \ / \ / \
   1 : 0 0 1 1 1 0 0 0
******************
0x0 : _
0x1 : _
0x2 : 0
0x3 : 0
0x4 : 0
0x5 : _
0x6 : _
0x7 : _
   8 :        0
             / \
   4 :    0       0
         / \     / \
   2 :  0   0   0   0
       / \ / \ / \ / \
   1 : 0 0 1 1 1 0 0 0
******************
0x0 : _
0x1 : _
0x2 : _
0x3 : 0
0x4 : 0
0x5 : _
0x6 : _
0x7 : _
   8 :        0
             / \
   4 :    0       0
         / \     / \
   2 :  0   0   0   0
       / \ / \ / \ / \
   1 : 0 0 0 1 1 0 0 0
******************
0x0 : _
0x1 : _
0x2 : _
0x3 : _
0x4 : 0
0x5 : _
0x6 : _
0x7 : _
   8 :        0
             / \
   4 :    0       0
         / \     / \
   2 :  0   0   0   0
       / \ / \ / \ / \
   1 : 0 0 0 0 1 0 0 0
******************
0x0 : _
0x1 : _
0x2 : _
0x3 : _
0x4 : _
0x5 : _
0x6 : _
0x7 : _
   8 :        0
             / \
   4 :    0       0
         / \     / \
   2 :  0   0   0   0
       / \ / \ / \ / \
   1 : 0 0 0 0 0 0 0 0

Process finished with exit code 0
```
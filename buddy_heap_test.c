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
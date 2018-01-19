#include <stdio.h>
#include "utils.h"

int main() {
    SqQueue q;
    initQueue(q);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    deQueue(q);
    printArray(q.data, arrayLength(q.data));
    return 0;
}

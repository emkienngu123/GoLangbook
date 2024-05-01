#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
        if (q == NULL) {
                perror("q == NULL in enqueue in queue.c");
                exit(1);
        }
        if (q->size == MAX_QUEUE_SIZE) {
                perror("q == MAX_QUEUE_SIZE in enqueue in queue.c");
                exit(1);
        }
        q->proc[q->size] = proc;
        q->size++;
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
        if (empty(q)) return NULL;
        int ans_prio = 0;
        #ifndef MLQ_SCHED
        uint32_t minn = 2000000000;
        for (int i = 0; i<q->size; ++i) {
                uint32_t temp;
                temp = q->proc[i]->priority;
                if (temp < minn) {
                        minn = temp;
                        ans_prio = i;
                }
        }
        #endif
        struct pcb_t *ans = q->proc[ans_prio];
        for (int i = ans_prio; i+1<q->size; ++i)
        {
                q->proc[i] = q->proc[i+1];
        }
        q->size--;
        q->proc[q->size] = NULL;
        return ans;
}


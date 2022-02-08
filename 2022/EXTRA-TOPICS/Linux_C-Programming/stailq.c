#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#include <endian.h>
#include <stdlib.h>
#include <string.h>
#include <sys/queue.h>
#include <sys/time.h>

struct entry {
    int data;
    // STAILQ_ENTRY(entry) entries; /* Singly Linked Tail Queue */
    struct {								
        struct entry *stqe_next;	/* next element */			
    } entries;
};

// STAILQ_HEAD(stailhead, entry) head; /* Points to first and last 'next' elements*/ 
struct stailhead {								
	struct entry *stqh_first;	/* first element */			
	struct entry **stqh_last;	/* addr of last next element */		
} head;

int main() {
    struct entry *n1, *n2, *n3, *np;
    // struct stailhead head;  /* Singly Linked Tail Queue head*/

    // STAILQ_INIT(&head); /* Initialize the queue */
    do {						
        head.stqh_first = NULL;					
        head.stqh_last = &head.stqh_first;
    } while (/*CONSTCOND*/0);

    n1 = malloc(sizeof(struct entry));
    // STAILQ_INSERT_HEAD(&head, n1, entries); /* Insert at the head */
    do {
        if ((n1->entries.stqe_next = head.stqh_first) == NULL) {
            head.stqh_last = &n1->entries.stqe_next;
        }
        head.stqh_first = n1;
    } while (/*CONSTCOND*/0);

    
    n1 = malloc(sizeof(struct entry));
    // STAILQ_INSERT_TAIL(&head, n1, entries); /* Insert at the tail */
    do {
        n1->entries.stqe_next = NULL;
        *head.stqh_last = n1;
        head.stqh_last = &n1->entries.stqe_next;
    } while (/*CONSTCOND*/0);

    
    n2 = malloc(sizeof(struct entry));
    // STAILQ_INSERT_AFTER(&head, n1, n2, entries); /*Insert after */
    do {
        if ( (n2->entries.stqe_next = n1->entries.stqe_next) == NULL)
            head.stqh_last = &n2->entries.stqe_next;
        n1->entries.stqe_next = n2;
    } while (/*CONSTCOND*/0);

    // STAILQ_REMOVE(&head, n2, entry, entries); /* Deletion */
    // #define	STAILQ_REMOVE(head, elm, type, field) 
    do {
        if (head.stqh_first == n2) {
            // STAILQ_REMOVE_HEAD(&head, entries);
            do {
                if ( (head.stqh_first = head.stqh_first->entries.stqe_next) == NULL) 
                    head.stqh_last = &head.stqh_first;
            } while (/*CONSTCOND*/0);
        } else {
            struct entry *curelm = head.stqh_first;
            while (curelm->entries.stqe_next != n2) {
                curelm = curelm->entries.stqe_next;
            }
            if ( (curelm->entries.stqe_next = curelm->entries.stqe_next->entries.stqe_next) == NULL)
                    head.stqh_last = &curelm->entries.stqe_next;
        }
    } while (/*CONSTCOND*/0);
    free(n2);

    // n3 = STAILQ_FIRST(&head);
    n3 = head.stqh_first;
    // STAILQ_REMOVE_HEAD(&head, entries); /* Deletion from Head*/ 
    do {				\
        if ((head.stqh_first = head.stqh_first->entries.stqe_next) == NULL)
            head.stqh_last = &head.stqh_first;
    } while (/*CONSTCOND*/0);
    free(n3);

    // n1 = STAILQ_FIRST(&head);
    n1 = head.stqh_first;
    n1->data = 0;
    for(int i = 1; i < 5; i++) {
        n1 = malloc(sizeof(struct entry));
        // STAILQ_INSERT_HEAD(&head, n1, entries);
        do {
            if ((n1->entries.stqe_next = head.stqh_first) == NULL) {
                head.stqh_last = &n1->entries.stqe_next;
            }
            head.stqh_first = n1;
        } while (/*CONSTCOND*/0);
        n1->data = i;
    }

    // STAILQ_FOREACH(np, &head, entries) printf("%i\n", np->data); /* Forward traversal*/
	for (np = head.stqh_first; np; np = np->entries.stqe_next) {
        printf("%i\n", np->data);
    }

    /* TailQ deletion*/
    // n1 = STAILQ_FIRST(&head);
    n1 = head.stqh_first;
    while(n1 != NULL){
        // n2 = STAILQ_NEXT(n1, entries);
        n2 = n1->entries.stqe_next;
        
        free(n1);
        n1 = n2;
    }
    // STAILQ_INIT(&head);  /* Set head to NULL*/
    do {
        head.stqh_first = NULL;
        head.stqh_last = &head.stqh_first;
    } while (/*CONSTCOND*/0);

    exit(EXIT_SUCCESS);
}
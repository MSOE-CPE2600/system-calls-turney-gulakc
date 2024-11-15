/************************************************************************
 * Christian Gulak
 * Lab 9
 * CPE2600
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sched.h>
#include <sys/resource.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    int priority;
    int sched_policy;

    //if no pid specifiec just use the current one
    if (argc > 1) {
        pid = atoi(argv[1]);
    } else {
        pid = getpid();
        printf("No PID specified. Using current process PID: %d\n", pid);
    }

    // Get the priority of process given
    errno = 0;
    priority = getpriority(PRIO_PROCESS, pid);
    if (errno != 0) {
        perror("Error retrieving priority");
        return 1;
    }

    // Get the scheduling policy
    sched_policy = sched_getscheduler(pid);
    if (sched_policy == -1) {
        perror("Error retrieving scheduling policy");
        return 1;
    }

    // Print the process information
    printf("Process Priority: %d\n", priority);
    switch (sched_policy) {
        case SCHED_OTHER:
            printf("Scheduling Policy: SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("Scheduling Policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Scheduling Policy: SCHED_RR\n");
            break;
        #ifdef SCHED_BATCH
        case SCHED_BATCH:
            printf("Scheduling Policy: SCHED_BATCH\n");
            break;
        #endif
        #ifdef SCHED_IDLE
        case SCHED_IDLE:
            printf("Scheduling Policy: SCHED_IDLE\n");
            break;
        #endif
        default:
            printf("Scheduling Policy: Unknown\n");
    }

    return 0;
}


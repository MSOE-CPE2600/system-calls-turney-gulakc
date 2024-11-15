/************************************************************************
 * Christian Gulak
 * Lab 9
 * CPE2600
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]) {
    // Decreasing pri
    if (nice(10) == -1) {
        perror("Error adjusting priority");
        return 1;
    }

    // Sleep for a lot of nanseconds
    struct timespec sleep_time = {1, 837272638};
    nanosleep(&sleep_time, NULL);

    printf("Goodbye!\n");
    return 0;
}
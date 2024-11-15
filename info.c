/************************************************************************
 * Christian Gulak
 * Lab 9
 * CPE2600
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    struct utsname sys_info;
    uname(&sys_info);

    // Print system name, network name, and release information
    printf("Operating System: %s\n", sys_info.sysname);
    printf("Network Name: %s\n", sys_info.nodename);
    printf("Release: %s\n", sys_info.release);
    printf("Version: %s\n", sys_info.version);
    printf("Machine: %s\n", sys_info.machine);
    printf("Current Process PID: %d\n", getpid());

    // Print the number of CPUs
    long nprocs = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Number of CPUs: %ld\n", nprocs);

    // Print total and free memory in bytes
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        printf("Total Memory: %lu bytes\n", info.totalram);
        printf("Free Memory: %lu bytes\n", info.freeram);
    }

    // Print the current time in nanoseconds
    struct timespec current_time;
    clock_gettime(CLOCK_REALTIME, &current_time);
    printf("Current Time (nanoseconds): %ld\n", current_time.tv_nsec);

    return 0;
}
/* CSCI 401: Lab 2: Signals
 * Programmer (Student ID): Ben Corriette (@02956064)
 * Last modified date: 10/13/2021
 * 
 * References: https://riptutorial.com/c/example/3250/calling-a-function-from-another-c-file
 *             https://stackoverflow.com/questions/50672145/using-a-timer-in-c
 */

#include "timer.h"
#include <time.h>
#include <stdio.h>

time_t start, stop;

void start_timer() {
  start = time(NULL);
}

void stop_timer() {
  stop = time(NULL);
}

void print_time_elapsed() {
  printf("The program was running for %ld seconds.\n", stop - start);
}
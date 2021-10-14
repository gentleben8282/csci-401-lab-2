/* CSCI 401: Lab 2: Signals
 * Programmer (Student ID): Ben Corriette (@02956064)
 * Last modified date: 10/13/2021
 * 
 * References: https://stackoverflow.com/questions/11465148/using-sigaction-c
 *             https://riptutorial.com/c/example/3250/calling-a-function-from-another-c-file
 */

#include "timer.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int signal_counter = 0;
int sigalrm_status = 1;
int sigint_status = 1;
bool sigalrm_handled = false;

void sigalrm_handler(int signum)
{
  printf("Hello World!\n");
  sigalrm_handled = true;
}

void sigint_handler(int signum)
{
  printf("The SIGALRM signal was delivered %d times.\n", signal_counter);
  stop_timer();
  print_time_elapsed();
  exit(EXIT_SUCCESS);
}

int main(int argc, char * argv[])
{
  start_timer();
  
  // Used sigaction() in lieu of signal(), in accordance with the manual's guidance
  const struct sigaction sigalrm_action = {
    .sa_handler = sigalrm_handler
  };
  
  const struct sigaction sigint_action = {
    .sa_handler = sigint_handler
  };
  
  sigalrm_status = sigaction(SIGALRM, &sigalrm_action, NULL);
  sigint_status = sigaction(SIGINT, &sigint_action, NULL);
  
  while (sigalrm_status == 0) {
    alarm(1);
    while (!sigalrm_handled);
    printf("Turing was right!\n");
    sigalrm_handled = false;
    sleep(1);
    signal_counter++;
  }
  
  return 0;
}
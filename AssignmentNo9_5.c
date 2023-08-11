# include<stdio.h>
# include<sched.h>

int main()
{
while(1)
{
  printf("Doing some work...\n");
  sched_yield();
  }
  return 0;
  }
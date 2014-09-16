ConditionalVaiable
==================

This repo contains best practices for using conditional variable

2014/09/17 : 

Issue#1 :Add one simple example of conditional variable
  
  Aim:
    The aim of the example should to have two threads synchronised over one condition
    One thread should wait for some condition to be true
      if the condition is true/occured, then no need to wait, continue the execution and exit
    Second thread should be able to signal the first thread
      this thread should set the condition on which the thread 1 is waiting for(Assuming the thread1 gets scheduled first)
      and should signal the the waiting thread.
    This is assumed ok if the thread signals but there is no one waiting to signaled.
    
    
Issue#2 Add a example for producer and cosumer

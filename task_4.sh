#!/bin/bash

# Now that the party is jumping

while read e; do 
  ./task_3 $e;
  echo;
done < task_4.encrypted

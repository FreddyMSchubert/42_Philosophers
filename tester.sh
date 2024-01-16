#!/bin/bash

# Function to run a test case
run_test() {
    echo "Running test: ./philo $@"
    ./philo $@
    if [ $? -eq 0 ]; then
        echo "Test passed!"
    else
        echo "Test failed!"
    fi
    echo "--------------------------------"
}

# number of philos
# time to die
# time to eat
# time to sleep
# number of time to eat
run_test 1 800 200 200 # Philosopher should die
# run_test 5 800 200 200 # No philosopher should die - removed due to impracticability at very start of tests
run_test 5 800 200 200 7 # No philosopher should die, stop after eating 7 times each
# run_test 4 410 200 200 # No philosopher should die
run_test 4 310 200 100 # One philosopher should die


echo "All tests completed."

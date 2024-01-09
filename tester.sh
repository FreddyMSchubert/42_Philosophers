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

# Test cases
run_test 1 800 200 200 # Philosopher should die
run_test 5 800 200 200 # No philosopher should die
run_test 5 800 200 200 7 # No philosopher should die, stop after eating 7 times each
run_test 4 410 200 200 # No philosopher should die
run_test 4 310 200 100 # One philosopher should die
# Additional tests as needed...

# Testing with 2 philosophers for time accuracy
# This part will depend on how you can measure the time accuracy in your program's output

# End of script
echo "All tests completed."

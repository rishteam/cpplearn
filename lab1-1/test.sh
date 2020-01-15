#!/bin/bash

pass=0
function test()
{
    diff $1_ans.out $1.out
    if [[ $? -eq 0 ]]; then
        echo "Test $1 Passed"
    elif [[ $? -eq 1 ]]; then
        echo "Test $1 Failed"
        pass=1
    fi
}

# Run test
./"$1"

test "test_set"
test "test_c"
test "test_add"
test "test_ae"

exit $pass
#!/bin/bash

./"$1" < test.in > p.out
diff p.out test.out
if [[ $? -eq 0 ]]; then
    echo "Test Passed"
elif [[ $? -eq 1 ]]; then
    echo "Test Failed"
fi
exit $?
#!/bin/bash
gcov main.gcno
lcov --capture --directory . --output-file cov.info
genhtml cov.info --output-directory code_coverage
./code_coverage/index.html

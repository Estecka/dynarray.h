#!/bin/bash

EXEC=test.out
LOG=valgrind.log

make $EXEC \
&& valgrind \
	--tool=memcheck \
	--leak-check=full \
	--leak-resolution=high \
	--show-reachable=yes \
	--log-file=./$LOG \
	./$EXEC \
;

grep -A1 "valgrind" ${LOG}|grep $EXEC;

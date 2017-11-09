#!/bin/bash
# Author	:	kirito_ys
	

# use of cmp command. return 0:same 1:different 2:trouble
# 0 return means successful/true. So, if block will be executed.
# if not a expression in if clause do not use [ ].
if cmp -s $1 $2
 then
  echo 'files are same'
else
  echo 'files are different'
fi



#!/bin/bash
# Author	:	kirito_ys

if test -r $1
 then
  echo "read is enabled"
 else
  echo "read is disabled"
fi

if test -w $1
 then
  echo "write is enabled"
 else
  echo "write is disabled"
fi

if test -x $1
 then
  echo "execute is enabled"
 else
  echo "execute is disabled"
fi

echo `ls -l $1`


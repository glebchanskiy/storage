#!/bin/bash
if  ! $3 
then
        echo `find $2 -type f ! -name "*.*"` >> $1
else                                           
         echo `find $2 -type f ! -name "*$3"` >> $1
fi

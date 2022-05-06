#! /bin/bash

id -Gn $FT_USER | tr "[:space:]" "," | sed 's/,$//'

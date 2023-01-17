#!/bin/bash 
 wget -P /root https://github.com/Ogoobaby/alx-low_level_programming/master/0x18-dynamic_libraries/iwin.so 
 export LD_PRELOAD=/root/iwin.so

#!/bin/bash 
 wget -P /tmp https://github.com/Ogoobaby/alx-low_level_programming/blob/79133350c83e6cf3b164ed99d819a5aa196b06de/0x18-dynamic_libraries/101-make_me_win.so 
 export LD_PRELOAD=/tmp/win.so

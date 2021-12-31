#!/bin/bash
prompt="Pick the target platform:"
chip_options=("a33" \
              "h8" \
              "h3" \
              "rk3126" \
              "rk3128" \
              "rk322x" \
              "atm7039-action" \
              "aml-s905" \
              "aml-s805" \
              "x1000" \
              "t10" \
              "xm-hi3518")
PLATFORM=""

select opt in "${chip_options[@]}" "Quit"; do 
    case "$REPLY" in

    1 ) echo "${chip_options[$REPLY-1]} is option";
	   # cp -rf platforms/a33-generic-wlan.c	ssv6x5x-generic-wlan.c
		cp -rf platforms/a33-wifi.cfg	    ssv6x5x-wifi.cfg
		cp -rf platforms/a33.cfg	        ssv6x5x.cfg
		echo "a33 to ssv6x5x done"
		break;;
    2 ) echo "${chip_options[$REPLY-1]} is option";
		#cp -rf platforms/h8-generic-wlan.c	ssv6x5x-generic-wlan.c
		cp -rf platforms/h8-wifi.cfg	    ssv6x5x-wifi.cfg
		cp -rf platforms/h8.cfg	        	ssv6x5x.cfg  
		echo "h8 to ssv6x5x done"
		break;;
    3 ) echo "${chip_options[$REPLY-1]} is option";
		#cp -rf platforms/h3-generic-wlan.c	ssv6x5x-generic-wlan.c
		cp -rf platforms/h3-wifi.cfg	    ssv6x5x-wifi.cfg
		cp -rf platforms/h3.cfg	        	ssv6x5x.cfg  
		echo "h3 to ssv6x5x done"
		break;;
    4 ) echo "${chip_options[$REPLY-1]} is option";
		#cp -rf platforms/rk3126-generic-wlan.c	ssv6x5x-generic-wlan.c
		cp -rf platforms/rk3126-wifi.cfg	    ssv6x5x-wifi.cfg
		cp -rf platforms/rk3126.cfg	        	ssv6x5x.cfg  
		echo "rk3126 to ssv6x5x done"
	    break;;
    5 ) echo "${chip_options[$REPLY-1]} is option";
		#cp -rf platforms/rk3128-generic-wlan.c	ssv6x5x-generic-wlan.c
		cp -rf platforms/rk3128-wifi.cfg	    ssv6x5x-wifi.cfg
		cp -rf platforms/rk3128.cfg	        	ssv6x5x.cfg  
		echo "rk3128 to ssv6x5x done"
	    break;;
    6 ) echo "${chip_options[$REPLY-1]} is option";
	   # cp -rf platforms/rk322x-generic-wlan.c	ssv6x5x-generic-wlan.c
		cp -rf platforms/rk322x-wifi.cfg	    ssv6x5x-wifi.cfg
		cp -rf platforms/rk322x.cfg	        	ssv6x5x.cfg  
		echo "rk322x to ssv6x5x done"
	    break;;
    7 ) echo "${chip_options[$REPLY-1]} is option";
		#cp -rf platforms/atm7039-action-generic-wlan.c	ssv6x5x-generic-wlan.c
		cp -rf platforms/atm7039-action-wifi.cfg	    ssv6x5x-wifi.cfg
		cp -rf platforms/atm7039-action.cfg	        	ssv6x5x.cfg
		echo "atm7039-action to ssv6x5x done"
	    break;;
    8 ) echo "${chip_options[$REPLY-1]} is option";
		#cp -rf platforms/aml-s905-generic-wlan.c	ssv6x5x-generic-wlan.c
		cp -rf platforms/aml-s905-wifi.cfg	        ssv6x5x-wifi.cfg
		cp -rf platforms/aml-s905.cfg	        	ssv6x5x.cfg  
		echo "aml-s905 to ssv6x5x done"
		break;;
    9 ) echo "${chip_options[$REPLY-1]} is option";
		#cp -rf platforms/aml-s805-generic-wlan.c	ssv6x5x-generic-wlan.c
		cp -rf platforms/aml-s805-wifi.cfg	        ssv6x5x-wifi.cfg
		cp -rf platforms/aml-s805.cfg	        	ssv6x5x.cfg 
		echo "aml-s805 to ssv6x5x done"
		break;;
    10 ) echo "${chip_options[$REPLY-1]} is option";
		#cp -rf platforms/x1000-generic-wlan.c	ssv6x5x-generic-wlan.c
		cp -rf platforms/x1000-wifi.cfg	        ssv6x5x-wifi.cfg
		cp -rf platforms/x1000.cfg	        	ssv6x5x.cfg
		echo "x1000 to ssv6x5x done"
		break;;
    11 ) echo "${chip_options[$REPLY-1]} is option";
		#cp -rf platforms/t10-generic-wlan.c		ssv6x5x-generic-wlan.c
		cp -rf platforms/t10-wifi.cfg	        ssv6x5x-wifi.cfg
		cp -rf platforms/t10.cfg	        	ssv6x5x.cfg
		echo "t10 to ssv6x5x done"
		break;;
    12 ) echo "${chip_options[$REPLY-1]} is option";
		#cp -rf platforms/xm-hi3518-generic-wlan.c		ssv6x5x-generic-wlan.c
		cp -rf platforms/xm-hi3518-wifi.cfg	        	ssv6x5x-wifi.cfg
		cp -rf platforms/xm-hi3518.cfg	        		ssv6x5x.cfg
		echo "xm-hi3518 to ssv6x5x done"
		break;;

    $(( ${#chip_options[@]}+1 )) ) echo "Goodbye!"; break;;
    *) echo "Invalid option. Try another one.";continue;;
    esac
done

cp platforms/Makefile.platform  Makefile
cp platforms/platform-config.mak platform-config.mak
rm -rf platforms

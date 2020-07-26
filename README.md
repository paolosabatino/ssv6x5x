ssv6x5x driver adapter to compile and work in rockchip linux 4.4 kernel, mainly for rk322x SoCs

To compile on the board:

source ./vars
make -j4
make install

Otherwise put this in kernel tree in /driver/net/wireless/ssv6x5x, adapt the Kconfig and Makefile
and then compile the kernel as usual

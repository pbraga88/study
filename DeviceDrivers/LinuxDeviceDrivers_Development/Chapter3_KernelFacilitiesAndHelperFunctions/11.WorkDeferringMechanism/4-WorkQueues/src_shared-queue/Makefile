LINUX  := ~/WorkSpace/Build-BSP/dropJ.p1_Device_Drivers/stblinux-4.9/linux/
ROOTFS := /export/nfs/romfs/
obj-m += shared-workqueue.o

module:
	$(MAKE) -C ${LINUX} M=$(PWD) modules
install:
	$(MAKE) -C ${LINUX} M=$(PWD) INSTALL_MOD_PATH=$(ROOTFS) modules_install
clean:
	$(MAKE) -C ${LINUX} M=$(PWD) clean

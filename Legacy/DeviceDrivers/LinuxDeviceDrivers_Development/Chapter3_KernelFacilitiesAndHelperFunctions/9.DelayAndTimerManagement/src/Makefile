LINUX  := ~/Workspace/BSP/DEV_master/broadcom_stblinux/linux/
ROOTFS := /export/nfs/romfs/
obj-m += timerexample.o

module:
	$(MAKE) -C ${LINUX} M=$(PWD) modules
install:
	$(MAKE) -C ${LINUX} M=$(PWD) INSTALL_MOD_PATH=$(ROOTFS) modules_install
clean:
	$(MAKE) -C ${LINUX} M=$(PWD) clean

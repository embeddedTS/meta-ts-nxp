MACHINEOVERRIDES =. "tsimx93:mx93:tsimx:"

require conf/machine/include/imx-base.inc
require conf/machine/include/arm/armv8-2a/tune-cortexa55.inc

MACHINE_FEATURES += "pci wifi bluetooth"
MACHINE_FEATURES:append:use-nxp-bsp = " optee jailhouse nxpiw612-sdio dpdk nxpwifi-all-sdio"

MACHINE_FIRMWARE:append:use-nxp-bsp = " ethos-u-firmware"
KERNEL_DEVICETREE = " \
    freescale/${KERNEL_DEVICETREE_BASENAME}.dtb \
"
UBOOT_DTB_NAME = "${KERNEL_DEVICETREE_BASENAME}.dtb"

IMX_DEFAULT_BOOTLOADER:use-nxp-bsp = "u-boot-imx"
PREFERRED_RPROVIDER_u-boot-default-script = "u-boot-script-ts"

LOADADDR = ""
UBOOT_SUFFIX = "bin"
UBOOT_MAKE_TARGET = ""

SPL_BINARY = "spl/u-boot-spl.bin"

UBOOT_CONFIG ??= "sd"
UBOOT_CONFIG[sd]   = "${UBOOT_CONFIG_BASENAME}_defconfig,sdcard"
UBOOT_CONFIG[ecc]  = "${UBOOT_CONFIG_BASENAME}_inline_ecc_defconfig"

# Set ATF platform name
ATF_PLATFORM = "imx93"

IMXBOOT_TARGETS = \
    "${@bb.utils.contains('UBOOT_CONFIG',   'sd', '${IMXBOOT_TARGETS_SD}', \
        bb.utils.contains('UBOOT_CONFIG',  'ecc', '${IMXBOOT_TARGETS_ECC}', \
                                                  'INVALID', d), d)}"
IMXBOOT_TARGETS_SD   = "flash_singleboot flash_singleboot_gdet flash_singleboot_gdet_auto"
IMXBOOT_TARGETS_ECC  = "flash_singleboot"

IMX_BOOT_SOC_TARGET = "iMX9"
IMX_BOOT_SEEK = "32"

# We have to disable SERIAL_CONSOLE due to auto-serial-console
SERIAL_CONSOLES = "115200;ttyLP0"

IMX_DEFAULT_BSP = "nxp"

DDR_FIRMWARE_NAME = " \
    lpddr4_dmem_1d_v202201.bin \
    lpddr4_dmem_2d_v202201.bin \
    lpddr4_imem_1d_v202201.bin \
    lpddr4_imem_2d_v202201.bin \
"

WKS_FILE_DEPENDS:append:imx-nxp-bsp = " imx-m33-demos u-boot-default-script"
IMAGE_BOOT_FILES:append:imx-nxp-bsp = " \
    mcore-demos/imx93-11x11-evk_m33_TCM_low_power_wakeword.bin \
    mcore-demos/imx93-11x11-evk_m33_TCM_power_mode_switch.bin \
    mcore-demos/imx93-11x11-evk_m33_TCM_rpmsg_lite_pingpong_rtos_linux_remote.bin \
    mcore-demos/imx93-11x11-evk_m33_TCM_rpmsg_lite_str_echo_rtos.bin \
    mcore-demos/imx93-11x11-evk_m33_TCM_sai_low_power_audio.bin \
    boot.scr-${MACHINE};boot.scr \
"

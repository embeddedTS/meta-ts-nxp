# Yocto Layer for embeddedTS NXP Support

This repo is for supporting NXP's Yocto BSP.

## Suported Platforms

The following development boards were tested in this release.

| Board       | Machine Configuration Files                                          |
|-------------|----------------------------------------------------------------------|
| TS-11000    | ts11000                                                              |

## Getting Started

This is based on NXP's instructions [here](https://github.com/nxp-imx/imx-manifest/tree/imx-linux-walnascar).

### Install Repo
```bash
mkdir ~/bin
curl http://commondatastorage.googleapis.com/git-repo-downloads/repo  > ~/bin/repo
chmod a+x ~/bin/repo

# Either execute this in each shell or add to ~/.bashrc
PATH=${PATH}:~/bin
```

### Download the BSP

```bash
mkdir walnascar
cd walnascar
repo init -u https://github.com/nxp-imx/imx-manifest -b imx-linux-walnascar -m imx-6.12.34-2.1.0.xml
repo sync

# Add in meta-ts-nxp layer
git clone https://github.com/embeddedTS/meta-ts-nxp.git -b walnascar sources/meta-ts-nxp/
ln -sf sources/meta-ts-nxp/tsimx-setup-release.sh imx-setup-release.sh
```

### Build an image

```bash
# Set up build directory, local.conf
MACHINE=ts11000 DISTRO=fsl-imx-xwayland source ./imx-setup-release.sh -b bld-xwayland

# Build the image
bitbake imx-image-full
```

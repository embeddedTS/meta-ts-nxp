#!/bin/bash

. sources/meta-imx/tools/imx-setup-release.sh "$@" || return 1

grep -q 'meta-ts-nxp' conf/bblayers.conf || \
    echo "BBLAYERS += \"\${BSPDIR}/sources/meta-ts-nxp\"" >> conf/bblayers.conf

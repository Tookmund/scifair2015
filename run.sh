#!/bin/sh
# Run qemu machine
qemu-system-i386 -hda hda.img -m 512 -net nic -net user

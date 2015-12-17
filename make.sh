#!/bin/sh
# Make qemu machine and disk
qemu-img create -f qcow2 hda.img 5G
qemu-system-i386 -cdrom debian*.iso -hda hda.img -m 512

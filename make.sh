#!/bin/sh
# Make qemu machine and disk
wget http://get.debian.org/cdimage/archive/7.9.0-live/i386/iso-hybrid/debian-live-7.9.0-i386-standard.iso -O debian.img
sha512sum -c SHA512SUM
qemu-img create -f qcow2 hda.img 5G
qemu-system-i386 -cdrom debian*.iso -hda hda.img -m 512

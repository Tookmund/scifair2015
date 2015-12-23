#!/bin/sh
# Make qemu machine and disk
if [ ! -e debian.iso ]
then
	wget http://get.debian.org/cdimage/archive/7.9.0-live/i386/iso-hybrid/debian-live-7.9.0-i386-standard.iso -O debian.iso
fi

sha512sum -c SHA512SUMS || exit 0

if [ ! -e hda.img ]
then 
	qemu-img create -f qcow2 hda.img 5G
fi
qemu-system-i386 -cdrom debian.iso -hda hda.img -m 512

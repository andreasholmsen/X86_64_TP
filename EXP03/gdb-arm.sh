#!/bin/bash
if [[ "$XDG_CURRENT_DESKTOP" == *"GNOME"* ]]; then
	gsettings set org.gnome.desktop.wm.preferences focus-new-windows 'strict'
	gnome-terminal -- qemu-system-arm -M lm3s811evb -m 8K -nographic -no-reboot -kernel arm.bin -s -S
	./arm-gdb -command=arm-qemu.gdb
	gsettings set org.gnome.desktop.wm.preferences focus-new-windows 'handy'
fi

if [[ "$XDG_CURRENT_DESKTOP" == *"MATE"* ]]; then
	mate-terminal --tab -- qemu-system-arm -M lm3s811evb -m 8K -nographic -no-reboot -kernel arm.bin -s -S
	mate-terminal --tab -- ./arm-gdb -command=arm-qemu.gdb
fi

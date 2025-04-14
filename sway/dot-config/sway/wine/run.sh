#!/bin/bash

program=$(awk -F: '{print $1}' /home/veil/.config/sway/wine/paths | fuzzel -d)
wine "$(awk -F: "\$1 ~ /^$program$/ {print \$2}" /home/veil/.config/sway/wine/paths)"

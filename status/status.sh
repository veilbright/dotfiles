#!/bin/bash

time=$(date +'%l:%M')

volume=$(amixer -M get Master | tail -n 1 | awk '{print $5}')
volume=${volume:1:-1}

echo "$volume  $time"

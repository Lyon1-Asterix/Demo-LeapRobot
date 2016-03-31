#!/bin/bash
# script permettant de lancer processing et arduino en ligne de commande
# sans avoir besoin d'écran
Xvfb :1 -nolisten inet6 -screen :1 1280x800x24 &
export DISPLAY=":1"
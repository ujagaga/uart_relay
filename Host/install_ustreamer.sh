#!/bin/bash

# This script should be run as user. The ustreamer will be available via port 8013

SERVICE_NAME=ustreamer.service
SERVICE_FILE=/etc/systemd/system/$SERVICE_NAME

# Disable existing service if any
sudo systemctl disable $SERVICE_NAME

# Create new startup service
{
echo "[Unit]"
echo Description=webcam video streaming service
echo After=network-online.target
echo Wants=network-online.target
echo
echo "[Service]"
echo Type=simple
echo RemainAfterExit=yes
echo User=$USER
echo Group=$USER
echo Restart=on-failure
echo RestartSec=10s
echo ExecStart=$PWD/ustreamer.sh $PWD/ start
echo ExecStop=$PWD/ustreamer.sh $PWD/ stop
echo WorkingDirectory=$PWD
echo
echo "[Install]"
echo WantedBy=default.target
} > temp.service
sudo mv temp.service $SERVICE_FILE

# Enable service
sudo systemctl enable $SERVICE_NAME

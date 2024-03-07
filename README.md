# uart_relay

Uart controlled relay to power on/off a device.

## Problem
I have a device that I want to be able to power off remotelly. I have a web server near it, hosted on a small Linux computer with GPIO access, so the simplest thing to do would be to add a relay and write a Python script to trigger it. The problem arises when I need to restart this computer without afecting the relay.

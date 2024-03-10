# uart_relay

Uart controlled relay to power on/off a device.

## Problem

I have a device (3D printer) that I want to be able to power on/off remotelly (Octoprint is an overkill). I have a web server near it, hosted on a small Linux computer with GPIO access, so the simplest thing to do would be to add a relay and write a Python script to trigger it. The problem arises when I need to restart this computer without affecting the relay.

## Solution

A microcontroller triggers the relay but only after receiving the command via UART, so it will not depend on power cycle of the computer controlling it.

## Details

I am using an AtTiny85 based board (at 16MHz), but any microcontroller would do. All it needs is UART. AtTiny85 does not have a dedicated UART, but it does support a software serial implementation.

To prepare Arduino IDE to work wit AtTiny85, you can add to additional boards:

        https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json

The code sets UART on pins 2 (RX) and 4 (TX) at BAUD 9600. The Relay pin is pin 1 (LED)

To turn the Relay ON, send bytes:

        0xA5, 0x01

You should receive response "OK"

To turn it OFF, use:

        0xA5, 0x00

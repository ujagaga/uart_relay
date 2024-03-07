# uart_relay

Uart controlled relay to power on/off a device.

## Problem

I have a device that I want to be able to power on/off remotelly. I have a web server near it, hosted on a small Linux computer with GPIO access, so the simplest thing to do would be to add a relay and write a Python script to trigger it. The problem arises when I need to restart this computer without afecting the relay.

## Solution

A microcontroller triggers the relay but only after receiving the command via UART. It has an indipendent power supply, so it will not depend on power cycle of the computer controlling it.

## Details

I am using an AtTiny85 based board (at 16MHz), but any microcontroller would do. All it needs is UART. AtTiny85 does not have a dedicated UART, so I am using a software serial implementation.

## Status

Just starting this project, so not yet usable
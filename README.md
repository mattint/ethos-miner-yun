# ethos-miner-yun
An Arduino Yun client for ethos-miner-com
# Usage
* Connect your Front Panel Power- to GND.
* Connect your Front Panel Power+ to Pin 36.
* Flash your Arduino Yun with `avr.c`
* Copy other files to OpenWrt controller
* Install gems `net-telnet`, `sinatra`, `digest` and `rack`
* Set `rackup <PATH TO YOUR FOLDER>/main.ru` to `/etc/profile`
* Reboot your Arduino
* **Profit**

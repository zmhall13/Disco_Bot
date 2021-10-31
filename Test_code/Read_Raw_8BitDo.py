# Read_Raw_8BitDo.py
#
# Created: 2021-10-30
# Creator: zmhall13
# Purpose: Read in raw data from controller to map buttons/joystick values

# How to pair:
#   - Launch Bluetooth Control in terminal: sudo bluetoothctl
#   - Turn on the Bluetooth module: power on
#   - Turn on the Raspberry Pi Bluetooth agent: agent on
#   - Use the default agent: default-agent
#   - Turn on the Bluetooth Scan: scan on
#       - run first without the controller on to see list of other discoverable devices.
#   - Scan again after turning on the controller: scan on 
#       - Turn on the controller and wait for devices to pop up.
#   - Pair the Pi with the controller: pair <insert_8BitDo_MAC>
#       - Do not include the <> in above.
#       - Will say attempting to pair.
#       - Will ask to accept, type yes and hit enter.

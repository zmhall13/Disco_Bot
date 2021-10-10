# Disco_Bot
Created: 2021-10-10
Last Updated: 2021-10-10

## Setup
### Step 1: Format the SD Card
- Remove the micro SD card from the Pi.  Put the micro SD Card into an SD card adapter and plug into your computer.
- Download the Raspberry Pi Imager Tool found here: https://www.raspberrypi.com/software/.  Download the one that best suits your computer's operating system (OS).
- Once downloaded, run the installer.  This will install the Imager and then open it after installing.  If it is already installed, you can just run the Imager.  Running the already installed imager will bring up an install page, which is odd, but correct.  Follow on screen prompts to set it up.  
- Once it opens up to the "Choose OS" screen, select `Raspberry Pi OS (32-bit)` for the OS to be installed.  If it is not shown, select the top option for the Raspberry Pi OS.  Then choose the SD Card in the "Choose SD Card". Now select `WRITE`.
- When completed, it will say to remove the SD Card from the computer.  Remove the SD Card and close the Imager.
- Insert the SD Card into the Raspberry Pi and power it on.  The Pi will boot to the desktop.  Plug in a keyboard so you can type commands on the Pi.  Follow the on screen setup wizard.  Once completed the Pi will update and need to restart.
- Open the terminal.  The command line should now say `pi@raspberry:~ $`.  This is the root user directory.  Navigate to the root directory in the boot folder by typing:
```
cd /boot
```
- In this folder we will need to modify a file to get on the school's Wi-Fi to complete the setup process.  Type the following to open the `wpa_supplicant` file so we can change the ssid or Wi-Fi network name and the psk or the Wi-Fi password:
```
nano wpa_supplicant.conf
```
- Erase everything in this file and replace it with the following:
```
network {
  ssid="yourssid"
  psk="yourpsk"
}
```
Replace `yourssid` with the name of the network you want to connect to and `yourpsk` with your Wi-Fi password to the desired network.  Leave the quotes there for both lines.
- Exit the file while saving.  To do so, hit `Ctrl` + `X` to exit, `Y` to save, and `Enter` to confirm.
- Restart the Pi.
```
sudo reboot now
```
- Once the Pi has restarted, log in as before.  To verify you are connected, type the following:
```
hostname -I
```
It should return an IP address that looks similar to this 10.0.0.2.  If it does not return an IP, your ssid or password are wrong.  This step gives us the IP address that we will use in Step 2 to remote into the Pi.

### Step 2: Remote into the Pi.
- Download and install PuTTy on your computer, if it is not already installed.  Go here https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html to download the latest version for your computer.  If you have a windows machine, you will want the latest download in the `Package Files` section under the `MSI header`.  Most people will get the 64-bit x86 version.  It will look something like this `putty-64bit-0.76-installer.msi`.
- Follow the installer and put it some place you can find it easily.
- Before the Pi will allow you to remote in, you will porbably have to enable the secure shell (SSH).  Start that process by going to the pi and typing the following:
```
sudo raspi-config
```
This opens the Raspberry Pi Configuration Tool in the Command Line.
- Use the Up and Down arrows to navigate this menu, and left and right to select between the numbered list, `SELECT`, and `FINISH`.  Arrow down to `3 Interfacing Options` and hit `Enter` to select it.
- Arrow down to `2 SSH` and hit `Enter` to select it.
- Select `YES` using the left and right arrows then hit `Enter` to select it.
- Hit `Enter` again to okay.
- Arrow right to select `FINISH`.  Reboot to save changes.  If the Pi does not ask to reboot after selecting `FINISH`, then type the following in the command line do force a reboot:
```
sudo reboot now
```
- Now we can log in using PuTTY.  Use `hostname -I` to get the IP again if not saved.  Open PuTTY and make sure `Session` is selected in the top left under `Category`.  In the `Host Name` blank, type the IP of the Raspberry Pi.  Make sure the `SSH` bubble is selected below the IP and the `Port` is set to 22.  Save this setup as a profile for easier loading by entering a name in the `Saved Session` blank and clicking `Save`.  When you reboot the Pi from PuTTY, you lose connection with it and you have to do this step everytime you want to open it.  It saves time to create an easy to remember profile name so you can start PuTTY, select the profile name, and hit load.  Now select `Open` at the bottom right to SSH into the Pi's terminal.
- Log in again.  Now you can run commands from you computer to control the Pi.

### Step 3: Configure the Pi's settings.
- In the terminal (Pi or PuTTy), type the following to begin setting up the Pi for your area:
```
sudo raspi-config
```
- Go to `1 System Options`, `S4 Hostname`, `Enter`.  The Pi should be named `Disco-Bot`.
- Now go to `5 Localization Options`, `L2 Timezone`, select `America`, then `New York` for EST.
- Now go to `5 Localization Options`, `L4 WLAN Country`, select `US`, then `Enter` to confirm.
- Now go to `6 Update` to update the changes and update the tool to the lastest version.  Once this completes, you're donw with the configuration tool.  Select `FINISH` to escape.
- Reboot the Pi to make the changes.

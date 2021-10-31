# How to set up the SD Card from scratch

## **SD Card Setup**

1. Erase the SD card using the Raspberry Pi Imager Tool found in `Desktop/Parts Catalog/SD Cards/Raspberry Pi Imager.exe`.

2. Using the Raspberry Pi Imager Tool again, image the SD Card with the Ubuntu 20.04.3 image found in `Desktop/Parts Catalog/Raspberry Pi 3 Model B/Images/ubuntu-20.04.3-preinstalled-server-arm64+raspi.img`.

3. Eject the card and insert it into the Raspberry Pi.  Connect a keyboard via USB and a monitor to HDMI out.  Power on the Pi with an apporved power source.

## **First Power Up and Initial Setup**

1. During the first boot, the Pi will try to connect to the WI-Fi network above and will fail.  To try again, type the following:

```
sudo reboot
```

2. After the Pi goes through it's first start initializations, it will ask to log in.  Use `ubuntu` for the user and password. After a minute or so, the Pi will have booted completely.  You will know if you are connected to the internet once you log in because the splash screen will show an IP address.  If you are connected via ethernet and it still hasn't connected to the network, try:

```
sudo dhclient eth0
```

3. To set up Wi-Fi, run the following command in the terminal to get the network adapter options.  You will be looking to confirm that `wlan0` exists.

```
ls /sys/class/net
```

* Run the following command to open the Wi-Fi config file.

```
sudo nano /etc/netplan/50-cloud-init.yaml
```

* Type the following with the indents as they are.  Align the `w` in `wifis` with the `v` in the line `version: 2` of the file.

```
wifis:
  wlan0:
    dhcp4: true
    optional: true
    access-points:
      <wifi network name>:
        password: "<wifi password>"
```

* Change `<wifi network name>` to your wireless network's ssid inside quotation marks, silimar to `"Home Network"`.  Also, change the wifi password from `<wifi password>` to whatver your password is, but keep the quotation marks.  You may get something like this:

```
verison: 2
wifis:
  wlan0:
    dhcp4: true
    optional: true
    access-points:
      "Home Network":
        password: "Top5ecretPassword!"
```

* To set a static IP, replace the line containing `dhcp4: true` with the following for (example settings only) an IP of `192.168.1.23` in the `192.168.1.0/24` subnet of the default gateway having an IP of `192.168.1.1` and DNS server of `192.168.1.53`.  This method works for eth0 and wlan0.

```
addresses:
  - 192.168.101.23/24
gateway4: 192.168.1.1
nameservers:
  addresses: [192.168.1.23]
optional: true
```

* Hit `Ctrl` + `x`, then `y`, then `Enter` to save and exit.  Restart the Pi so it will try to connect to the network.

```
sudo shutdown -r now
```

4. To connect remotely to the Pi, you need the Pi's IP and to open an SSH client, such as PuTTy or a VM with an Ubuntu terminal opened.  To get the IP, run the following on the Pi terminal:

```
hostname -I
```

* This will return the IP address of the Pi.  To log into the Pi remotely, start your SSH client of Choice.  For PuTTy, enter the IP and click `Open`.  For a Linux machine such as a VM with Ubuntu, run the following command:

```
ssh ubuntu@XXX.XXX.XXX.XXX
```

* Plug in the IP of the Pi for the X's.  It will ask for the username and password, which is still `ubuntu` for both.  WHen it asks to confirm the connection, type `yes` to confirm.

5. After logging in, run the following to test ping Google's DNS server:

```
sudo ping -c 5 8.8.8.8
```

* Use `Ctrl` + `c` to stop the ping once a few go through.  You will know they have gone through when it gives a time.

6. Set the timezone by running a list all timezones command:

```
timedatectl list-timezones
```

* Press `Ctrl` + `c` to exit.  Remember the timezone you need to use form the list and enter it in this command:

```
sudo timedatectl set-timezone America/Chicago
```

* For Cookeville, use America/Chicago.  Check that the timezone and time were set correctly:

```
timedatectl
```

* Restart to let changes take effect:

```
sudo shutdown -r now
```

7. Perform Updates and Upgrades by typing the following:

```
sudo apt update
```

```
sudo apt upgrade
```

* It will ask if you want to proceed with the upgrade relatively soon after running the command, so type `y` and hit `Enter`.  Once all files are updated and upgraded, run `autoremove` to get rid of all the old files.

```
sudo apt autoremove
```

8. This step is optional here but highly recommended.  It is recommended to install the `build-essential` packages.  It is a group package that contains very common dependencies for other packages.

```
sudo apt install build-essential
```

```
sudo shutdown -r now
```

9. Change the name of the user account. Start by adding a temporary account called `temp`.

```
sudo adduser temp
```

* Also, change the password for this user.

```
sudo passwd temp
```

* Add the `temp` useer to the `sudo` user group.

```
sudo usermod -aG sudo temp
```

* Logout of the `ubuntu` user account.

```
exit
```

* Log in under the username `temp` as you normally would with the new password you gave it.
* Rename `ubuntu` to the `<newusername>` user and homefolder.  Do not include the `<>` anywhere the `<newusername>` is used.

```
sudo usermod -l <newusername> -d /home/<newusername> -m ubuntu
```

* Rename the group.

```
sudo groupmod -n <newusername> ubuntu
```

* Create symbollic link from the `ubuntu` to the `<newusername>`.

```
sudo ln -s /home/<newusername> /home/ubuntu
```

* Change the display name.

```
sudo chfn -f "firstname lastname" <newusername>
```

* Logout of the `temp` user by running `exit` again.  Now sign into the new user account.
* Delete the `temp` user account.

```
sudo userdel -r temp
```

* Remove the old folder fot the old ubuntu user.

```
sudo rm -R /home/ubuntu
```

10. Change the Hostname file by replacing the old one with the new hostname.

```
sudo nano /etc/hostname
```

* Open the `hosts` file and change any instance of old hostname to the new one.

```
sudo nano /etc/hosts
```

* Restart ubuntu to let any changes take effect.

```
sudo shutdown -r now
```

11. Install a lite version of a desktop.

```
sudo apt install lubuntu-desktop
```

* When it asks what default display manager to use, select `gdm3`.  Restart to apply changes.

```
sudo shutdown -r now
```

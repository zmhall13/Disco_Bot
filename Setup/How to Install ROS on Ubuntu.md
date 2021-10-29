# Introduction:

This markdown file (.md) is a step by step tutorial for installing ROS Noetic on Ubuntu server for the Raspberry Pi 4.



# **README**

**NOTE: Be sure Wi-Fi stays connected, otherwise the packages cannot be downloaded.**

**NOTE: Only use** `sudo` **(administratro privlages) when instructed. Using** `sudo` **could corrupt the the system if not careful.**

**NOTE: The following link should be read throughly before continuing:** http://wiki.ros.org/noetic/Installation/Ubuntu




# Istallation of ROS on Ubuntu:

1.) The sources list needs to be set up so Ubuntu will accept software from `packages.ros.org`:

    sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'


2.) Next is to setup the Authentication Key:

    sudo apt install curl # if you haven't already installed curl
    curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -


3.) The next step is to update the system:

    sudo apt update

    sudo apt upgrade

    sudo apt autoremove


4.) Restart the system to let any changes take effect:

    sudo shutdown -r now


5.) Now, install ROS Noetic:

    sudo apt install ros-noetic-desktop-full


6.) Next is to set up the environment variables:

    source /opt/ros/noetic/setup.bash

The above command will tell the terminal where to look, but everytime a new terminal is opened, the command must be executed to use ROS.  To setup the shell so the command runs everytime, place the command above in the `.bashrc` file.  The `.bashrc` executes everytime a new terminal window is opened.

    echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc

Then to update the terminal, close output of the current one and open a new one, or run:

    source ~/.bashrc


7.) Install dependencies for building ROS packages:

    sudo apt install python3-rosdep python3-rosinstall python3-rosinstall-generator python3-wstool build-essential


8.) Initialze `rosdep`:

    sudo rosdep init

    rosdep update


9.) To see if ROS was installed properly run:

    roscore

# Quick Setup

Follow these instructions using `Pi_3-Ubuntu_20_04_3-ROS_Base.img` as the base image.  These instructions go from newly installed ROS Noetic to package install and configuration as the project progresses.

## Instructions:

1. Flash the image mentioned above to a freshly erased SD Card.

2. Create the Catkin workspace and compile it.

```
cd ~
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws
catkin_make
```

* Source the Catkin environment and test the source was correct.  It will return `/home/ubuntu/catkin_ws/src:/opt/ros/noetic/share`.

```
source devel/setup.bash
echo $ROS_PACKAGE_PATH
```

* Open `.bashrc`.

```
cd ~
nano ~/.bashrc
```

* Add the catkin environment to the bottom.

```
source /home/pi/catkin_ws/devel/setup.bash
```

* To exit, `Ctrl` + `x`, `y`, then `Enter`.

3. Download all packages.

```
sudo apt install ros-noetic-teleop-twist-keyboard
sudo apt install ros-noetic-rosserial
```

4. Downlaod all repos.

```
cd ~/catkin_ws/src
git clone https://github.com/zmhall13/Disco_Bot.git
```

* Make downloaded repos.

```
cd ~/catkin_ws
catkin_make
```

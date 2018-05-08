# clipbot_arduino

This is the Arduino code my robot uses with <a href="https://github.com/static55/ClipbotCtrl">ClipbotCtrl</a> and <a href="https://github.com/static55/clipbot_sshd">clipbot_sshd</a>. It uses rosserial to accept ROS Twist messages from clipot_sshd that it interprets and sends to the motors.

Note that this project is configured for an Arduino Mega 2560. If you're using a different board, you'll need to find your board with `platformio boards` and then initialize a new platformio project with `platformio init --board <yourboard>`

# Installation

#### Install dependencies

`user@clipbot:~$ sudo apt-get install python-pip virtualenv ros-kinetic-rosserial-arduino ros-kinetic-rosserial`<br>

#### Upgrade/Install Pip and PlatformIO in a virtual environment to avoid clobbering Ubuntu-installed packages.

`user@clipbot:~$ mkdir clipbot_arduino`<br>
`user@clipbot:~$ cd clipbot_arduino`<br>
`user@clipbot:~/clipbot_arduino$ virtualenv env`<br>
`user@clipbot:~/clipbot_arduino$ source env/bin/activate`<br>
`(env) user@clipbot:~/clipbot_arduino$ easy_install -U pip`<br>
`(env) user@clipbot:~/clipbot_arduino$ easy_install -U platformio`<br>
`(env) user@clipbot:~/clipbot_arduino$ deactivate`<br>
`user@clipbot:~/clipbot_arduino$`

#### Clone repository.

`user@clipbot:~/clipbot_arduino$ git clone https://github.com/static55/clipbot_arduino.git`

#### Create rosserial include files.

`user@clipbot:~/clipbot_arduino$ cd clipbot_arduino`<br>
`user@clipbot:~/clipbot_arduino/clipbot_arduino$ rosrun rosserial_arduino make_libraries.py .`<br>
`user@clipbot:~/clipbot_arduino/clipbot_arduino$ mv ros_lib include`

#### Compile and upload to Arduino.

`user@clipbot:~/clipbot_arduino/clipbot_arduino$ source ../env/bin/activate`<br>
`(env) user@clipbot:~/clipbot_arduino/clipbot_arduino$ platformio run`<br>
`(env) user@clipbot:~/clipbot_arduino/clipbot_arduino$ platformio run -t upload`


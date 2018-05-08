# clipbot_arduino

This is the Arduino code my robot uses with <a href="https://github.com/static55/ClipbotCtrl">ClipbotCtrl</a> and <a href="https://github.com/static55/clipbot_sshd">clipbot_sshd</a>. It depends on rosserial to accept ROS Twist messages from clipot_sshd that it interprets and sends to the motors.

Note that this project is configured for an Arduino Mega 2560. If you're using a different board, you'll need to find your board with `platformio boards` and then initialize a new platformio project with `platformio init --board <yourboard>`

# Installation

#### Install dependencies

`user@clipbot:~$ sudo apt-get install python-pip virtualenv ros-kinetic-rosserial-arduino ros-kinetic-rosserial`<br>

#### Build a virtual python environment to avoid touching Ubuntu-installed packages.

`user@clipbot:~$ mkdir clipbot_arduino`<br>
`user@clipbot:~$ cd clipbot_arduino`<br>
`user@clipbot:~/clipbot_arduino$ virtualenv env`<br>
`user@clipbot:~/clipbot_arduino$ source env/bin/activate`<br>
`(env) user@clipbot:~/clipbot_arduino$ pip --version`<br>
`  pip 8.1.1 from /usr/lib/python2.7/dist-packages (python 2.7)`<br>
`(env) user@clipbot:~/clipbot_arduino$ easy_install -U pip`<br>
`(env) user@clipbot:~/clipbot_arduino$ pip --version`<br>
`  pip 10.0.1 from [...]/clipbot_arduino/env/local/lib/python2.7/site-packages/pip (python 2.7)`<br>
`(env) user@clipbot:~/clipbot_arduino$ easy_install -U platformio`

#### Clone repository.

`(env) user@clipbot:~/clipbot_arduino$ git clone https://github.com/static55/clipbot_arduino.git`

#### Create rosserial include files.

`(env) user@clipbot:~/clipbot_arduino$ deactivate`<br>
`user@clipbot:~/clipbot_arduino$ cd clipbot_arduino`<br>
`user@clipbot:~/clipbot_arduino/clipbot_arduino$ rosrun rosserial_arduino make_libraries.py .`<br>
`user@clipbot:~/clipbot_arduino/clipbot_arduino$ mv ros_lib include`

#### Compile and upload to Arduino.

`user@clipbot:~/clipbot_arduino/clipbot_arduino$ source ../env/bin/activate`<br>
`(env) user@clipbot:~/clipbot_arduino/clipbot_arduino$ platformio run`<br>
`(env) user@clipbot:~/clipbot_arduino/clipbot_arduino$ platformio run -t upload`


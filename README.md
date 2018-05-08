# clipbot_arduino

This is the Arduino code my robot uses with BotCtrl and clipbot_sshd. It depends on rosserial to accept ROS Twist messages from clipot_sshd that it interprets and sends to the motors.

# Installation

#### Install dependencies

`user@clipbot:~$ sudo apt-get install python-pip`<br>
`user@clipbot:~$ sudo apt-get install virtualenv`<br>
`user@clipbot:~$ sudo apt-get install ros-kinetic-rosserial-arduino`

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

`(env) user@clipbot:~/clipbot_arduino$ git clone https://github.com/static55/clipbot_arduino.git`<br>
`(env) user@clipbot:~/clipbot_arduino$ cd clipbot_arduino`<br>
`(env) user@clipbot:~/clipbot_arduino/clipboard_arduino$

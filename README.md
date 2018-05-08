# clipbot_arduino

This is the Arduino code my robot uses with BotCtrl and clipbot_sshd. It depends on rosserial to accept ROS Twist messages from clipot_sshd that it interprets and sends to the motors.

# Installation

#### Build a virtual python environment to avoid touching Ubuntu-installed packages.

`user@clipbot:~$ sudo apt-get install python-pip`<br>
`user@clipbot:~$ sudo apt-get install virtualenv`<br>
`user@clipbot:~$ mkdir clipbot_arduino`<br>
`user@clipbot:~$ cd clipbot_arduino`<br>
`user@clipbot:~/clipbot_arduino$ virtualenv env`<br>
`user@clipbot:~/clipbot_arduino$ source env/bin/activate`<br>
`(env) user@clipbot:~/clipbot_arduino$ pip --version`<br>
`pip 8.1.1 from /usr/lib/python2.7/dist-packages (python 2.7)`


#include <Arduino.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>

#include "fixsecnsec.hpp"

#include <stdlib.h>

// getting the pin numbers wrong is the cause of many headaches.
// be quick to suspect they are wrong if something screwy is happening.
#define FRONT_RIGHT_FORWARD_PIN 24
#define FRONT_RIGHT_BACKWARD_PIN 22
#define FRONT_RIGHT_PWM_PIN 8
#define MID_RIGHT_FORWARD_PIN 36
#define MID_RIGHT_BACKWARD_PIN 38
#define MID_RIGHT_PWM_PIN 5
#define REAR_RIGHT_FORWARD_PIN 53
#define REAR_RIGHT_BACKWARD_PIN 50
#define REAR_RIGHT_PWM_PIN 3
#define FRONT_LEFT_FORWARD_PIN 28
#define FRONT_LEFT_BACKWARD_PIN 26
#define FRONT_LEFT_PWM_PIN 9
#define MID_LEFT_FORWARD_PIN 40
#define MID_LEFT_BACKWARD_PIN 42
#define MID_LEFT_PWM_PIN 6
#define REAR_LEFT_FORWARD_PIN 46
#define REAR_LEFT_BACKWARD_PIN 48
#define REAR_LEFT_PWM_PIN 2

void onTwistReceived(const geometry_msgs::Twist &twist) {

  // currently linear x and angular z are numbers between -1 and 1.
  // the following scaling (0.75 and 0.45) isn't ideal because it
  // limits linear motion to 75% speed..
  
  float linearX = twist.linear.x * 0.75; // scale down the linear part a bit
  float angularZ = twist.angular.z * 0.45; // scale down the angular part much more..
  float rightRotation = linearX - angularZ; // combine linear and angular
  float leftRotation = linearX + angularZ;

  // set motor direction pins
  digitalWrite(FRONT_RIGHT_FORWARD_PIN, rightRotation >= 0 ? HIGH : LOW);
  digitalWrite(FRONT_RIGHT_BACKWARD_PIN, rightRotation >= 0 ? LOW : HIGH);
  digitalWrite(MID_RIGHT_FORWARD_PIN, rightRotation >= 0 ? HIGH : LOW);
  digitalWrite(MID_RIGHT_BACKWARD_PIN, rightRotation >= 0 ? LOW : HIGH);
  digitalWrite(REAR_RIGHT_FORWARD_PIN, rightRotation >= 0 ? HIGH : LOW);
  digitalWrite(REAR_RIGHT_BACKWARD_PIN, rightRotation >= 0 ? LOW : HIGH);
  digitalWrite(FRONT_LEFT_FORWARD_PIN, leftRotation >= 0 ? HIGH : LOW);
  digitalWrite(FRONT_LEFT_BACKWARD_PIN, leftRotation >= 0 ? LOW : HIGH);
  digitalWrite(MID_LEFT_FORWARD_PIN, leftRotation >= 0 ? HIGH : LOW);
  digitalWrite(MID_LEFT_BACKWARD_PIN, leftRotation >= 0 ? LOW : HIGH);
  digitalWrite(REAR_LEFT_FORWARD_PIN, leftRotation >= 0 ? HIGH : LOW);
  digitalWrite(REAR_LEFT_BACKWARD_PIN, leftRotation >= 0 ? LOW : HIGH);
  
  rightRotation = abs(rightRotation);
  leftRotation = abs(leftRotation);
  if (rightRotation > 1) { rightRotation = 1; }
  if (leftRotation > 1) { leftRotation = 1; }

  // set motor speed (pwm) pins
  analogWrite(FRONT_RIGHT_PWM_PIN, (int)(rightRotation * 255));
  analogWrite(MID_RIGHT_PWM_PIN, (int)(rightRotation * 255));
  analogWrite(REAR_RIGHT_PWM_PIN, (int)(rightRotation * 255));
  analogWrite(FRONT_LEFT_PWM_PIN, (int)(leftRotation * 255));
  analogWrite(MID_LEFT_PWM_PIN, (int)(leftRotation * 255));
  analogWrite(REAR_LEFT_PWM_PIN, (int)(leftRotation * 255));  
}

ros::NodeHandle nh;
ros::Subscriber<geometry_msgs::Twist> sub("twist", onTwistReceived);

void setup() {

  nh.initNode();
  nh.subscribe(sub);
}

void loop() {

  nh.spinOnce();
  delay(1);
}

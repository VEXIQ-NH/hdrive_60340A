#pragma config(Sensor, port5,  led1,           sensorVexIQ_LED)
#pragma config(Motor,  motor1,          leftMotor,     tmotorVexIQ, openLoop, driveLeft, encoder)
#pragma config(Motor,  motor2,          rightArm,      tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor3,          h,             tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor4,          frontClaw,     tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor6,          rightMotor,    tmotorVexIQ, openLoop, reversed, driveRight, encoder)
#pragma config(Motor,  motor7,          leftArm,       tmotorVexIQ, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


task main()
{
	repeat (forever) {
		tankControl(ChD, ChA, 75);  //left and right drive motors
		armControl(h, BtnLUp, BtnLDown, 100);  //controls the h-drive (5th wheel)
		armControl(rightArm, BtnRUp, BtnRDown, 100); 
		armControl(leftArm, BtnRUp, BtnRDown, 100);
		armControl(frontClaw, BtnEUp, BtnEDown, 100);  //controls mini claw in front
		
    // if frontClaw is fully open, LED green
    if (getMotorEncoder(frontClaw) <= -10) {
			setTouchLEDColor(port5, colorGreen);
		}
    
    // if frontClaw is fully closed, LED green
		if (getMotorEncoder(frontClaw) > -10) {
			setTouchLEDColor(port5, colorRed);
		}
	}
}

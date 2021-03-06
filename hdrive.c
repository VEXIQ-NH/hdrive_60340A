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
		tankControl(ChA, ChD, 10);
		armControl(rightArm, BtnLUp, BtnLDown, 100);
		armControl(leftArm, BtnLUp, BtnLDown, 100);
		armControl(frontClaw, BtnEUp, BtnEDown, 100);
		armControl(h, BtnRUp, BtnRDown, 100);
	}
}

﻿using UnityEngine;

public class CameraController : MonoBehaviour
{
	private	float	rotateSpeedX = 3;
	private	float	rotateSpeedY = 5;
	private	float	limitMinX = -80;
	private	float	limitMaxX = 50;
	private	float	eulerAngleX;
	private	float	eulerAngleY;

	public void RotateTo(float mouseX, float mouseY)
	{
		// 마우스를 좌/우로 움직이는 mouseX 값을 y축에 대입하는 이유는
		// 마우스를 좌/우로 움직일 때 카메라도 좌/우를 보려면 카메라 오브젝트의
		// y축이 회전되어야 하기 때문
		eulerAngleY += mouseX * rotateSpeedX;
		// 같은 개념으로 카메라가 위/아래를 보려면 카메라 오브젝트의 x축이 회전!
		eulerAngleX -= mouseY * rotateSpeedY;

		// x축 회전 값의 경우 아래, 위를 볼 수 있는 제한 각도가 설정되어 있다
		eulerAngleX = ClampAngle(eulerAngleX, limitMinX, limitMaxX);

		// 실제 오브젝트의 쿼터니온 회전에 적용
		transform.rotation = Quaternion.Euler(eulerAngleX, eulerAngleY, 0);
	}

	private float ClampAngle(float angle, float min, float max)
	{
		if ( angle < -360 )	angle += 360;
		if ( angle > 360 )	angle -= 360;

		// Mathf.Clamp()를 이용해 angle이 min <= angle <= max을 유지하도록 함
		return Mathf.Clamp(angle, min, max);
	}
}


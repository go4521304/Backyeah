using UnityEngine;

public class CameraController : MonoBehaviour
{
	public GameObject Target;

    private float CamOffset;
    private float rotateX, rotateY;

    private void Start()
    {
        CamOffset = (Target.transform.position - transform.position).magnitude;

        Vector3 tmp = transform.position - Target.transform.position;
        rotateX = Mathf.Atan2(tmp.z, tmp.x) * Mathf.Rad2Deg;
        rotateY = Mathf.Asin(tmp.y / CamOffset) * Mathf.Rad2Deg;
    }

    public void RotateTo(float mouseX, float mouseY, float mouseScroll)
	{
        rotateX -= mouseX;
        rotateY -= mouseY;
        CamOffset -= mouseScroll;

        rotateY = ClampAngle(rotateY, -80, 50);

        float X = rotateX * Mathf.Deg2Rad, Y = rotateY * Mathf.Deg2Rad;
        Vector3 CamPos = new Vector3();
        CamPos.x = CamOffset * Mathf.Cos(X) * Mathf.Cos(Y);
        CamPos.y = CamOffset * Mathf.Sin(Y);
        CamPos.z = CamOffset * Mathf.Cos(Y) * Mathf.Sin(X);
        CamPos += Target.transform.position;

        transform.position = CamPos;
        transform.LookAt(Target.transform.position);

        RaycastHit hit;
        Ray ray = new Ray(transform.position, transform.forward);
        if (Physics.Raycast(ray, out hit, CamOffset))
        {
            if (hit.point != Vector3.zero && hit.collider.gameObject != Target)
            {
                transform.transform.position = hit.point;
            }
        }
    }

    private float ClampAngle(float angle, float min, float max)
	{
		if ( angle < -360 )	angle += 360;
		if ( angle > 360 )	angle -= 360;

		// Mathf.Clamp()를 이용해 angle이 min <= angle <= max을 유지하도록 함
		return Mathf.Clamp(angle, min, max);
	}
}


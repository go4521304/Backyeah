using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test : MonoBehaviour
{
    [SerializeField]
    public CameraController P;
    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 tt = new Vector3();
        //tt.x = 5f * Mathf.Cos(P.rotateX * Mathf.Deg2Rad);
        //tt.z = 5f * Mathf.Sin(P.rotateX * Mathf.Deg2Rad);

        //tt.y = P.rotateY * Mathf.Deg2Rad;

        float X = P.rotateX * Mathf.Deg2Rad, Y = P.rotateY * Mathf.Deg2Rad;
        tt.x = 5f * Mathf.Cos(X) * Mathf.Cos(Y);
        tt.y = 5f * Mathf.Sin(Y);
        tt.z = 5f * Mathf.Cos(Y) * Mathf.Sin(X);
        transform.position = tt;
    }
}

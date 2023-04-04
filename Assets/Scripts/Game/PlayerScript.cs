using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerScript : MonoBehaviour
{
    public Collider2D groundCollider;

    private Rigidbody2D _rigidbody2D;
    private PolygonCollider2D _polygonCollider2D;


    private float _horizontalforce = 3;
    private float _horizontalspeed = 2f;
    private float _jumpforce = 3;
    
    // Start is called before the first frame update
    void Start()
    {
        _rigidbody2D = GetComponent<Rigidbody2D>();
        _polygonCollider2D = GetComponent<PolygonCollider2D>();

    }

    // Update is called once per frame
    void FixedUpdate()
    {
        bool onGround = _rigidbody2D.IsTouching(groundCollider);
        if (Input.GetKey(KeyCode.A))
        {
            _rigidbody2D.AddForce(Vector2.left * _horizontalforce);
            if(onGround) _rigidbody2D.velocity = Vector2.left * _horizontalspeed;
        }

        if (Input.GetKey(KeyCode.D))
        {
            _rigidbody2D.AddForce(Vector2.right * _horizontalforce);
            if(onGround) _rigidbody2D.velocity = Vector2.right * _horizontalspeed;
        }

        if (onGround)
        {
            if (Input.GetKey(KeyCode.Space))
            {
                _rigidbody2D.velocity += Vector2.up * _jumpforce;
            }
        }
    }
}

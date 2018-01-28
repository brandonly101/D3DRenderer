#include "Object.h"

namespace D3DRenderer
{
    /// Static member functions

    Object Object::CreateCube()
    {
        Object result;

        result.vertices = new DirectX::SimpleMath::Vector3[24]
        {
            // Front face
            DirectX::SimpleMath::Vector3(-1.0, -1.0,  1.0),
            DirectX::SimpleMath::Vector3(1.0, -1.0,  1.0),
            DirectX::SimpleMath::Vector3(1.0,  1.0,  1.0),
            DirectX::SimpleMath::Vector3(-1.0,  1.0,  1.0),

            // Back face
            DirectX::SimpleMath::Vector3(-1.0, -1.0, -1.0),
            DirectX::SimpleMath::Vector3(-1.0,  1.0, -1.0),
            DirectX::SimpleMath::Vector3(1.0,  1.0, -1.0),
            DirectX::SimpleMath::Vector3(1.0, -1.0, -1.0),

            // Top face
            DirectX::SimpleMath::Vector3(-1.0,  1.0, -1.0),
            DirectX::SimpleMath::Vector3(-1.0,  1.0,  1.0),
            DirectX::SimpleMath::Vector3(1.0,  1.0,  1.0),
            DirectX::SimpleMath::Vector3(1.0,  1.0, -1.0),

            // Bottom face
            DirectX::SimpleMath::Vector3(-1.0, -1.0, -1.0),
            DirectX::SimpleMath::Vector3(1.0, -1.0, -1.0),
            DirectX::SimpleMath::Vector3(1.0, -1.0,  1.0),
            DirectX::SimpleMath::Vector3(-1.0, -1.0,  1.0),

            // Right face
            DirectX::SimpleMath::Vector3(1.0, -1.0, -1.0),
            DirectX::SimpleMath::Vector3(1.0,  1.0, -1.0),
            DirectX::SimpleMath::Vector3(1.0,  1.0,  1.0),
            DirectX::SimpleMath::Vector3(1.0, -1.0,  1.0),

            // Left face
            DirectX::SimpleMath::Vector3(-1.0, -1.0, -1.0),
            DirectX::SimpleMath::Vector3(-1.0, -1.0,  1.0),
            DirectX::SimpleMath::Vector3(-1.0,  1.0,  1.0),
            DirectX::SimpleMath::Vector3(-1.0,  1.0, -1.0)
        };

        result.normals = new DirectX::SimpleMath::Vector3[24]
        {
            // Front face
            DirectX::SimpleMath::Vector3(0.0, 0.0, 1.0),
            DirectX::SimpleMath::Vector3(0.0, 0.0, 1.0),
            DirectX::SimpleMath::Vector3(0.0, 0.0, 1.0),
            DirectX::SimpleMath::Vector3(0.0, 0.0, 1.0),

            // Back Face
            DirectX::SimpleMath::Vector3(0.0, 0.0, -1.0),
            DirectX::SimpleMath::Vector3(0.0, 0.0, -1.0),
            DirectX::SimpleMath::Vector3(0.0, 0.0, -1.0),
            DirectX::SimpleMath::Vector3(0.0, 0.0, -1.0),

            // Top Face
            DirectX::SimpleMath::Vector3(0.0, 1.0, 0.0),
            DirectX::SimpleMath::Vector3(0.0, 1.0, 0.0),
            DirectX::SimpleMath::Vector3(0.0, 1.0, 0.0),
            DirectX::SimpleMath::Vector3(0.0, 1.0, 0.0),

            // Bottom face
            DirectX::SimpleMath::Vector3(0.0, -1.0, 0.0),
            DirectX::SimpleMath::Vector3(0.0, -1.0, 0.0),
            DirectX::SimpleMath::Vector3(0.0, -1.0, 0.0),
            DirectX::SimpleMath::Vector3(0.0, -1.0, 0.0),

            // Right face
            DirectX::SimpleMath::Vector3(1.0, 0.0, 0.0),
            DirectX::SimpleMath::Vector3(1.0, 0.0, 0.0),
            DirectX::SimpleMath::Vector3(1.0, 0.0, 0.0),
            DirectX::SimpleMath::Vector3(1.0, 0.0, 0.0),

            // Left face
            DirectX::SimpleMath::Vector3(-1.0, 0.0, 0.0),
            DirectX::SimpleMath::Vector3(-1.0, 0.0, 0.0),
            DirectX::SimpleMath::Vector3(-1.0, 0.0, 0.0),
            DirectX::SimpleMath::Vector3(-1.0, 0.0, 0.0)
        };

        //result.vertexIndices = new DirectX::SimpleMath::Vector3[32];

        return result;
    }

    Object Object::CreateSphere()
    {
        Object result;

        // TODO: implement this; for now, it just returns a cube...
        result = CreateCube();

        return result;
    }

    /// Object Construction and Destruction

    Object::Object()
    {
        vertices = NULL;
        vertexIndices = NULL;
        normals = NULL;
    }

    Object::~Object()
    {
        if (vertices != NULL)
        {
            delete[] vertices;
        }
        if (vertexIndices != NULL)
        {
            delete[] vertexIndices;
        }
        if (normals != NULL)
        {
            delete[] vertexIndices;
        }
    }

    /// Public member functions

    // Render the Object, given its member vertices, vertex indices, normals, and other information
    void Object::Render()
    {

    }
}

#pragma once

#include <vector>

#include <dxgi.h>
#include <d3d11.h>

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")

#include <SimpleMath.h>

namespace D3DRenderer
{
    class Object
    {
    public:
        Object();
        ~Object();

        static Object CreateCube();
        static Object CreateSphere();

        DirectX::SimpleMath::Vector3 Position;
        DirectX::SimpleMath::Quaternion Rotation;
        DirectX::SimpleMath::Vector3 Scale;

        void Render();

    private:
        DirectX::SimpleMath::Vector3* vertices;
        DirectX::SimpleMath::Vector3* vertexIndices;
        DirectX::SimpleMath::Vector3* normals;
    };
}

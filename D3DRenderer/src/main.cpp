// Using SDL and standard IO
#include <stdio.h>
#include <SDL.h>
#include <SDL_syswm.h>
#include <wrl.h>

#include <dxgi.h>
#include <d3d11.h>

#include <SimpleMath.h>

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")

using namespace DirectX::SimpleMath;

// Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

void InitD3D();
void ReleaseD3D();
void Render();

IDXGISwapChain* swapChain;
ID3D11Device* device;
ID3D11DeviceContext* context;
HWND hWnd;
ID3D11RenderTargetView *backBuffer;

int main(int argc, char* args[])
{
    // Start SDL
    int pid = SDL_Init(SDL_INIT_EVERYTHING);
    if (pid < 0)
    {
        printf("Could not initialize SDL - SDL_Error : %s\n", SDL_GetError());
        return -1;
    }

    // Create Window
    SDL_Window* window = SDL_CreateWindow("D3D Renderer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("ERROR: Could not create window (SDL_Error : %s)\n", SDL_GetError());
        return -1;
    }

    // Create Surface
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    if (surface == NULL)
    {
        printf("ERROR: Could not create surface (SDL_Error : %s)\n", SDL_GetError());
        return -1;
    }
    SDL_UpdateWindowSurface(window);

    // Get WM info
    SDL_SysWMinfo SDLSysWMInfo;
    SDL_VERSION(&SDLSysWMInfo.version);
    if (SDL_GetWindowWMInfo(window, &SDLSysWMInfo) != SDL_TRUE)
    {
        printf("ERROR: Cannot get WM information (SDL_Error : %s)\n", SDL_GetError());
        return -1;
    }
    hWnd = SDLSysWMInfo.info.win.window;

    // Init D3D11
    InitD3D();

    bool running = true;
    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }
    }

    // Release D3D objects
    ReleaseD3D();

    // Destroy SDL Window
    SDL_DestroyWindow(window);

    // Quit SDL
    SDL_Quit();

    return 0;
}

void InitD3D()
{
    DWORD createDeviceFlags = 0;
#ifdef _DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    // Create swap chain desc struct and zero out
    DXGI_SWAP_CHAIN_DESC swapChainDesc;
    ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

    // Fill in swap chain properties
    swapChainDesc.BufferCount = 1;                                    // one back buffer
    swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;     // use 32-bit color
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;      // how swap chain is to be used
    swapChainDesc.OutputWindow = hWnd;                                // the window to be used
    swapChainDesc.SampleDesc.Count = 4;                               // how many multisamples
    swapChainDesc.Windowed = TRUE;                                    // windowed/full-screen mode

    HRESULT hrDevice = D3D11CreateDeviceAndSwapChain(
            NULL,
            D3D_DRIVER_TYPE_HARDWARE,
            NULL,
            createDeviceFlags,
            NULL,
            NULL,
            D3D11_SDK_VERSION,
            &swapChainDesc,
            &swapChain,
            &device,
            NULL,
            &context);

    // Get address of back buffer
    ID3D11Texture2D *pBackBuffer;
    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer);

    // Set the back buffer address to create the render target
    device->CreateRenderTargetView(pBackBuffer, NULL, &backBuffer);
    pBackBuffer->Release();

    // Set the render target as the back buffer
    context->OMSetRenderTargets(1, &backBuffer, NULL);

    // Set the viewport
    D3D11_VIEWPORT viewport;
    ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

    viewport.TopLeftX = 0;
    viewport.TopLeftY = 0;
    viewport.Width = SCREEN_WIDTH;
    viewport.Height = SCREEN_HEIGHT;

    context->RSSetViewports(1, &viewport);

    // Clear the back buffer
    context->ClearRenderTargetView(backBuffer, Color(0.0f, 0.2f, 0.4f, 1.0f));

    // Switch back buffer and front buffer
    swapChain->Present(0, 0);
}

void ReleaseD3D()
{
    swapChain->Release();
    backBuffer->Release();
    device->Release();
    context->Release();
}

void Render()
{
    // Clear the back buffer
    context->ClearRenderTargetView(backBuffer, Color(0.0f, 0.2f, 0.4f, 1.0f));

    // Do 3D rendering stuff (in the future)

    // Switch back buffer and front buffer
    swapChain->Present(0, 0);
}

#include <emscripten.h>
#include <emscripten/html5.h>
#include <iostream>

int main(int argc, char** argv) 
{
    EmscriptenWebGLContextAttributes attrs;
    attrs.alpha = false;
    attrs.depth = true;
    attrs.stencil = true;
    attrs.antialias = true;
    attrs.premultipliedAlpha = false;
    attrs.preserveDrawingBuffer = false;
    attrs.failIfMajorPerformanceCaveat = false;
    attrs.majorVersion = 2;
    attrs.minorVersion = 0;
    attrs.enableExtensionsByDefault = false;

    int ctx = emscripten_webgl_create_context("#canvas", &attrs);
    if(!ctx)
    {
        std::cout << "Error: WebGL context could not be created." << std::endl;
        return -1;
    }    

    emscripten_webgl_make_context_current(ctx);
    glClearColor(0,0,0.5,1); // Set the clear color (backgroun) to dark blue.
    glClear(GL_COLOR_BUFFER_BIT);

    return 0;
}
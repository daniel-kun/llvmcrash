// Main program that links "libcrashme.so" and initializes OpenGL 
// - which in turn uses mesa, which uses llvm-3.4
#include "GL/freeglut.h"
#include "GL/gl.h"

void foo(); // Defined in libcrashme.so

// Dummy OpenGL display func
void display ()
{
}

int main(int argc, char** argv)
{
    foo(); // Call our dummy llvm function, that actually does nothing. This is required for the crash
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("This crashes when using an llvm lib");
    // Crash happens here:
    glutDisplayFunc(display);
    glutMainLoop();
}


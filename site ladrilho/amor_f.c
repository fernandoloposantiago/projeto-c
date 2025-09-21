#include <GL/glut.h>
#include <math.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0); // vermelho
    glBegin(GL_POLYGON);

    // Desenha um coração com dois semicírculos e um V
    for (float angle = 0; angle <= M_PI; angle += 0.01) {
        glVertex2f(0.5 * cos(angle) - 0.5, 0.5 * sin(angle) + 0.5);
        glVertex2f(0.5 * cos(angle) + 0.5, 0.5 * sin(angle) + 0.5);
    }

    glVertex2f(0.0, -0.7); // ponta do coração

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Coração 3D OpenGL");
    glutInitWindowSize(800, 600);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

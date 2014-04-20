#include "openglwidget.h"
#include <GL/glu.h>
#include <math.h>

OpenGLWidget::OpenGLWidget(QWidget *parent) :
    QGLWidget(parent),
    x(0),
    y(0),
    radius(50),
    color( Qt::white )
{

}

void OpenGLWidget::setX( qreal x ) { this->x = x; }
qreal OpenGLWidget::getX() { return x; }

void OpenGLWidget::setY( qreal y ) { this->y = y; }
qreal OpenGLWidget::getY() { return y; }

void OpenGLWidget::setRadius( qreal radius ) { this->radius = radius; }
qreal OpenGLWidget::getRadius() { return radius; }

void OpenGLWidget::setColor( const QColor & color ) { this->color = color; }
QColor OpenGLWidget::getColor() { return color; }

void OpenGLWidget::drawCircle( qreal x, qreal y, qreal radius, const QColor & color )
{
    qglColor( color );

    // рисование круга
    glBegin( GL_TRIANGLE_FAN );
    glVertex2d( x, y );
    for( int i = 0; i <= radius; i++ )
    {
        qreal temp = ( qreal ) i / radius * M_PI * 2.0;
        glVertex2d( x + cos(temp) * ( radius / 10.0 ), y + sin(temp) * ( radius / 10.0 ) );
    }
    glEnd();
}

void OpenGLWidget::initializeGL()
{
    qglClearColor( Qt::black );
}
void OpenGLWidget::resizeGL(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glViewport(0, 0, width, height);
    gluOrtho2D(0, width, 0, height);
}
void OpenGLWidget::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT );
    glPushMatrix();
    glTranslated( width() / 2, height() / 2, 0 );

    drawCircle( x, y, radius, color );

    glPopMatrix();
}

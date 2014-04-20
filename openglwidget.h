#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QGLWidget>

class OpenGLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit OpenGLWidget(QWidget *parent = 0);

private:
    qreal x;
    qreal y;
    qreal radius;
    QColor color;

public slots:
    void setX( qreal x );
    qreal getX();

    void setY( qreal y );
    qreal getY();

    void setRadius( qreal r );
    qreal getRadius();

    void setColor( const QColor & color );
    QColor getColor();

private:
    void drawCircle( qreal x, qreal y, qreal radius, const QColor & color );

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
};

#endif // OPENGLWIDGET_H

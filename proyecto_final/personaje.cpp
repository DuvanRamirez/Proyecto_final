#include "personaje.h"

personaje::personaje(QObject *parent) : QObject(parent)
{

    timer = new QTimer();
    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(":/Imagenes/personaje1.png");

    //dimensiones de c/U de las imagenes
    ancho = 56.25;
    alto  = 38;

    timer->start(300);// modifica la velocidad en que itera entre las imagenes

    connect(timer,&QTimer::timeout,this,&personaje::Actualizacion);


}

void personaje::Actualizacion()
{
    columnas +=56.25;
    if(columnas >=225)
    {
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,56.25,38);

}
QRectF personaje::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

#include "personaje2.h"

personaje2::personaje2(QObject *parent) : QObject(parent)
{

    timer = new QTimer();
    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(":/Imagenes/personaje2.png");

    //dimensiones de c/U de las imagenes
    ancho = 50;
    alto  = 55;

    timer->start(100);// modifica la velocidad en que itera entre las imagenes

    connect(timer,&QTimer::timeout,this,&personaje2::Actualizacion);


}

void personaje2::Actualizacion()
{
    columnas +=50;
    if(columnas >=348)
    {
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);

}
QRectF personaje2::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void personaje2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}


#include "corazon.h"

Corazon::Corazon(QObject *parent) : QObject(parent)
{

    timer = new QTimer();
    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(":/Imagenes/corazon relleno.png");

    //dimensiones de c/U de las imagenes
    ancho = 40.6;
    alto  = 35;

    timer->start(500);// modifica la velocidad en que itera entre las imagenes

    connect(timer,&QTimer::timeout,this,&Corazon::Actualizacion);


}

void Corazon::Actualizacion()
{
    columnas +=40.6;
    if(columnas >=203)
    {
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,40.6,35);

}
QRectF Corazon::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Corazon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

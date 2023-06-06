#include "fantasma.h"

Fantasma::Fantasma(QObject *parent) : QObject(parent)
{

    timer = new QTimer();
    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(":/Imagenes/fantasma.png");

    //dimensiones de c/U de las imagenes
    ancho = 76.1;
    alto  = 73;

    timer->start(200);// modifica la velocidad en que itera entre las imagenes

    connect(timer,&QTimer::timeout,this,&Fantasma::Actualizacion);


}

void Fantasma::Actualizacion()
{
    columnas +=76.1;
    if(columnas >=684.9)
    {
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);

}
QRectF Fantasma::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Fantasma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

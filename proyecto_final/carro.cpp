#include "carro.h"

Carro::Carro()
{

}

QRectF Carro::boundingRect() const
{
    return QRectF(-40,-40,80,220);
}

void Carro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes/carro.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

#include "bloquefinal.h"

Bloquefinal::Bloquefinal()
{

}

QRectF Bloquefinal::boundingRect() const
{
    return QRectF(-200,-30,416,60);
}

void Bloquefinal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes/bloquefinal.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

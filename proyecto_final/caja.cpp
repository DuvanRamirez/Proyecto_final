#include "caja.h"

Caja::Caja()
{

}

QRectF Caja::boundingRect() const
{
    return QRectF(-30,-30,60,60);
}

void Caja::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes/caja.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

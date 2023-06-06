#include "bloquemenu.h"

Bloquemenu::Bloquemenu()
{

}

QRectF Bloquemenu::boundingRect() const
{
    return QRectF(-195,-20,400,59);
}

void Bloquemenu::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes/bloquefinal.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

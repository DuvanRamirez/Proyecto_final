#include "botones.h"

Botones::Botones(){

}

QRectF Botones::boundingRect() const
{
    return QRectF(0,0,125,10);
}

void Botones::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes/level 1.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

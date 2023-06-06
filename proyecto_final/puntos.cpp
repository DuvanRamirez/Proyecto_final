#include "puntos.h"

puntos::puntos()
{

}

QRectF puntos::boundingRect() const
{
    return QRectF(-15,-15,30,30);
}

void puntos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes/corazon.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}


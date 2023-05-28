#include "personaje.h"

personaje::personaje()
{

}

QRectF personaje::boundingRect() const
{
    return QRectF(-30,-30,70,60);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes/personaje.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

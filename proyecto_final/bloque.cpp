#include "bloque.h"

Bloque::Bloque()
{

}

QRectF Bloque::boundingRect() const
{
    return QRectF(-30,-30,60,60);
}

void Bloque::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes/bloque.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

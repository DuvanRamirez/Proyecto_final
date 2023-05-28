#include "tubo.h"

tubo::tubo()
{

}

QRectF tubo::boundingRect() const
{
    return QRectF(-50,-50,100,150);
}

void tubo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Imagenes/tubo.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

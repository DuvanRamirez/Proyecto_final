#ifndef TUBO_H
#define TUBO_H
#include <QGraphicsItem>
#include <QPainter>

class tubo : public QGraphicsItem
{
public:
    tubo();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // TUBO_H

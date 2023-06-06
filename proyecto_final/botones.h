#ifndef BOTONES_H
#define BOTONES_H
#include <QGraphicsItem>
#include <QPainter>

class Botones : public QGraphicsItem
{
public:
    Botones();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);


};
#endif // BOTONES_H

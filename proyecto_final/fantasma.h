#ifndef FANTASMA_H
#define FANTASMA_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Fantasma : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Fantasma(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    float filas,columnas;

    float ancho;
    float alto;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


signals:

public slots:
    void Actualizacion();
};
#endif // FANTASMA_H

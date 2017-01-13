#include "graphicsvertex.h"

#include <QBrush>
#include <QGraphicsSimpleTextItem>
#include <QPainter>
#include <QPen>

GraphicsVertex::GraphicsVertex(QPointF pos, QString label)
{
        setPos(pos);
        if(label.isEmpty())
        {
                mLabel = Q_NULLPTR;
        }
        else
        {
                mLabel = new QGraphicsSimpleTextItem(label, this);
                mLabel->setPos(-mLabel->boundingRect().width() / 2.0, 5.0);
        }
        setZValue(1.0);
}

QRectF GraphicsVertex::boundingRect() const
{
        return QRectF(-5.0, -5.0, 10.0, 10.0);
}

void GraphicsVertex::paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
{
       painter->setPen(QPen(Qt::gray, 10.0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
       painter->setRenderHint(QPainter::Antialiasing);
       painter->drawPoint(0, 0);
}

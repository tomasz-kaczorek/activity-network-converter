#include "graphicsedge.h"

#include <QGraphicsSimpleTextItem>
#include <QPainter>

GraphicsEdge::GraphicsEdge(QLineF line, QString label) :
        QGraphicsLineItem(line)
{
        if(label.isEmpty())
        {
                mLabel = Q_NULLPTR;
        }
        else
        {
                mLabel = new QGraphicsSimpleTextItem(label, this);
                mLabel->setPos(line.pointAt(0.5) - mLabel->boundingRect().center());
        }
        setPen(QPen(Qt::gray, 2.0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        setZValue(0.0);
}

GraphicsEdge::GraphicsEdge(QLineF line, bool fake) :
        QGraphicsLineItem(line)
{
        setPen(QPen(Qt::gray, 2.0, fake ? Qt::DashLine : Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        setZValue(0.0);
}

QRectF GraphicsEdge::boundingRect() const
{
        return QGraphicsLineItem::boundingRect().adjusted(-5.0, -5.0, 5.0, 5.0);
}

void GraphicsEdge::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
        QGraphicsLineItem::paint(painter, option, widget);
        painter->setPen(QPen(Qt::gray, 2.0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter->translate(line().p2());
        painter->rotate(-line().angle());
        painter->drawLine(-25.0, -2.5, -5.0, 0.0);
        painter->drawLine(-25.0, 2.5, -5.0, 0.0);
}

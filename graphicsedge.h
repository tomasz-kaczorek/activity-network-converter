#ifndef GRAPHICSEDGE_H
#define GRAPHICSEDGE_H

#include <QGraphicsLineItem>

class QGraphicsSimpleTextItem;

class GraphicsEdge : public QGraphicsLineItem
{
        public:
                GraphicsEdge(QLineF line, QString label);
                GraphicsEdge(QLineF line, bool fake = false);
                QRectF boundingRect() const;
                void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
        private:
                QGraphicsSimpleTextItem * mLabel;
};

#endif // GRAPHICSEDGE_H

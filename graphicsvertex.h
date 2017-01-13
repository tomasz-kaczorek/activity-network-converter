#ifndef GRAPHICSVERTEX_H
#define GRAPHICSVERTEX_H

#include <QGraphicsItem>

class QGraphicsSimpleTextItem;

class GraphicsVertex : public QGraphicsItem
{
        public:
                GraphicsVertex(QPointF pos, QString label = QString::null);
                QRectF boundingRect() const;
                void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
        private:
                QGraphicsSimpleTextItem * mLabel;
};

#endif // GRAPHICSVERTEX_H

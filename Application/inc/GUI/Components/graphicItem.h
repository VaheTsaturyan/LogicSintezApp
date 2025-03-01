#pragma once



#include <QGraphicsItem>
#include <QObject>
#include <QPointF>
#include <QPainter>


namespace gui{

class ScalableGraphicsItem : public QObject, public QGraphicsItem
{
Q_OBJECT
Q_INTERFACES(QGraphicsItem)

public:
    ScalableGraphicsItem(QGraphicsItem *parent = nullptr);
        
    // Implement these pure virtual methods from QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    
public slots:
    void scaleUp();
    void scaleDown();
    void setCustomScale(qreal scale);

    signals:
    void scaleChanged(qreal scale);
    
private:
    qreal m_scale;
    QPointF m_lastMousePos;
    bool m_isDragging;

};


}//namespace gui

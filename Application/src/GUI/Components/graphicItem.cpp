#include "../../../inc/GUI/Components/graphicItem.h"
#include <QGraphicsSceneMouseEvent>

namespace gui
{



ScalableGraphicsItem::ScalableGraphicsItem(QGraphicsItem *parent)
    : QGraphicsItem(parent), m_scale(1.0), m_isDragging(false)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    setAcceptHoverEvents(true);
}

QRectF ScalableGraphicsItem::boundingRect() const
{
    // This should be customized for your specific item
    return QRectF(-50, -50, 100, 100);
}

void ScalableGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // This should be customized for your specific item
    painter->drawRect(boundingRect());
}

void ScalableGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_lastMousePos = event->pos();
        m_isDragging = true;
    }
    QGraphicsItem::mousePressEvent(event);
}

void ScalableGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_isDragging) {
        // Move the item based on mouse movement
        QPointF delta = event->pos() - m_lastMousePos;
        moveBy(delta.x(), delta.y());
        m_lastMousePos = event->pos();
    }
    else {
        QGraphicsItem::mouseMoveEvent(event);
    }
}

void ScalableGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_isDragging = false;
    }
    QGraphicsItem::mouseReleaseEvent(event);
}

QVariant ScalableGraphicsItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemScaleChange) {
        // Can add constraints here if needed
    }
    return QGraphicsItem::itemChange(change, value);
}

void ScalableGraphicsItem::scaleUp()
{
    // Increase scale
    m_scale *= 1.2;
    setScale(m_scale);
    emit scaleChanged(m_scale);
}

void ScalableGraphicsItem::scaleDown()
{
    // Decrease scale
    m_scale *= 0.8;
    setScale(m_scale);
    emit scaleChanged(m_scale);
}

void ScalableGraphicsItem::setCustomScale(qreal scale)
{
    if (scale > 0) {
        m_scale = scale;
        setScale(m_scale);
        emit scaleChanged(m_scale);
    }
}


}//namespace gui
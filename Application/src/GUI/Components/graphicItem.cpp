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


//////////////////////////////////////////////////////////////////////////////////////////////////
///And Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
AndGraphicsItem::AndGraphicsItem(QGraphicsItem *parent)
    : QGraphicsItem(parent), m_scale(1.0), m_isDragging(false)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    setAcceptHoverEvents(true);
}

QRectF AndGraphicsItem::boundingRect() const
{
    // This should be customized for your specific item
    return QRectF(-50, -50, 100, 100);
}

void AndGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // This should be customized for your specific item
    //painter->drawRect(boundingRect());
    painter->drawImage(boundingRect(), QImage("/home/vts/repos/LogicSintesApp/Resources/LogicGates/and.png"));
}

void AndGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_lastMousePos = event->pos();
        m_isDragging = true;
    }
    QGraphicsItem::mousePressEvent(event);
}

void AndGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

void AndGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_isDragging = false;
    }
    QGraphicsItem::mouseReleaseEvent(event);
}

QVariant AndGraphicsItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemScaleChange) {
        // Can add constraints here if needed
    }
    return QGraphicsItem::itemChange(change, value);
}

void AndGraphicsItem::scaleUp()
{
    // Increase scale
    m_scale *= 1.2;
    setScale(m_scale);
    emit scaleChanged(m_scale);
}

void AndGraphicsItem::scaleDown()
{
    // Decrease scale
    m_scale *= 0.8;
    setScale(m_scale);
    emit scaleChanged(m_scale);
}

void AndGraphicsItem::setCustomScale(qreal scale)
{
    if (scale > 0) {
        m_scale = scale;
        setScale(m_scale);
        emit scaleChanged(m_scale);
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////
///Or Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
OrGraphicsItem::OrGraphicsItem(QGraphicsItem *parent)
    : QGraphicsItem(parent), m_scale(1.0), m_isDragging(false)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    setAcceptHoverEvents(true);
}

QRectF OrGraphicsItem::boundingRect() const
{
    // This should be customized for your specific item
    return QRectF(-50, -50, 100, 100);
}

void OrGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // This should be customized for your specific item
    //painter->drawRect(boundingRect());
    painter->drawImage(boundingRect(), QImage("/home/vts/repos/LogicSintesApp/Resources/LogicGates/or.png"));
}

void OrGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_lastMousePos = event->pos();
        m_isDragging = true;
    }
    QGraphicsItem::mousePressEvent(event);
}

void OrGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

void OrGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_isDragging = false;
    }
    QGraphicsItem::mouseReleaseEvent(event);
}

QVariant OrGraphicsItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemScaleChange) {
        // Can add constraints here if needed
    }
    return QGraphicsItem::itemChange(change, value);
}

void OrGraphicsItem::scaleUp()
{
    // Increase scale
    m_scale *= 1.2;
    setScale(m_scale);
    emit scaleChanged(m_scale);
}

void OrGraphicsItem::scaleDown()
{
    // Decrease scale
    m_scale *= 0.8;
    setScale(m_scale);
    emit scaleChanged(m_scale);
}

void OrGraphicsItem::setCustomScale(qreal scale)
{
    if (scale > 0) {
        m_scale = scale;
        setScale(m_scale);
        emit scaleChanged(m_scale);
    }
}





//////////////////////////////////////////////////////////////////////////////////////////////////
///Nand Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
NandGraphicsItem::NandGraphicsItem(QGraphicsItem *parent)
    : QGraphicsItem(parent), m_scale(1.0), m_isDragging(false)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    setAcceptHoverEvents(true);
}

QRectF NandGraphicsItem::boundingRect() const
{
    // This should be customized for your specific item
    return QRectF(-50, -50, 100, 100);
}

void NandGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // This should be customized for your specific item
    //painter->drawRect(boundingRect());
    painter->drawImage(boundingRect(), QImage("/home/vts/repos/LogicSintesApp/Resources/LogicGates/nand.png"));
}

void NandGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_lastMousePos = event->pos();
        m_isDragging = true;
    }
    QGraphicsItem::mousePressEvent(event);
}

void NandGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

void NandGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_isDragging = false;
    }
    QGraphicsItem::mouseReleaseEvent(event);
}

QVariant NandGraphicsItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemScaleChange) {
        // Can add constraints here if needed
    }
    return QGraphicsItem::itemChange(change, value);
}

void NandGraphicsItem::scaleUp()
{
    // Increase scale
    m_scale *= 1.2;
    setScale(m_scale);
    emit scaleChanged(m_scale);
}

void NandGraphicsItem::scaleDown()
{
    // Decrease scale
    m_scale *= 0.8;
    setScale(m_scale);
    emit scaleChanged(m_scale);
}

void NandGraphicsItem::setCustomScale(qreal scale)
{
    if (scale > 0) {
        m_scale = scale;
        setScale(m_scale);
        emit scaleChanged(m_scale);
    }
}




//////////////////////////////////////////////////////////////////////////////////////////////////
///Nor Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
NorGraphicsItem::NorGraphicsItem(QGraphicsItem *parent)
    : QGraphicsItem(parent), m_scale(1.0), m_isDragging(false)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    setAcceptHoverEvents(true);
}

QRectF NorGraphicsItem::boundingRect() const
{
    // This should be customized for your specific item
    return QRectF(-50, -50, 100, 100);
}

void NorGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // This should be customized for your specific item
    //painter->drawRect(boundingRect());
    painter->drawImage(boundingRect(), QImage("/home/vts/repos/LogicSintesApp/Resources/LogicGates/nor.png"));
}

void NorGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_lastMousePos = event->pos();
        m_isDragging = true;
    }
    QGraphicsItem::mousePressEvent(event);
}

void NorGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

void NorGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_isDragging = false;
    }
    QGraphicsItem::mouseReleaseEvent(event);
}

QVariant NorGraphicsItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemScaleChange) {
        // Can add constraints here if needed
    }
    return QGraphicsItem::itemChange(change, value);
}

void NorGraphicsItem::scaleUp()
{
    // Increase scale
    m_scale *= 1.2;
    setScale(m_scale);
    emit scaleChanged(m_scale);
}

void NorGraphicsItem::scaleDown()
{
    // Decrease scale
    m_scale *= 0.8;
    setScale(m_scale);
    emit scaleChanged(m_scale);
}

void NorGraphicsItem::setCustomScale(qreal scale)
{
    if (scale > 0) {
        m_scale = scale;
        setScale(m_scale);
        emit scaleChanged(m_scale);
    }
}



//////////////////////////////////////////////////////////////////////////////////////////////////
///Not Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
NotGraphicsItem::NotGraphicsItem(QGraphicsItem *parent)
    : QGraphicsItem(parent), m_scale(1.0), m_isDragging(false)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    setAcceptHoverEvents(true);
}

QRectF NotGraphicsItem::boundingRect() const
{
    // This should be customized for your specific item
    return QRectF(-50, -50, 100, 100);
}

void NotGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // This should be customized for your specific item
    //painter->drawRect(boundingRect());
    painter->drawImage(boundingRect(), QImage("/home/vts/repos/LogicSintesApp/Resources/LogicGates/not.png"));
}

void NotGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_lastMousePos = event->pos();
        m_isDragging = true;
    }
    QGraphicsItem::mousePressEvent(event);
}

void NotGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

void NotGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_isDragging = false;
    }
    QGraphicsItem::mouseReleaseEvent(event);
}

QVariant NotGraphicsItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemScaleChange) {
        // Can add constraints here if needed
    }
    return QGraphicsItem::itemChange(change, value);
}

void NotGraphicsItem::scaleUp()
{
    // Increase scale
    m_scale *= 1.2;
    setScale(m_scale);
    emit scaleChanged(m_scale);
}

void NotGraphicsItem::scaleDown()
{
    // Decrease scale
    m_scale *= 0.8;
    setScale(m_scale);
    emit scaleChanged(m_scale);
}

void NotGraphicsItem::setCustomScale(qreal scale)
{
    if (scale > 0) {
        m_scale = scale;
        setScale(m_scale);
        emit scaleChanged(m_scale);
    }
}





}//namespace gui
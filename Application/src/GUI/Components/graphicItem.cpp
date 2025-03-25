#include "../../../inc/GUI/Components/graphicItem.h"
#include <QGraphicsSceneMouseEvent>

namespace gui
{



AGraphicsItem::AGraphicsItem(QGraphicsItem *parent)
    : QGraphicsItem(parent), m_scale(1.0), m_isDragging(false)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    setAcceptHoverEvents(true);
}

QRectF AGraphicsItem::boundingRect() const
{
    // This should be customized for your specific item
    return QRectF(-50, -50, 50, 50);
}

void AGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // This should be customized for your specific item
    painter->drawRect(boundingRect());
}

void AGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_lastMousePos = event->pos();
        m_isDragging = true;
    }
    QGraphicsItem::mousePressEvent(event);
}

void AGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

void AGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_isDragging = false;
    }
    QGraphicsItem::mouseReleaseEvent(event);
}

QVariant AGraphicsItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemScaleChange) {
        // Can add constraints here if needed
    }
    return QGraphicsItem::itemChange(change, value);
}

void AGraphicsItem::scaleUp()
{
    // Increase scale
    m_scale *= 1.2;
    setScale(m_scale);
    emit scaleChanged(m_scale);
}

void AGraphicsItem::scaleDown()
{
    // Decrease scale
    m_scale *= 0.8;
    setScale(m_scale);
    emit scaleChanged(m_scale);
}

void AGraphicsItem::setCustomScale(qreal scale)
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
    : AGraphicsItem(parent)
{
}


void AndGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // This should be customized for your specific item
    //painter->drawRect(boundingRect());
    painter->drawImage(boundingRect(), QImage("/home/vts/repos/LogicSintesApp/Resources/LogicGates/and.png"));
    QRectF rect = boundingRect();
    painter->setPen(QPen(Qt::blue));
    painter->drawPoint(rect.y()+rect.height(), rect.x()+rect.width()/2);
    painter->setPen(QPen(Qt::red));
    painter->drawPoint(rect.y(), rect.x()+3*rect.width()/4);
    painter->drawPoint(rect.y(), rect.x()+rect.width()/4);

}



//////////////////////////////////////////////////////////////////////////////////////////////////
///Or Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
OrGraphicsItem::OrGraphicsItem(QGraphicsItem *parent)
    : AGraphicsItem(parent)
{

}


void OrGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // This should be customized for your specific item
    //painter->drawRect(boundingRect());
    painter->drawImage(boundingRect(), QImage("/home/vts/repos/LogicSintesApp/Resources/LogicGates/or.png"));
}





//////////////////////////////////////////////////////////////////////////////////////////////////
///Nand Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
NandGraphicsItem::NandGraphicsItem(QGraphicsItem *parent)
    : AGraphicsItem(parent)
{
    
}



void NandGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // This should be customized for your specific item
    //painter->drawRect(boundingRect());
    painter->drawImage(boundingRect(), QImage("/home/vts/repos/LogicSintesApp/Resources/LogicGates/nand.png"));
}




//////////////////////////////////////////////////////////////////////////////////////////////////
///Nor Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
NorGraphicsItem::NorGraphicsItem(QGraphicsItem *parent)
    : AGraphicsItem(parent)
{    
}


void NorGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // This should be customized for your specific item
    //painter->drawRect(boundingRect());
    painter->drawImage(boundingRect(), QImage("/home/vts/repos/LogicSintesApp/Resources/LogicGates/nor.png"));
}



//////////////////////////////////////////////////////////////////////////////////////////////////
///Not Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
NotGraphicsItem::NotGraphicsItem(QGraphicsItem *parent)
    : AGraphicsItem(parent)
{
    
}


void NotGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // This should be customized for your specific item
    //painter->drawRect(boundingRect());
    painter->drawImage(boundingRect(), QImage("/home/vts/repos/LogicSintesApp/Resources/LogicGates/not.png"));
}



}//namespace gui
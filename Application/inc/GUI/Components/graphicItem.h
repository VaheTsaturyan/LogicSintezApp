#pragma once



#include <QGraphicsItem>
#include <QObject>
#include <QPointF>
#include <QPainter>
#include <QPixmap>

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


//////////////////////////////////////////////////////////////////////////////////////////////////
///And Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
class AndGraphicsItem : public QObject, public QGraphicsItem
{
Q_OBJECT
Q_INTERFACES(QGraphicsItem)

public:
    AndGraphicsItem(QGraphicsItem *parent = nullptr);
        
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


//////////////////////////////////////////////////////////////////////////////////////////////////
///Or Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
class OrGraphicsItem : public QObject, public QGraphicsItem
{
Q_OBJECT
Q_INTERFACES(QGraphicsItem)

public:
    OrGraphicsItem(QGraphicsItem *parent = nullptr);
        
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




//////////////////////////////////////////////////////////////////////////////////////////////////
//Nand Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
class NandGraphicsItem : public QObject, public QGraphicsItem
{
Q_OBJECT
Q_INTERFACES(QGraphicsItem)

public:
    NandGraphicsItem(QGraphicsItem *parent = nullptr);
        
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




//////////////////////////////////////////////////////////////////////////////////////////////////
///Nor Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
class NorGraphicsItem : public QObject, public QGraphicsItem
{
Q_OBJECT
Q_INTERFACES(QGraphicsItem)

public:
    NorGraphicsItem(QGraphicsItem *parent = nullptr);
        
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




//////////////////////////////////////////////////////////////////////////////////////////////////
///Not Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
class NotGraphicsItem : public QObject, public QGraphicsItem
{
Q_OBJECT
Q_INTERFACES(QGraphicsItem)

public:
    NotGraphicsItem(QGraphicsItem *parent = nullptr);
        
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

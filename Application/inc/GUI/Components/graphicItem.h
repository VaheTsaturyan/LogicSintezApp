#pragma once



#include <QGraphicsItem>
#include <QObject>
#include <QPointF>
#include <QPainter>
#include <QPixmap>

namespace gui{

class AGraphicsItem : public QObject, public QGraphicsItem
{
Q_OBJECT
Q_INTERFACES(QGraphicsItem)

public:
    AGraphicsItem(QGraphicsItem *parent = nullptr);
        
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
class AndGraphicsItem : public AGraphicsItem
{
Q_OBJECT
Q_INTERFACES(QGraphicsItem)

public:
    AndGraphicsItem(QGraphicsItem *parent = nullptr);
        
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


//////////////////////////////////////////////////////////////////////////////////////////////////
///Or Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
class OrGraphicsItem : public AGraphicsItem
{
Q_OBJECT
Q_INTERFACES(QGraphicsItem)
public:
    OrGraphicsItem(QGraphicsItem *parent = nullptr);
        
    // Implement these pure virtual methods from QGraphicsItem
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};




//////////////////////////////////////////////////////////////////////////////////////////////////
//Nand Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
class NandGraphicsItem : public AGraphicsItem
{
Q_OBJECT
Q_INTERFACES(QGraphicsItem)
public:
    NandGraphicsItem(QGraphicsItem *parent = nullptr);
        
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};




//////////////////////////////////////////////////////////////////////////////////////////////////
///Nor Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
class NorGraphicsItem : public AGraphicsItem
{
Q_OBJECT
Q_INTERFACES(QGraphicsItem)

public:
    NorGraphicsItem(QGraphicsItem *parent = nullptr);
    
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};




//////////////////////////////////////////////////////////////////////////////////////////////////
///Not Graphic Ithem
/////////////////////////////////////////////////////////////////////////////////////////////////
class NotGraphicsItem : public AGraphicsItem
{
Q_OBJECT
Q_INTERFACES(QGraphicsItem)

public:
    NotGraphicsItem(QGraphicsItem *parent = nullptr);
        
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};


}//namespace gui

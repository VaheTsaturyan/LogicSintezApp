// graphicScen.h
#pragma once
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

#include <unordered_map>
#include <string>
#include <vector>

#include "graphicItem.h"

namespace gui
{

class ConnectionLine : public QObject, public QGraphicsLineItem
{
    Q_OBJECT
public:
    explicit ConnectionLine( QGraphicsItem *parent = nullptr );
    ~ConnectionLine ();
    
    // Store source and target IDs
    void setSourceItem( AGraphicsItem* source ) { m_sourceItem = source; }
    void setTargetItem( AGraphicsItem* target ) { m_targetItem = target; }
    
    AGraphicsItem* sourceItem () const { return m_sourceItem; }
    AGraphicsItem* targetItem () const { return m_targetItem; }
    
    // Method to finalize creation and emit the signal
    void finishCreation();
    
    // Override mouse events to handle the endpoint selection and dragging
    void mousePressEvent( QGraphicsSceneMouseEvent *event) override;
    void mouseDoubleClickEvent( QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent( QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent( QGraphicsSceneMouseEvent *event ) override;
    
    // Custom paint method to draw endpoint circles
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr ) override;
    
signals:
    // Signal emitted when the line is created or endpoints are moved
    void lineCreated( const QPointF &sourcePoint, const QPointF &targetPoint );
    
private:
    // Enum to track which endpoint is being modified
    enum EndpointType { 
        Source, 
        Target, 
        None 
    };

private:
    // Helper method to check if position is on an endpoint
    EndpointType hitTestEndpoint(const QPointF &pos);
    // Helper method to delete the line
    void deleteLine();
    
private:
    // Constants
    AGraphicsItem* m_sourceItem;
    AGraphicsItem* m_targetItem;
    bool m_isDragging;
    EndpointType m_currentEndpoint;
    const qreal ENDPOINT_RADIUS = 9.0 / 2.0; // 9 pixels thickness means radius of 4.5
    const qreal ENDPOINT_HITAREA = 10.0;     // Slightly larger hit area for easier selection

};


//////////////////////////////////////////////////////////////////////////////////
///Custom Graphic scen
/////////////////////////////////////////////////////////////////////////////////
class CustomGraphicsScene : public QGraphicsScene
{
Q_OBJECT
public:
    CustomGraphicsScene(QObject *parent = nullptr);
    QList<AGraphicsItem*> selectedScalableItems() const;


public slots:
    AGraphicsItem* addScalableItem(const QString &gateType);
    void scaleUpSelected();
    void scaleDownSelected();

signals:
    // New signals for selections and connections
    void itemsSelected(QVector<qint64> itemIds);
    void itemsConnected(qint64 sourceId, qint64 targetId);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

private:
    void initGateMap();
    AGraphicsItem* itemAtPosition(const QPointF& pos);

private:
    std::unordered_map<std::string, AGraphicsItem*> gateMap;
    
    // For line drawing with right button
    bool m_rightButtonDown;
    QPointF m_lineStartPos;
    ConnectionLine* m_currentLine;
    AGraphicsItem* m_sourceItem;
};

} // namespace gui

/*#pragma once
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>

#include <unordered_map>
#include <string>

#include "graphicItem.h"

namespace gui
{
    
    
class CustomGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    CustomGraphicsScene(QObject *parent = nullptr);
    QList<AGraphicsItem*> selectedScalableItems() const;

public slots:
    AGraphicsItem* addScalableItem(const QString &gateType);
    //AGraphicsItem* addScalableItemAt(const QPointF &pos);
    //AndGraphicsItem* addScalableItemAt(const QPointF &pos);
    //AndGraphicsItem* addScalableItem();
    void scaleUpSelected();
    void scaleDownSelected();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

private:
    void initGateMap();

private:
    std::unordered_map<std::string, AGraphicsItem*> gateMap;

};

} // namespace gui
*/
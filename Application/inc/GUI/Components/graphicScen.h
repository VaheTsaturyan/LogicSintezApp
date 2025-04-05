#pragma once
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

#include <unordered_map>
#include <string>
#include <vector>

#include "graphicItem.h"

namespace gui
{

// Forward declaration
class SelectionRect;

class ConnectionLine : public QObject, public QGraphicsLineItem
{
    Q_OBJECT
public:
    explicit ConnectionLine(QGraphicsItem *parent = nullptr);
    ~ConnectionLine();
    
    // Store source and target IDs
    void setSourceItem(AGraphicsItem* source) { m_sourceItem = source; }
    void setTargetItem(AGraphicsItem* target) { m_targetItem = target; }
    
    AGraphicsItem* sourceItem() const { return m_sourceItem; }
    AGraphicsItem* targetItem() const { return m_targetItem; }
    
    // Method to finalize creation and emit the signal
    void finishCreation();
    
    // Override mouse events to handle the endpoint selection and dragging
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    
    // Custom paint method to draw endpoint circles
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    
signals:
    // Signal emitted when the line is created or endpoints are moved
    void lineCreated(const QPointF &sourcePoint, const QPointF &targetPoint);
    
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

// Selection Rectangle class to draw squares around selected items
class SelectionRect : public QGraphicsRectItem
{
public:
    explicit SelectionRect(QGraphicsItem* targetItem = nullptr, QGraphicsItem* parent = nullptr);
    
    void updatePosition();
    void setTargetItem(QGraphicsItem* item);
    QGraphicsItem* targetItem() const { return m_targetItem; }
    
    // Custom paint method to draw selection handles
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
    
private:
    QGraphicsItem* m_targetItem;
    const qreal HANDLE_SIZE = 8.0; // Size of selection handles
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
    
    // New method to get all selectable items (including ConnectionLines)
    QList<QGraphicsItem*> allSelectedItems() const;

public slots:
    AGraphicsItem* addScalableItem(const QString &gateType);
    void scaleUpSelected();
    void scaleDownSelected();

signals:
    // Signals for selections and connections
    void itemsSelected(QVector<qint64> itemIds);
    void itemsConnected(qint64 sourceId, qint64 targetId);
    
    // New signal that passes all selected elements (not just AGraphicsItems)
    void allItemsSelected(QList<QGraphicsItem*> items);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

private slots:
    // New slot to handle selection changes
    void handleSelectionChanged();
    
    // Methods to update selection rectangles
    void updateSelectionRects();
    void clearSelectionRects();

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
    
    // For selection rectangles
    QList<SelectionRect*> m_selectionRects;
};

} // namespace gui
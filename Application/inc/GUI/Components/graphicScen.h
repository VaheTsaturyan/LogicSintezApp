#pragma once
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
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
    AGraphicsItem* addScalableItem();
    AGraphicsItem* addScalableItemAt(const QPointF &pos);
    //AndGraphicsItem* addScalableItemAt(const QPointF &pos);
    //AndGraphicsItem* addScalableItem();
    void scaleUpSelected();
    void scaleDownSelected();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;
};

} // namespace gui

#include "../../../inc/GUI/Components/graphicScen.h"

namespace gui{


CustomGraphicsScene::CustomGraphicsScene(QObject *parent)
    : QGraphicsScene(parent)
{
}

QList<ScalableGraphicsItem*> CustomGraphicsScene::selectedScalableItems() const
{
    QList<ScalableGraphicsItem*> items;
    for (QGraphicsItem *item : selectedItems()) {
        ScalableGraphicsItem *scalableItem = qgraphicsitem_cast<ScalableGraphicsItem*>(item);
        if (scalableItem)
            items.append(scalableItem);
    }
    return items;
}

ScalableGraphicsItem* CustomGraphicsScene::addScalableItem()
{
    ScalableGraphicsItem *item = new ScalableGraphicsItem();
    addItem(item);
    return item;
}

ScalableGraphicsItem* CustomGraphicsScene::addScalableItemAt(const QPointF &pos)
{
    ScalableGraphicsItem *item = addScalableItem();
    item->setPos(pos);
    return item;
}

void CustomGraphicsScene::scaleUpSelected()
{
    for (ScalableGraphicsItem *item : selectedScalableItems())
        item->scaleUp();
}

void CustomGraphicsScene::scaleDownSelected()
{
    for (ScalableGraphicsItem *item : selectedScalableItems())
        item->scaleDown();
}

void CustomGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
}

void CustomGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
}

void CustomGraphicsScene::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // You can implement wheel scaling here if desired
    QGraphicsScene::wheelEvent(event);
}




}//namespace gui
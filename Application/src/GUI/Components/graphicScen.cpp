#include "../../../inc/GUI/Components/graphicScen.h"

namespace gui{


    CustomGraphicsScene::CustomGraphicsScene(QObject *parent)
    : QGraphicsScene(parent)
{
}

QList<AGraphicsItem*> CustomGraphicsScene::selectedScalableItems() const
{
    QList<AGraphicsItem*> items;
    for (QGraphicsItem *item : selectedItems()) {
        AGraphicsItem *scalableItem = qgraphicsitem_cast<AGraphicsItem*>(item);
        if (scalableItem)
            items.append(scalableItem);
    }
    return items;
}
/*

AndGraphicsItem* AGraphicsItem::addScalableItem()
{
    AndGraphicsItem* item = new AndGraphicsItem();
    addItem(item);
    return item;
}

AndGraphicsItem* AGraphicsItem::addScalableItemAt(const QPointF &pos)
{
    AndGraphicsItem *item = addScalableItem();
    item->setPos(pos);
    return item;
}
*/



/////////////////////////costo cod
AGraphicsItem* CustomGraphicsScene::addScalableItem()
{
    AGraphicsItem *item = new AndGraphicsItem();
    addItem(item);
    return item;
}

AGraphicsItem* CustomGraphicsScene::addScalableItemAt(const QPointF &pos)
{
    AGraphicsItem *item = addScalableItem();
    item->setPos(pos);
    return item;
}
/////////////////////////costo cod

void CustomGraphicsScene::scaleUpSelected()
{
    for (AGraphicsItem *item : selectedScalableItems())
        item->scaleUp();
}

void CustomGraphicsScene::scaleDownSelected()
{
    for (AGraphicsItem *item : selectedScalableItems())
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
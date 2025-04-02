// graphicScen.cpp
#include "../../../inc/GUI/Components/graphicScen.h"
#include "../../application.h"
namespace gui {

ConnectionLine::ConnectionLine(QGraphicsItem *parent) 
    : QGraphicsLineItem(parent),
      m_sourceItem(nullptr),
      m_targetItem(nullptr),
      m_isDragging(false),
      m_currentEndpoint(None)
{
    setPen( QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin) );
    setFlag( QGraphicsItem::ItemIsSelectable, true );
    setAcceptHoverEvents( true );
    
    connect( this, &ConnectionLine::lineCreated, MyApplication::instance(), &MyApplication::lineAndGraphicSchenBridg );
}

ConnectionLine::~ConnectionLine()
{
    // No special cleanup needed
}

void ConnectionLine::finishCreation()
{
    // Emit signal with current endpoint coordinates
    emit lineCreated(line().p1(), line().p2());
}

void ConnectionLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // First draw the line using the parent implementation
    QGraphicsLineItem::paint(painter, option, widget);
    
    // Now draw the endpoint circles
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(Qt::white));
    
    // Draw source endpoint circle
    painter->drawEllipse(line().p1(), ENDPOINT_RADIUS, ENDPOINT_RADIUS);
    
    // Draw target endpoint circle
    painter->drawEllipse(line().p2(), ENDPOINT_RADIUS, ENDPOINT_RADIUS);
}

ConnectionLine::EndpointType ConnectionLine::hitTestEndpoint(const QPointF &pos)
{
    QPointF sourcePoint = line().p1();
    QPointF targetPoint = line().p2();
    
    // Calculate distance to endpoints
    qreal distToSource = QLineF( pos, sourcePoint ).length();
    qreal distToTarget = QLineF( pos, targetPoint ).length();
    
    // Check if click is within the hit area of either endpoint
    if ( distToSource < ENDPOINT_HITAREA ) {
        return Source;
    } else if ( distToTarget < ENDPOINT_HITAREA ) {
        return Target;
    }
    
    return None;
}

void ConnectionLine::deleteLine()
{
    scene ()->removeItem( this );
    deleteLater ();
}

void ConnectionLine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button () == Qt::LeftButton) {
        // Check if click is on an endpoint
        m_currentEndpoint = hitTestEndpoint( event->pos() );
        
        if ( m_currentEndpoint != None ) {
            m_isDragging = true;
            event->accept ();
            return;
        }
    } else if ( event->button() == Qt::RightButton ) {
        // Right-click on line - delete it
        deleteLine ();
        event->accept ();
        return;
    }
    
    // Otherwise, pass the event to parent
    QGraphicsLineItem::mousePressEvent( event );
}

void ConnectionLine::mouseDoubleClickEvent( QGraphicsSceneMouseEvent *event )
{
    if ( event->button() == Qt::LeftButton ) {
        // Left double-click - delete the line
        deleteLine ();
        event->accept ();
        return;
    }
    
    QGraphicsLineItem::mouseDoubleClickEvent( event );
}

void ConnectionLine::mouseMoveEvent( QGraphicsSceneMouseEvent *event )
{
    if ( m_isDragging && m_currentEndpoint != None ) {
        // Get current line
        QLineF currentLine = line ();
        
        // Update the appropriate endpoint
        if ( m_currentEndpoint == Source ) {
            currentLine.setP1( event->pos() );
        } else if ( m_currentEndpoint == Target ) {
            currentLine.setP2( event->pos() );
        }
        
        // Set the new line
        setLine( currentLine );
        event->accept ();
    } else {
        QGraphicsLineItem::mouseMoveEvent( event );
    }
}

void ConnectionLine::mouseReleaseEvent( QGraphicsSceneMouseEvent *event )
{
    if ( m_isDragging && event->button() == Qt::LeftButton ) {
        m_isDragging = false;
        
        // Emit signal with updated endpoint coordinates
        emit lineCreated( line().p1(), line().p2() );
        
        event->accept ();
        
        // Reset current endpoint after handling
        m_currentEndpoint = None;
    } else {
        QGraphicsLineItem::mouseReleaseEvent( event );
    }
}


//////////////////////////////////////////////////////////////////////////////////
///Custom Graphic scen
/////////////////////////////////////////////////////////////////////////////////
CustomGraphicsScene::CustomGraphicsScene( QObject *parent )
    : QGraphicsScene( parent ),
      m_rightButtonDown( false ),
      m_currentLine( nullptr ),
      m_sourceItem( nullptr )
{
    initGateMap ();
}

QList<AGraphicsItem*> CustomGraphicsScene::selectedScalableItems () const
{
    QList<AGraphicsItem*> items;
    for ( QGraphicsItem *item : selectedItems() ) {
        AGraphicsItem *scalableItem = qgraphicsitem_cast<AGraphicsItem*>( item );
        if ( scalableItem )
            items.append( scalableItem );
    }
    return items;
}

AGraphicsItem* CustomGraphicsScene::addScalableItem( const QString &gateType )
{
    auto findResult = gateMap.find( gateType.toStdString() );
    AGraphicsItem *item;
    
    if( findResult == gateMap.end() ){
        item = new AGraphicsItem ();
    } else {
        item = findResult->second->clone ();
    }

    addItem( item );
    return item;
}

void CustomGraphicsScene::scaleUpSelected ()
{
    for ( AGraphicsItem *item : selectedScalableItems() )
        item->scaleUp ();
}

void CustomGraphicsScene::scaleDownSelected ()
{
    for ( AGraphicsItem *item : selectedScalableItems() )
        item->scaleDown ();
}

void CustomGraphicsScene::mousePressEvent( QGraphicsSceneMouseEvent *event )
{
    if ( event->button() == Qt::LeftButton ) {
        // Let QGraphicsScene handle selection through rubber band
        QGraphicsScene::mousePressEvent( event );
    }
    else if ( event->button() == Qt::RightButton ) {
        // Start drawing a line
        m_rightButtonDown = true;
        m_lineStartPos = event->scenePos ();
        
        // Create a new line
        m_currentLine = new ConnectionLine ();
        m_currentLine->setLine( m_lineStartPos.x(), m_lineStartPos.y(), 
                                m_lineStartPos.x(), m_lineStartPos.y() );
        addItem( m_currentLine );
        
        // Check if there's an item at this position
        m_sourceItem = itemAtPosition( m_lineStartPos );
        if ( m_sourceItem ) {
            m_currentLine->setSourceItem( m_sourceItem );
        }
        
        // Don't let QGraphicsScene handle this event
        event->accept ();
    }
    else {
        QGraphicsScene::mousePressEvent( event );
    }
}

void CustomGraphicsScene::mouseMoveEvent( QGraphicsSceneMouseEvent *event )
{
    if ( m_rightButtonDown && m_currentLine ) {
        // Update the end point of the line
        m_currentLine->setLine( m_lineStartPos.x(), m_lineStartPos.y(),
                                event->scenePos().x(), event->scenePos().y() );
        event->accept ();
    }
    else {
        QGraphicsScene::mouseMoveEvent( event );
    }
}

void CustomGraphicsScene::mouseReleaseEvent( QGraphicsSceneMouseEvent *event )
{
    if ( event->button() == Qt::LeftButton ) {
        // Get all selected items after rubber band selection
        QList<AGraphicsItem*> selected = selectedScalableItems ();
        
        if ( !selected.isEmpty() ) {
            // Create a vector of item IDs
            QVector<qint64> selectedIds;
            for ( AGraphicsItem* item : selected ) {
                selectedIds.append( item->id() );
            }
            
            // Emit the signal with all selected item IDs
            emit itemsSelected( selectedIds );
        }
        
        QGraphicsScene::mouseReleaseEvent( event );
    }
    else if ( event->button() == Qt::RightButton && m_rightButtonDown ) {
        m_rightButtonDown = false;
        
        // Finalize the line
        QPointF endPos = event->scenePos ();
        m_currentLine->setLine( m_lineStartPos.x(), m_lineStartPos.y(),
                                endPos.x(), endPos.y() );
        
        // Check if there's an item at the end position
        AGraphicsItem* targetItem = itemAtPosition( endPos );
        
        if ( m_sourceItem && targetItem && m_sourceItem != targetItem ) {
            // We have a valid connection between two items
            m_currentLine->setTargetItem( targetItem );
            
            // Emit signal for the connection
            emit itemsConnected( m_sourceItem->id(), targetItem->id() );
        }
        else if ( !m_sourceItem || !targetItem ) {
            // No valid connection, just a curve in space
            // You could style this differently if desired
        }
        
        // Reset tracking variables
        m_sourceItem = nullptr;
        m_currentLine = nullptr;
        
        event->accept();
    }
    else {
        QGraphicsScene::mouseReleaseEvent(event);
    }
}

void CustomGraphicsScene::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // You can implement wheel scaling here if desired
    QGraphicsScene::wheelEvent(event);
}

void CustomGraphicsScene::initGateMap()
{
    gateMap.emplace( "AND",  new AndGraphicsItem() );
    gateMap.emplace( "OR",   new OrGraphicsItem()  );
    gateMap.emplace( "NAND", new NandGraphicsItem());
    gateMap.emplace( "NOR",  new NorGraphicsItem() );
    gateMap.emplace( "NOT",  new NotGraphicsItem() );
    gateMap.emplace( "XOR",  new XorGraphicsItem() );
    gateMap.emplace( "XNOR", new XnorGraphicsItem());
}

AGraphicsItem* CustomGraphicsScene::itemAtPosition(const QPointF& pos)
{
    QGraphicsItem* item = itemAt(pos, QTransform());
    return qgraphicsitem_cast<AGraphicsItem*>(item);
}



}//namespace gui

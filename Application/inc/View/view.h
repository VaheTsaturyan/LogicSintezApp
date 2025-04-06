#pragma once
#include "../application.h"

#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <string>
#include <QObject>
#include <list>

#include "../GUI/Components/graphicItem.h"
namespace std {
template<>
struct hash<doc::Gate>{
    std::size_t operator()(const doc::Gate& gate) const noexcept
    {
        unsigned int inputCaount = gate.getInputCaount();
        return hash<unsigned int>( inputCaount);
    }
}

}// namespace std


namespace viw
{
    
inline const unsigned int startX = 100;
inline const unsigned int startY = 20;    
inline const unsigned int deltaX = 100;
inline const unsigned int deltaY = 20;
    
class View : public QObject
{
Q_OBJECT
public:
    explicit View(QObject *parent = nullptr);
    void setDoc(std::shared_ptr<doc::Document> doc_);
    void draw();

signals:
    void clearGraphicSchen();
    void drawLine(unsigned int sx, unsigned int sy, unsigned int ex, unsigned int ey);
    void drawGate(unsigned int x, unsigned int y, std::string gateType);

private:
    void sortGates();
    void drawGates();
    void drawLines();

private:
    std::unordered_set<std::shared_ptr<doc::Gate>, std::hash<doc::Gate>> gates_;
    std::list<std::shared_ptr<doc::Gate>> outputGate_;
    std::shared_ptr<doc::Document> doc_;
    unsigned int x_;
    unsigned inr y_;
};


} // namespace viw
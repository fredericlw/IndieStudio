//
// Created by jupi on 28/05/2021.
//

#include "Components/GUI/ListSelectorComp.hpp"
#include "Entity.hpp"
#include "raylib_encap/Math/RectCollider.hpp"
#include "raylib_encap/Input/EMouseInputModule.hpp"

ListSelectorComp::ListSelectorComp(
    const std::vector<std::string> &options, const std::string &label,
    Colors color
)
    : _options(options),
      _prevRect(Vector2D(50, 50), Vector2D::Zero()),
      _nextRect(Vector2D(50, 50), Vector2D::Zero()),
      selIndex(0),
      _Select(""),
      _prevText("<"),
      _nextText(">"),
      _label(label),
      _color(color)
{
}

void ListSelectorComp::init()
{

    Component::init();
    _transform = &entity->getComponent<TransformComp>();
    if (!_transform)
        _transform = &entity->addComponent<TransformComp>();
    _prevRect.y = _transform->position.y - 10;
    _prevRect.x = _transform->position.x - 140;
    _nextRect.y = _transform->position.y - 10;
    _nextRect.x = _transform->position.x + 90;
}

void ListSelectorComp::update()
{
    Component::update();
    bool clicked = false;

    if (RectCollider::CheckMouseInRect(_prevRect)) {
        _prevHover = true;
        if (EMouseInputModule::GetButtonReleased(LeftClick)) {
            selIndex--;
            clicked = true;
        }
    } else
        _prevHover = false;
    if (RectCollider::CheckMouseInRect(_nextRect)) {
        _nextHover = true;
        if (EMouseInputModule::GetButtonReleased(LeftClick)) {
            selIndex++;
            clicked = true;
        }
    } else
        _nextHover = false;
    if (selIndex < 0)
        selIndex = _options.size() - 1;
    else if (selIndex > _options.size() - 1)
        selIndex = 0;
    if (_Select._text != _options[selIndex])
        _Select._text = _options[selIndex];
    if (!clicked)
        return;
    for (auto &fun : _eventFuns)
        fun(_options[selIndex]);
}

void ListSelectorComp::draw()
{
    Component::draw();
    _prevRect.draw(true, true, (_prevHover) ? Green : LightGray,
        (_prevHover) ? Green : Gray);
    _prevText.drawInRectCenter(_prevRect, 30, Black);
    _nextRect.draw(true, true, (_nextHover) ? Green : LightGray,
        (_prevHover) ? Green : Gray);
    _nextText.drawInRectCenter(_nextRect, 30, Black);
    _Select.drawCentered(_transform->position.x, _transform->position.y, 30,
        _color);
    _label.drawCentered(_transform->position.x, _transform->position.y - 65, 40,
        _color);
}

EInputType ListSelectorComp::getSelInputType() const
{
    return (EInputType) selIndex;
}

std::string ListSelectorComp::getSelStr() const
{
    return _options[selIndex];
}

void ListSelectorComp::addEventFun(const std::function<void(std::string)>& fun)
{
    _eventFuns.emplace_back(fun);
}

void ListSelectorComp::set_sel_index(int sel_index)
{
    selIndex = sel_index;
}

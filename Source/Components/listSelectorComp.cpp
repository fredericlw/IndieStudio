//
// Created by jupi on 28/05/2021.
//

#include "Components/GUI/listSelectorComp.hpp"
#include "Entity.hpp"
#include "raylib_encap/Math/RectCollider.hpp"
#include "raylib_encap/Input/EMouseInputModule.hpp"

listSelectorComp::listSelectorComp(const std::vector<std::string> &options, const std::string &label)
: _options(options),
_prevRect(Vector2D(50, 50), Vector2D::Zero()),
_nextRect(Vector2D(50, 50), Vector2D::Zero()),
selIndex(0),
  _Select(""),
  _prevText("<"),
  _nextText(">"),
  _label(label)
{
}

void listSelectorComp::init() {
    Component::init();
    _transform = &entity->getComponent<TransformComp>();
    _prevRect.y = _transform->position.y - 10;
    _prevRect.x = _transform->position.x - 190;
    _nextRect.y = _transform->position.y - 10;
    _nextRect.x = _transform->position.x + 150;

}

void listSelectorComp::update() {
    Component::update();
    if (RectCollider::CheckMouseInRect(_prevRect)) {
        _prevHover = true;
        if (EMouseInputModule::GetButtonReleased(LeftClick))
            selIndex--;
    } else
        _prevHover = false;
    if (RectCollider::CheckMouseInRect(_nextRect)) {
        _nextHover = true;
        if (EMouseInputModule::GetButtonReleased(LeftClick))
            selIndex++;
    } else
        _nextHover = false;
    if (selIndex < 0)
        selIndex = _options.size() - 1;
    else if (selIndex > _options.size() - 1)
        selIndex = 0;
    if (_Select._text != _options[selIndex])
        _Select._text = _options[selIndex];
}

void listSelectorComp::draw() {
    Component::draw();
    _prevRect.draw(true, true, (_prevHover) ? Green : LightGray, (_prevHover) ? Green : Gray);
    _prevText.drawInRectCenter(_prevRect, 40, Black);
    _nextRect.draw(true, true, (_nextHover) ? Green : LightGray, (_prevHover) ? Green : Gray);
    _nextText.drawInRectCenter(_nextRect, 40, Black);
    _Select.drawCentered(_transform->position.x, _transform->position.y, 40, DarkBlue);
    _label.drawCentered(_transform->position.x, _transform->position.y - 65, 50, DarkBlue);
}

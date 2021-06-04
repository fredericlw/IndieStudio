//
// Created by leofa on 04/06/2021.
//

#include "Components/GUI/AnimatedSprite.hpp"
#include "Entity.hpp"
#include "Manager.hpp"

AnimatedSprite::AnimatedSprite(
    const std::string &path, Vector2D nbFrames, bool loop
)
    : _sprite(path),
      _nbFrames(nbFrames),
      _frameSize((float)_sprite.width / nbFrames.x, (float)_sprite.height / nbFrames.y),
      _curPos(Vector2D::Zero()),
      _loop(loop),
      active(true),
      framesCounter(0),
      frameRect(_frameSize, {0, 0})
{
}

void AnimatedSprite::init()
{
    Component::init();
    transform = &entity->getComponent<TransformComp>();
    if (!transform)
        transform = &entity->addComponent<TransformComp>();
    std::cout << "Boom pos : " << transform->position << std::endl;
}

void AnimatedSprite::update()
{
    Component::update();
    framesCounter++;
    if (active) {
        if (framesCounter > 2) {
            currentFrame++;
            if ((float) currentFrame >= _nbFrames.x) {
                currentFrame = 0;
                currentLine++;
                if ((float) currentLine >= _nbFrames.y) {
                    currentLine = 0;
                    if (!_loop) active = false;
                }
            }
            framesCounter = 0;
        }
    }
    frameRect.x = _frameSize.x * (float) currentFrame;
    frameRect.y = _frameSize.y * (float) currentLine;
}

void AnimatedSprite::draw()
{
    Component::draw();
    if (!active) return;
    //2D version
//        _sprite.drawInRect(Vector2D(transform->position.x, transform->position.y),
//            frameRect);
    //3D version
    entity->_mgr.MainCam.Begin3D();
    _sprite.drawBillboardRect(entity->_mgr.MainCam, frameRect,
        transform->position, {7,7}, White);
    entity->_mgr.MainCam.End3D();
}

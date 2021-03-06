//
// Created by leofa on 04/06/2021.
//

#ifndef ANIMATEDSPRITE_HPP
#define ANIMATEDSPRITE_HPP

#include <raylib_encap/ESprite.hpp>
#include <raylib_encap/Math/Vector2D.hpp>
#include <3D/TransformComp.hpp>
#include <raylib_encap/ERect.hpp>
#include "Component.hpp"
class AnimatedSprite : public Component {
public:
    AnimatedSprite(
        const std::string &path, Vector2D nbFrames, bool loop = false
    );
    void init() override;
    void update() override;
    void draw() override;
    ESprite _sprite;
    Vector2D _frameSize;
    Vector2D _nbFrames;
    Vector2D _curPos;
    bool _loop;
    bool active;
    TransformComp *transform;
    int framesCounter = 0;
    int currentFrame = 0;
    int currentLine = 0;
    ERect frameRect;
};

#endif //ANIMATEDSPRITE_HPP

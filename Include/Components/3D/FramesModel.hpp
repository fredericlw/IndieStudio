//
// Created by leofa on 18/06/2021.
//

#ifndef FRAMESMODEL_HPP
#define FRAMESMODEL_HPP

#include "Component.hpp"
#include "../../../Source/Components/EFramesModel.hpp"
#include "TransformComp.hpp"

class FramesModel : public Component {
public:
    explicit FramesModel(EFramesModel &firstModel, EModel &idleModel, Colors color = White);
    void init() override;
    void update() override;
    void draw() override;
    void SetModel(EFramesModel &newModel);
    void SetSpeed(float Speed);
    void rotate(const Vector3D &vec);

    void SetIdle(bool state);
    void SetVisibility(bool state);
private:
    EFramesModel _curModel;
    EModel idleModel;
    TransformComp *transform;
    Colors color;
    bool visible;
    bool _idle;
};

#endif //FRAMESMODEL_HPP

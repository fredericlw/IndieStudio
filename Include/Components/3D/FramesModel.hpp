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
    explicit FramesModel(EFramesModel &firstModel, Colors color = White);
    void init() override;
    void update() override;
    void draw() override;
    void SetModel(EFramesModel &newModel);
    void SetSpeed(float Speed);
private:
    EFramesModel *_curModel;
    TransformComp *transform;
    Colors color;
};

#endif //FRAMESMODEL_HPP

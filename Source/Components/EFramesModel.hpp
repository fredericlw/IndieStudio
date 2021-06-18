//
// Created by leofa on 18/06/2021.
//

#ifndef EFRAMESMODEL_HPP
#define EFRAMESMODEL_HPP

#include <raylib_encap/Math/Vector3D.hpp>
#include <Colors.h>
#include <vector>
#include <boost/filesystem.hpp>
#include <raylib_encap/EModel.hpp>

class EFramesModel {
public:
    explicit EFramesModel(const std::string &folder, const std::string &texturePath, float scale = 1.f, float speed = 1.f);
    void draw(const Vector3D &pos, Colors color = White);
    float scale;
    float speed;
    Model model;
    std::vector<EModel> _frames;
private:
    float timer;
    int frameCounter;
    std::vector<std::string> get_paths_ordered(
        const std::string &dirPath
    );
    int nbFrames;
};

#endif //EFRAMESMODEL_HPP

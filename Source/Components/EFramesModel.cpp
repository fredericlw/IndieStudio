//
// Created by leofa on 18/06/2021.
//

#include "EFramesModel.hpp"
#include <vector>
#include <algorithm>
#include <raylib_encap/ETime.hpp>

void EFramesModel::draw(const Vector3D &pos, Colors color)
{
    timer += ETime::DeltaTime();
    if (timer >= speed) {
        frameCounter++;
        timer = 0;
    }
    if (frameCounter >= nbFrames - 1) {
        frameCounter = 0;
    }
    _frames[frameCounter].draw(pos, color);
}

EFramesModel::EFramesModel(const std::string &folder, const std::string &texture, float scale, float speed)
    : timer(0),
    scale(scale),
    speed(speed),
    frameCounter(0)
{
    auto paths = get_paths_ordered(folder);
    _frames.reserve(paths.size());
    for (const auto &item : paths) {
        std::cout << "got " << item << std::endl;
        _frames.emplace_back(item.c_str(), texture, scale);
    }
}

std::vector<std::string> EFramesModel::get_paths_ordered(
    const std::string &dirPath
)
{
    using namespace std;
    using namespace boost::filesystem;
    path p(dirPath);
    vector<string> res;
    nbFrames = std::count_if(
        directory_iterator(p),
        directory_iterator(),
        static_cast<bool (*)(const path &)>(is_regular_file));
    for (int i = 1; i < nbFrames; ++i) {
        path temp(p);
        temp.append(to_string(i).append(".glb"));
        res.emplace_back(temp.generic_string());
    }
    return res;
}

void EFramesModel::rotate(const Vector3D &vec)
{
    for (auto &model : _frames) {
        model.rotate(vec);
    }
}


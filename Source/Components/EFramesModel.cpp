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
    DrawModel(_frames[frameCounter], pos, scale, GetRaylibColor(color));
}

EFramesModel::EFramesModel(const std::string &folder, float scale, float speed)
    : timer(0),
    scale(scale),
    speed(speed)
{
    for (const auto &item : get_paths_ordered(folder)) {
        std::cout << "got " << item << std::endl;
        _frames.emplace_back(LoadModel(item.c_str()));
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
    int cnt = std::count_if(
        directory_iterator(p),
        directory_iterator(),
        static_cast<bool (*)(const path &)>(is_regular_file));
    for (int i = 0; i < cnt; ++i) {
        path temp(p);
        temp.append(to_string(i).append(".glb"));
        res.emplace_back(temp);
    }
    return res;
}
/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <ECS/Manager.hpp>
#include <Components/3D/BasicCubeComp.hpp>
#include <raylib_encap/Math/Vector2D.hpp>
#include <raylib_encap/Window.hpp>
#include "Components/Components.h"
#include <GUI/ResizableTextComp.hpp>

void Manager::loadAboutPowerUpsScene()
{
    addControlsHowToPlayButton();
    addRightHowToPlayButton();
    addBackToHowToPlayButton();
    addPowerUpsTitle();
    addPowerUpsDescription();
    addFullFireDescription();
    addFireUpDescription();
    addSpeedUpDescription();
    addWallPassDescription();
}

void Manager::addRightHowToPlayButton()
{
    auto size = Vector2D{300, 50};
    auto halfsize = Vector2D{size.x / 2, size.y / 2};
    auto winSize = Window::GetWinSize();
    auto pos = Vector2D{winSize.x - size.x, winSize.y - size.y};
    auto &BackToGameBtnEnt = addEntity("RulesButton");
    BackToGameBtnEnt.addComponent<TransformComp>(pos);
    BackToGameBtnEnt.addComponent<ButtonComp>("How to play", size);
    BackToGameBtnEnt.getComponent<ButtonComp>().AddEventFunc(
        [this]() {
            setNextSceneToLoad(HowToPlay);
            curSceneAlive = false;
        }
    );
    BackToGameBtnEnt.addGroup(GUI);
}


void Manager::addPowerUpsTitle()
{
    auto &HowToPlayName = addEntity("PowerUpsName");
    HowToPlayName.addComponent<TransformComp>(Vector2D::ScreenCenter().x, 0);
    HowToPlayName.addComponent<TextComp>("About the PowerUps", Black);
    HowToPlayName.addGroup(GUI);
}

void Manager::addPowerUpsDescription()
{
    auto &HowToPlayRules = addEntity("PowerUpsDesc");
    HowToPlayRules.addComponent<TransformComp>(Vector2D::ScreenCenter().x, Vector2D::ScreenCenter().y / 8);
    HowToPlayRules.addComponent<ResizableTextComp>("During the game, powerups might randomly apear when you explode a soft block.\n"
                                                   "You can only have one powerup at a time.\n"
                                                   "Here is a description of each powerup avalible:", DarkBlue, 30);
    HowToPlayRules.addGroup(GUI);
}

void Manager::addFullFireDescription()
{
    auto winSize = Window::GetWinSize();
    auto pos = Vector2D{(winSize.x / 8), (winSize.y / 4)};
    auto &FullFireSpriteDesc = addEntity("FullFireSpriteDesc");
    FullFireSpriteDesc.addComponent<TransformComp>(pos.x, pos.y);
    FullFireSpriteDesc.addComponent<Sprite2D>("./Assets/Textures/FullFire.png");
    FullFireSpriteDesc.addGroup(GUI);
    auto &FullFireTitle = addEntity("FullFireTitle");
    FullFireTitle.addComponent<TransformComp>(pos.x + 150, pos.y);
    FullFireTitle.addComponent<ResizableTextComp>("Full Fire", DarkBlue, 30);
    FullFireTitle.addGroup(GUI);
    auto &FullFireDesc = addEntity("FullFireDesc");
    FullFireDesc.addComponent<TransformComp>(pos.x + 250, pos.y + 30);
    FullFireDesc.addComponent<ResizableTextComp>("Set the blast radius to 7 blocks", DarkBlue, 20);
    FullFireDesc.addGroup(GUI);
}

void Manager::addFireUpDescription()
{
    auto winSize = Window::GetWinSize();
    auto pos = Vector2D{(winSize.x / 8), (winSize.y / 4) * 2};
    auto &FireUpSpriteDesc = addEntity("FireUpSpriteDesc");
    FireUpSpriteDesc.addComponent<TransformComp>(pos.x, pos.y);
    FireUpSpriteDesc.addComponent<Sprite2D>("./Assets/Textures/FireUp.png");
    FireUpSpriteDesc.addGroup(GUI);
    auto &FireUpTitle = addEntity("FireUpTitle");
    FireUpTitle.addComponent<TransformComp>(pos.x + 150, pos.y);
    FireUpTitle.addComponent<ResizableTextComp>("Fire Up", DarkBlue, 30);
    FireUpTitle.addGroup(GUI);
    auto &FireUpDesc = addEntity("FireUpDesc");
    FireUpDesc.addComponent<TransformComp>(pos.x + 250, pos.y + 30);
    FireUpDesc.addComponent<ResizableTextComp>("Increases the blast radius by 1", DarkBlue, 20);
    FireUpDesc.addGroup(GUI);
}

void Manager::addSpeedUpDescription()
{
    auto winSize = Window::GetWinSize();
    auto pos = Vector2D{(winSize.x / 8) * 4, (winSize.y / 4) * 2};
    auto &SpeedUpSpriteDesc = addEntity("SpeedUpSpriteDesc");
    SpeedUpSpriteDesc.addComponent<TransformComp>(pos.x, pos.y);
    SpeedUpSpriteDesc.addComponent<Sprite2D>("./Assets/Textures/Skate.png");
    SpeedUpSpriteDesc.addGroup(GUI);
    auto &SpeedUpTitle = addEntity("SpeedUpTitle");
    SpeedUpTitle.addComponent<TransformComp>(pos.x + 150, pos.y);
    SpeedUpTitle.addComponent<ResizableTextComp>("Speed Up", DarkBlue, 30);
    SpeedUpTitle.addGroup(GUI);
    auto &SpeedUpDesc = addEntity("SpeedUpDesc");
    SpeedUpDesc.addComponent<TransformComp>(pos.x + 225, pos.y + 30);
    SpeedUpDesc.addComponent<ResizableTextComp>("Increases the player speed", DarkBlue, 20);
    SpeedUpDesc.addGroup(GUI);
}

void Manager::addWallPassDescription()
{
    auto winSize = Window::GetWinSize();
    auto pos = Vector2D{(winSize.x / 8) * 4, (winSize.y / 4)};
    auto &WallPassSpriteDesc = addEntity("WallPassSpriteDesc");
    WallPassSpriteDesc.addComponent<TransformComp>(pos.x, pos.y);
    WallPassSpriteDesc.addComponent<Sprite2D>("./Assets/Textures/SoftBlockPass.png");
    WallPassSpriteDesc.addGroup(GUI);
    auto &WallPassTitle = addEntity("WallPassTitle");
    WallPassTitle.addComponent<TransformComp>(pos.x + 150, pos.y);
    WallPassTitle.addComponent<ResizableTextComp>("Wall Pass", DarkBlue, 30);
    WallPassTitle.addGroup(GUI);
    auto &WallPassDesc = addEntity("WallPassDesc");
    WallPassDesc.addComponent<TransformComp>(pos.x + 305, pos.y + 30);
    WallPassDesc.addComponent<ResizableTextComp>("Allow the player to walk through soft blocks", DarkBlue, 20);
    WallPassDesc.addGroup(GUI);
}

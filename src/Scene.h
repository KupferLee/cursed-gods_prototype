#pragma once
#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include "ProtectedTexture.h"
#include "ProtectedTileset.h"
#include "ActorLoredrop.h"
#include <memory>


class Scene final : public GameObject
{
private:

    std::shared_ptr <ProtectedTexture> map_;
    std::shared_ptr <ProtectedTileset> tileAtlas_;
    std::shared_ptr <player> player_;
    Music theme_;
    Camera2D cam_;
    bool drawhitbox_;
    bool gameover_;
    std::vector<Vector2> spawnpoints = {{730, 700}, {2725, 3327}};



public:

    Scene() = delete;

    Scene(const std::shared_ptr<player> &player,
          const std::shared_ptr<ProtectedTexture> &map,
          const std::shared_ptr <ProtectedTileset> &tileAtlas,
          const Music &theme,
          const Camera2D &cam);

    Scene(const std::shared_ptr<ProtectedTexture> &map,
          const Music &theme);

    Scene(const Scene &other) = delete;

    Scene &operator = (const Scene &) = delete;

    ~Scene();

    void HandleInput () final;
    void Update(float) final;
    void Update() final;
    void Render() final;

    void HandleInputScene ();
    void UpdateScene ();
    void RenderScene();

    Camera2D getCamera();
    int getGameOver();
};
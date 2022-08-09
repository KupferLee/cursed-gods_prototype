#pragma once
#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include "ProtectedTexture.h"
#include "ProtectedTileset.h"
#include <memory>

class Scene final : public GameObject
{
private:

    std::shared_ptr <player> player_;
    std::shared_ptr <ProtectedTexture> map_;
    std::shared_ptr <ProtectedTileset> tileAtlas_;

    int counter_;
    Vector2 vec_{};
    Rectangle rec_{};
    std::vector <Vector2> vecs_{};
    std::vector <Rectangle> recs_{};

public:

    Scene() = delete;

    Scene(const std::shared_ptr<player> &player,
          const std::shared_ptr<ProtectedTexture> &map,
          const std::shared_ptr <ProtectedTileset> &tileAtlas);

    Scene(const Scene &other) = delete;

    Scene &operator = (const Scene &) = delete;

    ~Scene();

    void HandleInput () final;
    void Update(float, std::vector<Rectangle> &) final;
    void Update() final;
    void Render() final;

    void HandleInputScene ();
    void UpdateScene ();
    void RenderScene();
};
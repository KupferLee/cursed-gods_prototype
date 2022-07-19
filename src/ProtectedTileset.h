#pragma once
#include "raylib.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <cassert>
#include <vector>

class ProtectedTileset  final {
private:
    std::ifstream file_;
    std::vector <int> tileAtlas_;
    std::vector <Rectangle> hitboxes_;
    std::vector <Rectangle> triggerboxes_;
    nlohmann::json description_;

public:
    ProtectedTileset()=delete;
    explicit ProtectedTileset(const char *filename);
    ProtectedTileset(const ProtectedTileset &other) = delete;
    ProtectedTileset &operator = (const ProtectedTileset &) = delete;
    std::vector <int> getTileAtlas();
    std::vector <Rectangle> getHitboxes();
    std::vector <Rectangle> getTriggerboxes();
    ~ProtectedTileset();
};
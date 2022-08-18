#pragma once
#include "raylib.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <cassert>
#include <vector>
#include "config.h"

class ProtectedTileset  final {
private:
    std::ifstream file_{};
    std::vector <Rectangle> hitboxes_{};
    std::vector <Rectangle> hitboxesGround_{};
    std::vector <Rectangle> triggerboxesStalagtit_{};
    std::vector <Rectangle> triggerboxesStalagmit_{};
    std::vector <Rectangle> triggerboxesBreakable_{};
    nlohmann::json description_{};
    int binZscheKonstante_{388};

    int columns_{};
    int tilesX_{};
    int tilesY_{};

public:
    ProtectedTileset()=delete;
    explicit ProtectedTileset(const char *filename);
    ProtectedTileset(const ProtectedTileset &other) = delete;
    ProtectedTileset &operator = (const ProtectedTileset &) = delete;
    int getColumns();
    int getTilesX();
    int getTilesY();
    std::vector <Rectangle> getHitboxes();
    std::vector <Rectangle> getHitboxesGround();
    std::vector <Rectangle> getTriggerboxesStalagtit();
    std::vector <Rectangle> getTriggerboxesStalagmit();
    std::vector <Rectangle> getTriggerboxesBreakable();
    ~ProtectedTileset();
};
/*
*   Created by Schr4mMb00 on 19.07.2022.
*
*   Title: ProtectedTileset
*   Required: const char* filename --> for Initialization
*   Return: you can get readingaccess to:  -> tile IDs [getTileAtlas()] returns a vector of ints
*                                          -> hitboxes [getHitboxes()] returns a vector auf rectangles
*                                          -> triggerboxes [getTriggerboxes()] returns a vector of rectangles
*   Function: assertion handling of json file and provide save data for game
*/


#include "ProtectedTileset.h"

//explicit constructor to stream json data and getting the vectors for the mapdescription
//default- and copy-constructor are deleted
ProtectedTileset::ProtectedTileset(const char *filename)
{
    this->file_.open(filename);

    if(!this->file_.is_open())
    {
        TraceLog(LOG_INFO, "JSON-ERROR: File is not available");
    }

    assert(this->file_.is_open());

    this->file_ >> this->description_;
    this->file_.close();

    columns_ = 17;
    tilesX_ = description_["width"];
    tilesY_ = description_["height"];

    //push the json data into vectors --> maybe adjustment to the actual layers
    for (auto const &layer: this->description_["layers"])
    {
        if (layer["type"] == "tilelayer" && layer["visible"])
        {
            for (auto const &tileId: layer["data"])
            {
                this->tileAtlas_.push_back(static_cast<int>(tileId.get<int>()));
            }
        }
       if (layer["type"] == "objectgroup" && layer["name"] == "Triggerbox_Treppe")
        {
            for (auto const &object: layer["objects"])
            {
                this->triggerboxes_.push_back({static_cast<float>(object["x"].get<int>()),
                                               static_cast<float>(object["y"].get<int>()),
                                               static_cast<float>(object["width"].get<int>()),
                                               static_cast<float>(object["height"].get<int>())});
            }
        }
        if (layer["type"] == "objectgroup" && layer["name"] == "Hitbox_Wand")
        {
            for (auto const &object: layer["objects"])
            {
                this->hitboxes_.push_back({static_cast<float>(object["x"].get<int>()),
                                           static_cast<float>(object["y"].get<int>()),
                                           static_cast<float>(object["width"].get<int>()),
                                           static_cast<float>(object["height"].get<int>())});
            }
        }
        if (layer["type"] == "objectgroup" && layer["name"] == "Hitbox_Gelaender")
        {
            for (auto const &object: layer["objects"])
            {
                this->hitboxes_.push_back({static_cast<float>(object["x"].get<int>()),
                                           static_cast<float>(object["y"].get<int>()),
                                           static_cast<float>(object["width"].get<int>()),
                                           static_cast<float>(object["height"].get<int>())});
            }
        }
        if (layer["type"] == "objectgroup" && layer["name"] == "Triggerbox_Tueren")
        {
            for (auto const &object: layer["objects"])
            {
                this->triggerboxes_.push_back({static_cast<float>(object["x"].get<int>()),
                                               static_cast<float>(object["y"].get<int>()),
                                               static_cast<float>(object["width"].get<int>()),
                                               static_cast<float>(object["height"].get<int>())});
            }
        }
        else
        {
            TraceLog(LOG_INFO, "No Triggerboxes"); //example for layer debugging
        }
    }
    TraceLog(LOG_INFO, "ProtectedTiles constructor called");
}

std::vector<int> ProtectedTileset::getTileAtlas()
{
    return this->tileAtlas_;
}

std::vector<Rectangle> ProtectedTileset::getHitboxes()
{
    return this->hitboxes_;
}

std::vector<Rectangle> ProtectedTileset::getTriggerboxes()
{
    return this->triggerboxes_;
}

ProtectedTileset::~ProtectedTileset()
{
    TraceLog(LOG_INFO, "ProtectedTiles destructor called");
}

int ProtectedTileset::getColumns() {
    return this->columns_;
}

int ProtectedTileset::getTilesX() {
    return this->tilesX_;
}

int ProtectedTileset::getTilesY() {
    return this->tilesY_;
}
